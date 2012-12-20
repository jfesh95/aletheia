#ifndef SIMPLESQLITE3WRAPPER_H
#define SIMPLESQLITE3WRAPPER_H

#include <string>

class sqlite3;

class SqlQueryResult
{
public:
    SqlQueryResult();
    ~SqlQueryResult();
};

class Sqlite3Db
{
public:
    Sqlite3Db();
    ~Sqlite3Db();
    bool Open(const std::string &);
    std::string Error();
    bool Exec(const std::string &);
    void Close();

private:
    sqlite3 *db;
    std::string error;
};

#endif // SIMPLESQLITE3WRAPPER_H
