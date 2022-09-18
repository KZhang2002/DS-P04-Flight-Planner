///Flight header file
///Contains function prototypes.
///Created by Kenny Zhang

#ifndef INC_22S_FLIGHT_PLANNER_FLIGHT_H
#define INC_22S_FLIGHT_PLANNER_FLIGHT_H

#include "DSString.h"
#include "DSLinkedList.h"

class flight {

private:
    DSString l1 = "null"; //location 1
    DSString l2 = "null"; //location 2
    int price = NULL; //in USD
    int time = NULL; //in minutes
    DSString airline = "null"; //airline

public:
    //Constructors
    flight() = default;
    flight(const DSString &name1, const DSString &name2, int price, int time, const DSString &airL);
    flight(const flight &arg);
    ~flight();

    //Getters
    int getPrice() const { return price; }
    int getTime() const { return time; }
    DSString getL1(){ return l1; }
    DSString &getL2() { return l2; }
    DSString getAirline() { return airline; }

    //Setters
    void setPrice(int val) { price = val; }
    void setTime(int val) { time = val; }
    void setL1(const DSString &name) { l1 = name; }
    void setL2(const DSString &name) { l2 = name; }
    void setAirL(const DSString &name) { airline = name; }
};

#endif //INC_22S_FLIGHT_PLANNER_FLIGHT_H
