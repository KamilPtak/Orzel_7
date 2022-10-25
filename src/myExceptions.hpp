#include <exception>
#include <string>
#pragma once

class TCPException : public std::exception {
    private:
    std::string message;

    public:
    TCPException(std::string msg): message(msg) {}
    std::string what() {
        return message;
    }
};