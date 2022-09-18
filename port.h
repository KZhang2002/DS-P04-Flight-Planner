///Port header file
///Contains function prototypes.
///Created by Kenny Zhang
///"The sky above the port was the color of television, tuned to a dead channel." - Will Gibson
#ifndef INC_22S_FLIGHT_PLANNER_PORT_H
#define INC_22S_FLIGHT_PLANNER_PORT_H

#include "DSLinkedList.h"
#include "DSString.h"
#include "flight.h"

class port {
private:
    DSString name;
    DSLinkedList<flight> *destList = new DSLinkedList<flight>; //destList = destinations
public:
    port();
    explicit port(const DSString& portName);
    explicit port(char* s);
    ~port();

    //getters
    DSString getName() { return name; }
    DSLinkedList<flight>& getDestList() { return *destList; }

    //setters
    void setName(const DSString& val) { name = val; }
};


#endif //INC_22S_FLIGHT_PLANNER_PORT_H
