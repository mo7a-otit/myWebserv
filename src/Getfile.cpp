#include "../includes/webserv.hpp"

void Getfile::removeSpaces(std::string& line){
    line.erase(remove_if(line.begin(), line.end(), isspace),\
        line.end());
}

void Getfile::BracketsCheck(std::ifstream& file){
    int i = 0;
    char c;
    std::stack<char> stack;
    
    while(file.get(c)){
        if (c == '{'){
            stack.push(c);
            i++;
        }
        else if (c == '}'){
            if (stack.empty())
                throw std::invalid_argument("Brackets");
            else
                stack.pop();
        }
    }
    if (i == 0)
        throw std::invalid_argument("There is no brackets!!");
    if (!stack.empty())
        throw std::invalid_argument("Brackets");
}

void Getfile::getConfigFile(std::string fileName){
    //******first step*******
    std::ifstream configfile;
    configfile.open(fileName);
    if (!configfile.is_open())
        throw std::invalid_argument("can't open file");
    Getfile::BracketsCheck(configfile);
    configfile.close();
    //************************

    //******second step********
    //saving the file in the string allFile;
    configfile.open(fileName);
    if (!configfile.is_open())
        throw std::invalid_argument("can't open file");
    std::string line;
    for (; std::getline(configfile, line);){
        Getfile::removeSpaces(line);//-->remove spaces from the config file
        allFile += line + "\n";
    }
    // std::cout << allFile << std::endl;
    Getfile::parseFile(allFile);
    configfile.close();
}