#include <iostream>
#include "TCPconnection.hpp" //przy rozszeeniu .cpp jakims cudem dziala - teraz nie widzi definicji funkcji z tcp.cpp
#include "vechicle.hpp"
#include "kalman.hpp"

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
    Vechicle* vechicle = new Vechicle();
    // Kalman* kalman = new Kalman();

    try{
        std::string rcvData = "";
        tcp->createConnection();
        
        while(rcvData != "close") {
            rcvData = tcp->receiveData(SPEAKER);
            std::cout<<rcvData<<"\n";

        }
    }
    catch (Exception& e){
        std::cerr<<"Exception!!!"<<"\n"<<e.what()<<"\n";  
    }



    delete tcp;    
    delete vechicle;
    // delete kalman;

    std::cerr<<"Thanks for a ride!!!"<<std::endl;
    return 0;
}