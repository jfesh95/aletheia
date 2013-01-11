#ifndef WORKSMANAGER_H
#define WORKSMANAGER_H

#include <string>

class WorksManager
{
public:
    static std::string getCrossReference(const std::string & book, const std::string & chapter, const std::string & verse);
};

#endif // WORKSMANAGER_H
