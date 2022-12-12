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
uint port = 80001;

void runRobotRun(std::pair<std::string, Vechicle*> inputPair);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr<< "Program launched on port "<<port<<". To specify port run 'program <port>'\n";
    }
    else {
        port  = atoi(argv[1]);
        std::cerr<<"The program launched on port "<<port<<"\n";
    }
    

    try{
        TCPServer* tcp = new TCPServer(port);
        Vechicle* vechicle = new Vechicle();

        std::queue<std::string> messageQueue;
        std::string rcvData = "";
        tcp->createConnection();


        do {
            rcvData = tcp->receiveData(SPEAKER); 
            std::cout<<"Received message: "<<rcvData<<"\n";
            messageQueue.push(rcvData);

            if(messageQueue.size() != 0 ) {
                auto msg = messageQueue.front();
                messageQueue.pop();
                vechicle->decodeMessageFromClient(rcvData); 
            }
            else {
                std::cout<<"Waiting for message"<<"\n";
                usleep(200);
            }
        } while (rcvData != "close");
        delete tcp;    
        delete vechicle;
    }
    catch (Exception& e){
        std::cerr<<"Exception!!!"<<"\n"<<e.what()<<"\n";  
    }



    std::cerr<<"Thanks for a ride!!!"<<std::endl;
    return 0;
}


void runRobotRun(std::pair<std::string, Vechicle*> inputPair) {
    std::string msg = inputPair.first;
    Vechicle* vechicle = std::move(inputPair.second);
    std::cout<<"I am child thread!!!"<<std::endl;

    try{
        vechicle -> decodeMessageFromClient(msg);
    }
    catch (Exception& e){
        std::cerr<<"Exception!!!"<<"\n"<<e.what()<<"\n";  
    }
}