///Flight cpp file
///Contains function definitions.
///Created by Kenny Zhang

#include "flight.h"

//Constructors
flight::flight(const DSString &name1, const DSString &name2, int priceVal, int timeVal, const DSString &airL) {
    setL1(name1);
    setL2(name2);
    setPrice(priceVal);
    setTime(timeVal);
    setAirL(airL);
}

flight::flight(const flight &arg) {
    setL1(arg.l1);
    setL2(arg.l2);
    setPrice(arg.price);
    setTime(arg.time);
    setAirL(arg.airline);
}

flight::~flight() {

}

