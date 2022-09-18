///Request cpp file
///Contains function definitions.
///Created by Kenny Zhang

#include "request.h"

//Constructors
request::request() = default;

request::~request() = default;

request::request(const request& req) {
    start = req.start;
    dest = req.dest;
    sortByCost = req.sortByCost;
    itList = req.itList;
}

request::request(DSString start, DSString dest, bool sortByCost) {
    this->start = start;
    this->dest = dest;
    this->sortByCost = sortByCost;
}

//List Modifiers
/**
 * Sorts all flights in all the itineraries in the list by time or cost based upon "bool sortByCost"
 */
void request::sortItList() {
    if (itList.getNumMembers() <= 1) { return; }
    //itList.swap(0, 1);

    for (int j = 0; j < itList.getNumMembers() - 1; j++) {
        int lowest, cur;
        int index = j;

        if (sortByCost) { lowest = itList.get_at(j).getCost(); }
        else { lowest = itList.get_at(j).getTime(); }

        for (int i = j + 1; i < itList.getNumMembers(); i++) {
            if (sortByCost) { cur = itList.get_at(i).getCost(); }
            else { cur = itList.get_at(i).getTime(); }

            if (cur < lowest) {
                lowest = cur;
                index = i;
            }
        }

        itList.swap(j, index);
    }
}


