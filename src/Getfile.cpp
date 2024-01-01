#include "../includes/getFile.hpp"

void Getfile::getConfigFile(std::string fileName){
    //opening the file
    std::ifstream configfile;
    configfile.open(fileName);
    if (!configfile.is_open()){
        throw std::invalid_argument("can't open file");
    }
    // std::cout << "File opened" << std::endl;

    //after opening the file let's get all the content from it
    std::string line;
    for (; std::getline(configfile, line);){

    }
}