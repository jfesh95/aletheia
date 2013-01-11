#include "worksmanager.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

std::string WorksManager::getCrossReference(const std::string &book, const std::string &chapter, const std::string &verse)
{
    std::string line, retValue = "";
    std::string filename = "works/crossreferences/"+book;
    std::ifstream file(filename.c_str(), std::ios::in | std::ios::binary);
    if (file.is_open())
    {
        while ( file.good() )
        {
            getline (file, line);
            if (line.find(chapter+':'+verse) != std::string::npos)
            {
                std::vector<std::string> parts = split(line, '\t');
                std::vector<std::string> ref = split(parts[0], ':');
                if (ref[0] == chapter && ref[1] == verse)
                {
                    std::vector<std::string> crossRef = split(parts[1], ':');
                    retValue += crossRef[0] + ' ' + crossRef[1] + ':' + crossRef[2] + '\t';
                }
            }
        }
        file.close();
    }

    else std::cerr << "There was an error loading the cross references!\n";
    return retValue;
}
