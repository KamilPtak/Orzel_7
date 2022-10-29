#include <exception>
#include <string>
#pragma once

class Exception : public std::exception {
    private:
        std::string message;

    public:
        virtual std::string what() = 0;
        virtual ~Exception() {};
};

class TCPException : public Exception {
    private:
        std::string message;

    public:
        TCPException(std::string msg): message(msg) {}
        virtual std::string what() override {
            return message;
        }
};

class VechicleException : public Exception {
    private:
        std::string message;

    public:
        VechicleException(std::string msg): message(msg) {}
        virtual std::string what() override {
            return message;
        }
};

class UARTException : public Exception {
    private:
        std::string message;

    public:
        UARTException(std::string msg): message(msg) {}
        virtual std::string what() override {
            return message;
        }
};