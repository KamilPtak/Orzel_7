// https://www.geeksforgeeks.org/socket-programming-cc/

#include "TCPconnection.hpp"
#include "myExceptions.hpp"

void TCP::createSocket() {
    sockfd = socket(AF_INET , SOCK_STREAM , 0);

    if (sockfd < 0){
        throw TCPException("Error while creating TCP socket");
    }

    if(setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        throw TCPException("Jak tu sie sypie to usunac tego ifa");
    }
}

void TCP::setAddress() {
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8000);
}

