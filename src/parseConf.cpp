#include "../includes/webserv.hpp"

void Getfile::saveDirectives(std::string line){
    // std::cout << line << std::endl;
    if (line.find('\n') != std::string::npos)
        throw std::invalid_argument("invalid directives");
    if (line.find(':') == std::string::npos)
        throw std::invalid_argument("invalid form");

    int posColone = line.find(':');
    std::string key;
    std::string value;
    key = line.substr(0, posColone);
    value = line.substr(posColone + 1);
    // std::cout << key << std::endl;
    // std::cout << value << std::endl;
    this->arr[key] = value;
    // std::map<std::string, std::string>::iterator it;
    // std::cout << "it->first = " << it->first << std::endl;
    // std::cout << "it->second = " << it->second << std::endl;
}

void Getfile::parseFile(std::string file){
    int serverPos = file.find("server{");
    int start = 0;
    while (start < serverPos){
        if(file[start] != '\n')
            throw std::invalid_argument("invalid content");
        start++;
    }
    size_t i = serverPos + 7;
    size_t posVergul;
    std::string line;
        while (file[i] && file[i] == '\n')
            i++;
    while(i < file.length()){
        // std::cout << "-----" << std::endl;
        posVergul = file.find(";\n");
        if (posVergul != std::string::npos){
            line = file.substr(i, (posVergul - i));
            Getfile::saveDirectives(line);
            int j = posVergul + 1;
            while (file[++j] == '\n');
                // j++;
            i = j ;
            file.erase(0, j);
            i = 0;
            // break;
        }
        else
            break;
    }
       std::map<std::string, std::string>::iterator it;
       std::map<std::string, std::string>::iterator ite = arr.end();
       for (it = arr.begin(); it!=ite; it++){
            std::cout << "it->first = " << it->first << std::endl;
            std::cout << "it->second = " << it->second << std::endl;
       }
}