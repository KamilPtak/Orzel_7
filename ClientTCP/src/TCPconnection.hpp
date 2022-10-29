#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> 

#include <string> 
#include <iostream>
#include "myExceptions.hpp"

#pragma once

class TCPClient {
    private:
        std::string ipAdress;
        uint portNum;
        
        int clientSock;
        sockaddr_in hint;
        socklen_t addrlen;
    public:
        TCPClient(std::string ip, uint port);

        void createConnection();
        void getClientAddres();
        void sendData(std::string& data);
        auto receiveData();
        int isConnectionAlive(int socket);

        void closeConnection();
        ~TCPClient();
};