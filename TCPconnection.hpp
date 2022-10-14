#include <sys/socket.h>
#include <arpa/inet.h>
#include <string> 
#pragma once

class TCP {
    private:
        int sockfd, serverfd, newSocket, valread;
        sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);

        char buffer[1024] = {0};
        char* hello = "Hello from server";
    
    public:
        TCP(): sockfd(-1) {}

        void createSocket();
        void setAddress();
        std::string sendData(std::string &data);
        void receiveData();

};