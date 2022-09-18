///Port cpp file
///Contains function definitions.
///Created by Kenny Zhang

#include "port.h"

port::port() {
    name = "null";
}

port::port(const DSString& portName) {
    name = portName;
}

port::port(char* s) {
    name = DSString(s);
}

port::~port() {
}


