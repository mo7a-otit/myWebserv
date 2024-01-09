#ifndef SERVER_HPP
#define SERVER_HPP


class Server{
    public:
        int listen;
        std::string host;
        std::string server_name;
        std::string root;
        std::string index;
        std::vector<Server> servr;
    public:
        // Server();
        void get_file(std::string);
        void fill_server(std::string line);


        

};



#endif