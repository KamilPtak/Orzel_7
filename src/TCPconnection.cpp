// https://www.geeksforgeeks.org/socket-programming-cc/

#include "TCPconnection.hpp"


TCPServer::TCPServer(uint port_): port(port_), opt(1), numOfClients(0) {
    hint.sin_family = AF_INET;
    hint.sin_addr.s_addr = INADDR_ANY;
    hint.sin_port = htons(port);
    std::cerr<<"Server adress configuration done"<<"\n";
}

void TCPServer::createSocket() {
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1){
        throw Exception("TCP", "Error while creating TCP socket");
    }
    std::cerr<<"New socket created..."<<"\n";
}

void TCPServer::setSockOpt() {
    if(setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        throw Exception("TCP", "Jak tu sie sypie to usunac tego ifa");
    }
    std::cerr<<"Socket options set..."<<"\n";
}

void TCPServer::bindSocket() {
    if(bind(serverfd, (sockaddr*) &hint, sizeof(hint)) == -1) {
        throw Exception("TCP", "Error while binding socket");
    }
    std::cerr<<"Socket binded..."<<"\n";
}

void TCPServer::listenForClients() {
    if(listen(serverfd, 3) == -1) {
        throw Exception("TCP", "Error while listening for client");
    }
    std::cerr<<"Listening for client..."<<"\n";
}

void TCPServer::acceptClient() {
    int newSocket = accept(serverfd, (struct sockaddr*)& hint, &addrlen);
    if(newSocket == -1) {
        throw Exception("TCP", "Error while accepting");
    }
    clientsList.push_back(newSocket);
    numOfClients++;
    std::cerr<<"Client connected!"<<"\n";
}

std::string TCPServer::receiveData(int client) {
    std::string reply(1024, ' ');
    int rcvData = recv(clientsList[client], &reply.front(), reply.size(), 0);
    if (rcvData == -1) {
        throw Exception("TCP", "Error while receiving bytes");
    }
    reply.erase(std::remove_if(reply.begin(), reply.end(), ::isspace),reply.end());
    return reply;
}

void TCPServer::sendData(int client, std::string &data) {
    send(clientsList[client], data.data(), data.length(), 0);
}

void TCPServer::createConnection() {
    createSocket();
    setSockOpt();
    bindSocket();
    listenForClients();
    acceptClient();
}

int TCPServer::isConnectionAlive(int socket) {
    int error_code;
    socklen_t error_code_size = sizeof(error_code);
    return getsockopt(socket, SOL_SOCKET, SO_ERROR, &error_code, &error_code_size);
} 

void TCPServer::closeConnection(){
    for(auto elem: clientsList) {
        if(isConnectionAlive(elem) != -1) {
            close(elem);
            std::cerr<<"Connenction closed for client number "<<elem<<"\n";
        }
    }
    close(serverfd);
}

TCPServer::~TCPServer() {
    closeConnection();
}