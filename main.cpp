#include <iostream>
#include "TCPconnection.hpp" //przy rozszeeniu .cpp jakims cudem dziala - teraz nie widzi definicji funkcji z tcp.cpp
#include "userTypeDefs.hpp"

PORT port;


int main(int argc, char *argv[]) {



    if (argc != 2) {
        //Nie sprecyzowany port - rzucenie wyjtku do otwarcia 
        //komunikacji na standardowym porcie
        std::cerr<< "Run program at port 80000. To specify port run 'program <port>'\n";
        port = 80000;
    }

    // TCP* tcp = new TCP(port);
    TCP tcp(port);
    tcp.createConnection();
    tcp.closeConnection();
    // delete tcp;

    std::cout<<"dupa"<<std::endl;
    return 0;
}