// https://www.geeksforgeeks.org/socket-programming-cc/

#include "TCPconnection.hpp"


TCP::TCP(PORT port_): port(port_), newSocket(1) {}

void TCP::setAddress() {
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    std::cerr<<"Server adress configuration done"<<"\n";
}

void TCP::createSocket() {
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1){
        throw TCPException("Error while creating TCP socket");
    }
    std::cerr<<"New socket created"<<"\n";
}

void TCP::setSockOpt() {
    if(setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        throw TCPException("Jak tu sie sypie to usunac tego ifa");
    }
    std::cerr<<"Socket options set"<<"\n";
}

void TCP::bindSocket() {
    if(bind(serverfd, (sockaddr*) &address, sizeof(address)) == -1) {
        throw TCPException("Error while binding socket");
    }
    std::cerr<<"Socket binded"<<"\n";
}

void TCP::listenForClients() {
    if(listen(serverfd, 3) == -1) {
        throw TCPException("Error while listening for client");
    }
    std::cerr<<"Listening for "<<"\n";
}

void TCP::acceptClient() {
    while(newSocket == 1) {
        newSocket = accept(serverfd, (struct sockaddr*)& address,(socklen_t*)& addrlen);
        if(newSocket < 0) {
            throw TCPException("Error while accepting");
        }
    }
    std::cerr<<"Client connected"<<"\n";
}

auto TCP::receiveData() {
    std::string reply(15, ' ');
    auto rcvData = recv(newSocket, &reply.front(), reply.size(), 0);
    if (rcvData == -1) {
        throw TCPException("Error while receiving bytes");
    }
    return rcvData;
}

void TCP::sendData(std::string &data) {
    send(newSocket, data.data(), data.length(), 0);
}

void TCP::createConnection() {
    setAddress();
    createSocket();
    setSockOpt();
    bindSocket();
    listenForClients();
    acceptClient();
}

void TCP::closeConnection(){
    close(newSocket);
    close(serverfd);
}
