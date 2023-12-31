#include "websev.hpp"

int main(){
    char buffer[BUFFER_SIZE];
    char resp[] = "HTTP/1.1 200 OK\r\n"
                  "Server: webserver-c\r\n"
                  "Content-type: text/html\r\n\r\n"
                  "<html><center>walid hmar</center></html>\r\n";
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        std::cerr << "webserv (socket)" << std::endl;
        return (1);
    }
    std::cout << "Socket created Successfully" << std::endl;



    struct sockaddr_in host_addr;
    int host_addrLen = sizeof(host_addr);
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if(bind(sockfd, (struct sockaddr *)&host_addr, host_addrLen) != 0){
        std::cerr << "webserv (Bind)" << std::endl;
        return 1;
    }
    std::cout << "Socket successfully bound to address" << std::endl;

    if (listen(sockfd, SOMAXCONN) != 0){
        std::cerr << "webserv (listen)" << std::endl;
        return 1;
    }
    std::cout << "Server listening for connections" << std::endl;
    for (;;) {
        int newsockfd = accept(sockfd, (struct sockaddr *)&host_addr,
                               (socklen_t *)&host_addrLen);
        if (newsockfd < 0) {
            std::cerr << "webserver (accept)" << std::endl;
            continue;
        }
        std::cout << "connection accepted\n";
        int valread = read(newsockfd, buffer, BUFFER_SIZE);
        if (valread < 0) {
            std::cerr << "webserver (read)" << std::endl;
            continue;
        }
        std::cout << "--" << buffer << std::endl;
        int valwrite = write(newsockfd, resp, strlen(resp));
        if (valwrite < 0) {
            std::cerr << "webserver (write)" << std::endl;
            continue;
        }
        close(newsockfd);
    }

}