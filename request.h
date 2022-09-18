///Request header file
///Contains function definitions.
///Created by Kenny Zhang

#ifndef INC_22S_FLIGHT_PLANNER_REQUEST_H
#define INC_22S_FLIGHT_PLANNER_REQUEST_H

#include "DSString.h"
#include "itinerary.h"
#include "port.h"
#include "DSLinkedList.h"

class request {
private:
    DSString start; //name of starting location

    DSString dest; //name of destination

    bool sortByCost; //Sorts by cost if true, sorts by time if false
    DSLinkedList<itinerary> itList; //List of itineraries
public:
    //Constructors
    request();
    request(const request&);
    request(DSString start, DSString dest, bool sortByCost);
    ~request();

    //Getters
    DSString &getStart() { return start; }
    DSString &getDest() { return dest; }
    DSLinkedList<itinerary> &getItList() { return itList; }
    bool isSortByCost() { return sortByCost; }

    //List Modifiers
    void sortItList();
};


#endif //INC_22S_FLIGHT_PLANNER_REQUEST_H
