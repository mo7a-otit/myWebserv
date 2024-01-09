#include "../includes/webserv.hpp"

/*****check brackets******/
void BracketsCheck(std::string configfile){
    std::ifstream ss;
    ss.open(configfile);
     if (!ss.is_open())
        throw std::invalid_argument("can't open file");
    
    int i = 0;
    char c;
    std::stack<char> stack;
    
    while(ss.get(c)){
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
    ss.close();
}

void Server::fill_server(std::string line){
    size_t posVergul = line.find(';');
    if (posVergul == std::string::npos)
        throw std::invalid_argument("can't find ';'");
}

void Server::get_file(std::string file){
    BracketsCheck(file);
    std::ifstream ss;
    ss.open(file);
     if (!ss.is_open())
        throw std::invalid_argument("can't open file");
    std::string line;
    int i = 0;
    while (std::getline(ss, line)){
        if(line == "server{"){
            std::cout << "first cond" << std::endl;
            Server server;
            Server::fill_server();
        }
        // std::cout << line << std::endl;
    }
    
}



