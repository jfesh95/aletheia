#ifndef BIBLEMANAGER_H
#define BIBLEMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include "sqlite3.h"

class BibleManager
{
public:
    BibleManager();
    ~BibleManager();
    std::vector<std::string> getBookNames();
    std::vector<std::string> getNumberOfChapters(const std::string &);
    std::string getVerse(const std::string &, const std::string &, const std::string &);
    std::string getChapter(const std::string &, const std::string &);

private:
    std::string lookupVerse(const std::string &, const std::string &, const std::string &);
    sqlite3 *bibleIndex;
};

#endif // BIBLEMANAGER_H
