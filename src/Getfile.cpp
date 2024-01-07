#include "../includes/getFile.hpp"

void Getfile::removeSpaces(std::string& line){
    line.erase(remove_if(line.begin(), line.end(), isspace),\
        line.end());
}

void Getfile::BracketsCheck(std::ifstream& file){
    // if(line.empty())
    //     return ;
    std::stack<char> stack;
    char c;
    
    while(file.get(c)){
        if (c == '{')
            stack.push(c);
        else if (c == '}'){
            if (stack.empty())
                throw std::invalid_argument("Brackets");
            else
                stack.pop();
        }
    }
    if (!stack.empty())
        throw std::invalid_argument("Brackets");
}

void Getfile::getConfigFile(std::string fileName){
    //opening the file
    std::ifstream configfile;
    configfile.open(fileName);
    if (!configfile.is_open())
        throw std::invalid_argument("can't open file");
    //check the brackets
    Getfile::BracketsCheck(configfile);
    ////////////////////////////////////////////////////////////
    //after opening the file let's get all the content from it//
    std::string line;
    for (; std::getline(configfile, line);){
        Getfile::removeSpaces(line);//-->remove spaces from the config file
        std::cout << line << std::endl;
    }
}