#include <iostream>

#include "TCPconnection.hpp" //przy rozszeeniu .cpp jakims cudem dziala - teraz nie widzi definicji funkcji z tcp.cpp
#include "userTypeDefs.hpp"

PORT port;



int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr<< "Program launched on port 80000. To specify port run 'program <port>'\n";
        port  = 80000;
    }
    else {
        port  = atoi(argv[1]);
        std::cerr<<"The program launched on port "<< port<<"\n";
    }


    TCP* tcp = new TCP(port);
    try{
        tcp->createConnection();
    }
    catch (TCPException& e){
        std::cerr<<e.what()<<"\n";
        tcp ->closeConnection();
        delete tcp;    
    }



    tcp->closeConnection();
    delete tcp;    
    

    std::cout<<"dupa"<<std::endl;
    return 0;
}