#include "biblemanager.h"

BibleManager::BibleManager()
{
    bibleIndex = new Sqlite3Db();

    if (!bibleIndex->Open("bibles/kjv.bible"))
    {
        std::cerr << "Can't open Bible index: " << bibleIndex->Error() << std::endl;
        bibleIndex->Close();
    }
}

BibleManager::~BibleManager()
{
    bibleIndex->Close();
}

std::string BibleManager::getVerse(const std::string & book, int chapter, int verse)
{
    bool ret;
    std::string query = "SELECT VText FROM Bible WHERE BookName = '" + book;
    query += "' AND Chapter = ";
    query += chapter + " AND Verse = " + verse;

    ret = bibleIndex->Exec(query);

    if (!ret)
    {
        std::cerr << "SQL error: " << bibleIndex->Error() << std::endl;
    }

    return book + (char)(chapter+(int)'0') + (char)(verse+(int)'0');
}

std::string BibleManager::getChapter(const std::string & book, int chapter)
{
    return book + (char)(chapter+(int)'0');
}
