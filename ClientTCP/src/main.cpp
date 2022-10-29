#include <iostream>
#include "TCPconnection.cpp" //przy rozszeeniu .cpp jakims cudem dziala - teraz nie widzi definicji funkcji z tcp.cpp

std::string selectMode() {
    std::string input = "";
    std::cout<<"Type 'talk' or 'listen' to select client mode"<<"\n";
    std::cin>>input;

    if(input != "talk" and input != "listen") {
        std::cout<<"Enter client mode correctly!"<<"\n";
        input = selectMode();
    }
    return input;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr<<"Run program with 'program <ip address> <port>'\n";
        return -1;
    }
    
    std::string ipAdress(argv[1]);
    uint portNum   = atoi(argv[2]);

    TCPClient* tcp = new TCPClient(ipAdress, portNum);
    try{
        std::string rcvData = "";
        std::string mode = "";
        std::string dataToSend = "";

        tcp->createConnection();
        mode = selectMode();
        std::cout<<"Work in "<<mode<<"mode."<<"\n";

        if(mode == "talk") {
            while (dataToSend != "close") {
                std::cout<<"Enter command for robot: "<<"\n";
                std::cin>>dataToSend;
                tcp->sendData(dataToSend);
            }
            tcp->closeConnection();
        }
        else {
            while(rcvData != "close") {
            rcvData = tcp->receiveData();
            std::cout<<rcvData;
            }
            tcp->closeConnection();
        }

        delete tcp;
    }
    catch (TCPException& e){
        std::cerr<<e.what()<<"\n";
        delete tcp;
    }

    
    return 0;
}