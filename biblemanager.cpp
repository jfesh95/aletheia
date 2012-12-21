#include "biblemanager.h"

static int bookNamesQueryCallback(void *bookList, int argc, char **argv, char **colName)
{
    std::vector<std::string> *bList;
    bList = (std::vector<std::string>*)bookList;

    for (int i = 0; i < argc; i++)
        bList->push_back(argv[i]);

    return 0;
}

static int chapterQueryCallback(void *verseText, int argc, char **argv, char **colName)
{
    std::string *vText;
    vText = (std::string*)verseText;

    for (int i = 0; i < argc; i+=2)
        *vText = *vText + argv[i] + " " + argv[i+1] + "\n";

    return 0;
}

BibleManager::BibleManager()
{
    if (sqlite3_open("bibles/kjv.bible", &bibleIndex))
    {
        std::cerr << "Can't open Bible index: " << sqlite3_errmsg(bibleIndex) << std::endl;
        sqlite3_close(bibleIndex);
    }
}

BibleManager::~BibleManager()
{
    sqlite3_close(bibleIndex);
}

std::vector<std::string> BibleManager::getBookNames()
{
    int ret;
    char *errMsg = 0;
    std::vector<std::string> bookList(0);
    bookList.reserve(66);
    std::string query = "SELECT BookName FROM Bible WHERE Chapter = 1 AND Verse = 1";

    ret = sqlite3_exec(bibleIndex, query.c_str(), bookNamesQueryCallback, &bookList, &errMsg);

    if (ret != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    return bookList;
}

std::string BibleManager::lookupVerse(const std::string & book, const std::string & chapter = "", const std::string & verse = "")
{
    int ret;
    char *errMsg = 0;
    std::string verseText = "";
    std::string query = "SELECT Verse, VText FROM Bible WHERE BookName = '" + book;
    if (chapter != "")
        query += "' AND Chapter = " + chapter;
    if (verse != "")
        query += " AND Verse = " + verse;

    ret = sqlite3_exec(bibleIndex, query.c_str(), chapterQueryCallback, &verseText, &errMsg);

    if (ret != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    return verseText;
}

std::string BibleManager::getVerse(const std::string & book, const std::string & chapter, const std::string & verse)
{
    return lookupVerse(book, chapter, verse);
}

std::string BibleManager::getChapter(const std::string & book, const std::string & chapter)
{
    return lookupVerse(book, chapter);
}
