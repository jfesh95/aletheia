#ifndef BIBLEMANAGER_H
#define BIBLEMANAGER_H

#include <string>
#include <iostream>
#include "simplesqlite3wrapper.h"

class BibleManager
{
public:
    BibleManager();
    ~BibleManager();
    std::string getVerse(const std::string & book, int chapter, int verse);
    std::string getChapter(const std::string &, int);

private:
    Sqlite3Db *bibleIndex;
};

#endif // BIBLEMANAGER_H
