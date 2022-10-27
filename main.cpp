#include <iostream>
#include "TCPconnection.hpp" //przy rozszeeniu .cpp jakims cudem dziala - teraz nie widzi definicji funkcji z tcp.cpp

uint port;


int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr<< "Program launched on port 80000. To specify port run 'program <port>'\n";
        port  = 80000;
    }
    else {
        port  = atoi(argv[1]);
        std::cerr<<"The program launched on port "<< port<<"\n";
    }


    TCPServer* tcp = new TCPServer(port);
    try{
        std::string rcvData = "";
        tcp->createConnection();
        std::cout<<"dupa";
        while(rcvData != "close") {
            auto rcvData = tcp->receiveData(1);
            std::cout<<rcvData<<"\n";
        }
    }
    catch (TCPException& e){
        std::cerr<<e.what()<<"\n";  
    }



    tcp->closeConnection();
    delete tcp;    
    

    std::cout<<"dupa"<<std::endl;
    return 0;
}