// https://www.geeksforgeeks.org/socket-programming-cc/

#include "TCPconnection.hpp"
#include <cstring>

TCPClient::TCPClient(std::string ip, uint port): ipAdress(ip), portNum(port) {
    hint.sin_family = AF_INET;
    hint.sin_port = htons(portNum);
    inet_pton(AF_INET, ipAdress.c_str(), &hint.sin_addr);
}

void TCPClient::createConnection() {
    std::cout<<"Creating server socket..."<<"\n";
    clientSock = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSock == -1) {
        throw TCPException("Can't create a socket!");   
    }

    int connectRes = connect(clientSock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1) {
         throw TCPException("Can't connect to server");
    }
    std::cout<<"Connected to server!"<<"\n";
}

void TCPClient::getClientAddres() {
    std::cout<<"Client address: "<<inet_ntoa(hint.sin_addr)<<" and port: "<<hint.sin_port<<std::endl;
}


auto TCPClient::receiveData() {
    std::string reply(15, ' ');
    std::string responce = "ACK";
    auto rcvData = recv(clientSock, &reply.front(), reply.size(), 0);
    if (rcvData == -1) {
        throw TCPException("Error while receiving bytes");
    }
    else {
        send(clientSock, responce.data(), responce.length(), 0);
    }

    return rcvData;
}
void TCPClient::sendData(std::string& data) {
    send(clientSock, data.data(), data.length(), 0);
}

int TCPClient::isConnectionAlive(int socket) {
    int error_code;
    socklen_t error_code_size = sizeof(error_code);
    return getsockopt(socket, SOL_SOCKET, SO_ERROR, &error_code, &error_code_size);
} 

void TCPClient::closeConnection() {
    if(isConnectionAlive(clientSock) != -1) {
        close(clientSock);
        std::cerr<<"Connection with server closed"<<"\n";
    }
}

TCPClient::~TCPClient(){
    closeConnection();
}

