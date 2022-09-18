///Itinerary header file
///Contains function prototypes.
///Created by Kenny Zhang

#ifndef INC_22S_FLIGHT_PLANNER_ITINERARY_H
#define INC_22S_FLIGHT_PLANNER_ITINERARY_H

#include "DSLinkedList.h"
#include "DSString.h"
#include "port.h"
#include "flight.h"

class itinerary {
private:
    DSLinkedList<flight> flightList;
    int cost = 0;
    int time = 0;
public:
    //Constructors
    itinerary() = default;
    explicit itinerary(DSLinkedList<port> &locList);
    ~itinerary() = default;

    //Getters
    DSLinkedList<flight>& getFlightList() { return flightList; }
    int getTime() { return time; }
    int getCost() { return cost; }

    //List Modifiers
    void addFlight(flight fl);
};


#endif //INC_22S_FLIGHT_PLANNER_ITINERARY_H
