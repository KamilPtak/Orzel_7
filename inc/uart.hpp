//https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/

#include <stdio.h>
#include <string.h>
#include <iostream>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

#include "myExceptions.hpp"

#pragma once

class UART{
    private:
        struct termios tty;
        std::string port;
        int serialPort;
        int baud;
    public:
        UART(std::string port_, int baud_);
        void openSerialPort();
        void closeSerialPort();
        void pushData(std::string data);
        ~UART();
};
