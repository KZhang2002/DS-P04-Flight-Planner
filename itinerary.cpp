///Itinerary cpp file
///Contains function definitions.
///Created by Kenny Zhang

#include "itinerary.h"

//Constructor
itinerary::itinerary(DSLinkedList<port> &locList) {
    for (int i = 0; i < locList.getNumMembers() - 1; i++) {
        for (int j = 0; j < locList.get_at(i).getDestList().getNumMembers(); j++) {
            if (locList.get_at(i).getDestList().get_at(j).getL2() == locList.get_at(i+1).getName()) {
                flight *temp = new flight(locList.get_at(i).getDestList().get_at(j));
                flightList.push_back(*temp);
            }
        }
    }
}

/**
 * Adds flight and the flight price/time to the itinerary
 * @param fl
 */
void itinerary::addFlight(flight fl) { //pass by reference?
    if (flightList.getNumMembers() > 0) {
        cost += 23;
        time += 43;
    }
    flightList.push_back(fl);
    cost += fl.getPrice();
    time += fl.getTime();
}


