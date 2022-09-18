///Flight Planner header file
///Contains function prototypes.
///Created by Kenny Zhang

#ifndef INC_22S_FLIGHT_PLANNER_FLIGHT_PLANNER_H
#define INC_22S_FLIGHT_PLANNER_FLIGHT_PLANNER_H

#include <fstream>
#include "DSLinkedList.h"
#include "DSStack.h"
#include "DSString.h"
#include "DSVector.h"
#include "port.h"
#include "request.h"
#include "flight.h"

class flight_planner {
private:
    DSLinkedList<port> *airports = new DSLinkedList<port>; //Stores airports and their flights
    DSLinkedList<request> *reqList = new DSLinkedList<request>; //Stores requests

public:
    //Constructors
    flight_planner();
    ~flight_planner();

    //Data Input
    void inputRequests(std::ifstream &file);
    void inputFlights(std::ifstream &file);

    //Data Output
    void outputRequests();
    void outputPorts();
    void outputResults(std::ofstream &output);
    void printStack(DSStack<port> *stackVal);

    //Pathfinding Methods
    void planFlights();
    void findItineraries(request &req);
    port *strToPtr(DSString str);
    bool isInStack(DSStack<port>& tempStack, port);
};


#endif //INC_22S_FLIGHT_PLANNER_FLIGHT_PLANNER_H
