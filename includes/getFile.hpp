#ifndef GETFILE_HPP
#define GETFILE_HPP

#include "webserv.hpp"

class Getfile{
    private:
        std::string file;
    public:
        void getConfigFile(std::string fileName);
};


#endif