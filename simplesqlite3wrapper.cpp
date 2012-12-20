#include "sqlite3.h"
#include "simplesqlite3wrapper.h"

static int queryCallback(void *extraArg, int argc, char **argv, char **colName)
{
    int i;

    for (i = 0; i < argc; i++)
        //std::cout << colName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;

    return 0;
}

Sqlite3Db::Sqlite3Db()
{
}

Sqlite3Db::~Sqlite3Db()
{
}

bool Sqlite3Db::Open(const std::string & filename)
{
    if (db)
        sqlite3_close(db);

    if (sqlite3_open(filename.c_str(), &db))
    {
        error = sqlite3_errmsg(db);
        return false;
    }

    return true;
}

std::string Sqlite3Db::Error()
{
    return error;
}

bool Sqlite3Db::Exec(const std::string & query)
{
    if (!db)
    {
        error = "database on open";
        return false;
    }

    int ret;
    char *errMsg = 0;

    ret = sqlite3_exec(db, query.c_str(), queryCallback, 0, &errMsg);

    if (ret != SQLITE_OK)
    {
        error = errMsg;
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}

void Sqlite3Db::Close()
{
    if (db)
        sqlite3_close(db);
}
