#include <iostream>
#include "TCPconnection.hpp" //przy rozszeeniu .cpp jakims cudem dziala - teraz nie widzi definicji funkcji z tcp.cpp

#define SPEAKER 0
#define LISTENER 1

uint port = 80016;


int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr<< "Program launched on port "<<port<<". To specify port run 'program <port>'\n";
    }
    else {
        port  = atoi(argv[1]);
        std::cerr<<"The program launched on port "<< port<<"\n";
    }


    TCPServer* tcp = new TCPServer(port);
    try{
        std::string rcvData = "";
        tcp->createConnection();
        while(rcvData != "close") {
            rcvData = tcp->receiveData(SPEAKER);
            std::cout<<rcvData<<"\n";
        }
    }
    catch (TCPException& e){
        std::cerr<<"Exception!!!"<<"\n"<<e.what()<<"\n";  
    }



    tcp->closeConnection();
    delete tcp;    
    
    return 0;
}