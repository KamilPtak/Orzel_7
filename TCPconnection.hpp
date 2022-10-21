#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> 

#include <string> 
#include <iostream>

#include "userTypeDefs.hpp"
#include "myExceptions.hpp"

#pragma once

class TCP {
    private:
        PORT port;

        int serverfd, newSocket;
        struct sockaddr_in address;
        int addrlen = sizeof(address);
        int opt = 1;

        // char buffer[1024] = {0};

        void setAddress();
        void createSocket();
        void setSockOpt();
        void bindSocket();
        void listenForClients();
        void acceptClient();
    
    public:
        TCP(PORT port);

        void createConnection();
        void closeConnection();
        void sendData(std::string& data);
        auto receiveData();

};