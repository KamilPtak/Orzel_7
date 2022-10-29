#include <exception>
#include <string>
#pragma once

class Exception : public std::exception {
    private:
        std::string message;
        std::string source;

    public:
        Exception(std::string source, std::string msg): source(source), message(msg) {}
        std::string what() {
            return source + "->" +message;
        }
};