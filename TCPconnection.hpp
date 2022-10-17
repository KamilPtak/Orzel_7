#include <sys/socket.h>
#include <arpa/inet.h>
#include <string> 
#pragma once

class TCP {
    private:
        int serverfd, newSocket, valread;
        sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);

        char buffer[1024] = {0};

        void setAddres();
        void createSocket();
        void setSockOpt();
        void bindSocket();
        void setAddress();
    
    public:
        TCP();

        void createConnection();

        std::string sendData(std::string &data);
        void receiveData();

};