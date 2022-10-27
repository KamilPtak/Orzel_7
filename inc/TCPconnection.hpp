#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> 

#include <string> 
#include <iostream>
#include <vector>

#include "userTypeDefs.hpp"
#include "myExceptions.hpp"

#pragma once

class TCPServer {
    private:
        uint port;
        int opt;
        int serverfd;
        sockaddr_in hint;
        socklen_t addrlen = sizeof(hint);
        
        std::vector<int> clientsList;
        int numOfClients;

        void createSocket();
        void setSockOpt();
        void bindSocket();
        void listenForClients();
        void acceptClient();
        
    
    public:
        TCPServer(uint port);

        void createConnection();
        void closeConnection();
        void sendData(int client,std::string& data);
        auto receiveData(int client);

        int getNumOfClients() {return numOfClients;}

        ~TCPServer();
};