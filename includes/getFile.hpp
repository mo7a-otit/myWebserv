#ifndef GETFILE_HPP
#define GETFILE_HPP

#include <map>
#include <vector>
class Getfile{
    private:
        // std::stack<std::string> brackets;
        std::string allFile;
        std::map<std::string, std::string> arr;
    public:
        void getConfigFile(std::string fileName);
        void removeSpaces(std::string&);
        void BracketsCheck(std::ifstream&);
        void parseFile(std::string);
        void saveDirectives(std::string);
};


#endif