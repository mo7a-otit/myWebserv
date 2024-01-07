#ifndef GETFILE_HPP
#define GETFILE_HPP

#include "webserv.hpp"

class Getfile{
    private:
        // std::stack<std::string> brackets;
        std::map<std::string, std::string> arr;
    public:
        void getConfigFile(std::string fileName);
        void removeSpaces(std::string&);
        void BracketsCheck(std::ifstream&);
};


#endif