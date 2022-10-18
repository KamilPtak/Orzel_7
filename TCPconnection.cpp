// https://www.geeksforgeeks.org/socket-programming-cc/

#include "TCPconnection.hpp"

TCP::TCP(PORT port_): port(port_) {}

void TCP::setAddress() {
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
}

void TCP::createSocket() {
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0){
        throw TCPException("Error while creating TCP socket");
    }
}

void TCP::setSockOpt() {
    if(setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        throw TCPException("Jak tu sie sypie to usunac tego ifa");
    }
}

void TCP::bindSocket() {
    if(bind(serverfd, (sockaddr*) &address, sizeof(address)) < 0) {
        throw TCPException("Error while binding socket");
    }
}

void TCP::listenForClients() {
    if(listen(serverfd, 3) < 0) {
        throw TCPException("Error while listening for client");
    }
}

void TCP::acceptClient() {
    newSocket = accept(serverfd, (struct sockaddr*)& address,(socklen_t*)& addrlen);
    if(newSocket < 0) {
        throw TCPException("Error while accepting");
    }
}

std::string TCP::receiveData() {
    std::string reply(15, ' ');
    auto bytes_recv = recv(newSocket, &reply.front(), reply.size(), 0);
    if (bytes_recv == -1) {
        throw TCPException("Error while receiving bytes");
    }
}

void TCP::sendData(std::string &data) {
    send(newSocket, data.data(), data.length(), 0);
}

void TCP::createConnection() {
    setAddress();
    createSocket();
    setSockOpt();
    bindSocket();
}

void TCP::closeConnection(){
    close(newSocket);
    close(serverfd);
}
