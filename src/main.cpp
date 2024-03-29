// RT Patch - lepsze sterowanie jadrem linuksa

#include <iostream>
#include <thread>
#include <utility>
#include <queue>
#include <unistd.h>

#include "TCPconnection.hpp"
#include "vechicle.hpp"

#define SPEAKER 0
#define LISTENER 1
uint port = 80008;

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr<<"\n"<<"!==============================!"<<"\n";
        std::cerr<< "Program launched on port "<<port
                <<". To specify port run 'program <port>'\n";
        std::cerr<<"!=============NOTE=============!"<<"\n";
        std::cerr<<"To set robot speed please use '_' instad of space."<<"\n\n";

    }
    else {
        port  = atoi(argv[1]);
        std::cerr<<"\n"<<"!==============================!"<<"\n";
        std::cerr<<"The program launched on port "<<port<<"\n";
        std::cerr<<"!=============NOTE=============!"<<"\n";
        std::cerr<<"To set robot speed please use '_' instad od space."<<"\n\n";
    }

    TCPServer* tcp = new TCPServer(port);
    Vechicle* vechicle = new Vechicle();
    //vechicle->createPositionThread();
    try{        
        std::queue<std::string> messageQueue;
        std::string rcvData = "";
        tcp->createConnection();
        do {
            rcvData = tcp->receiveData(SPEAKER);
            std::cout<<"Received message: "<<rcvData<<"\n";
            messageQueue.push(rcvData);

            if(messageQueue.size() != 0 ) {
                std::string msg = messageQueue.front();
                messageQueue.pop();
                vechicle->decodeMessageFromClient(msg);
            }
            else {
                std::cout<<"Waiting for message"<<"\n";
                usleep(200);
            }
        } while (rcvData != "close");
            vechicle->decodeMessageFromClient("stop");
            vechicle->resetPosition();
            delete tcp;
    }
    catch (Exception& e) {
        delete tcp;
        delete vechicle;
        std::cerr<<"Exception!!!"<<"\n"<<e.what()<<"\n";
    }

    std::cerr<<"Thanks for a ride!!!"<<std::endl;
    return 0;
}
