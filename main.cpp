/**
 * Author: Kenny Zhang
 * Github: https://github.com/KZhang2002
 *
 * Project: Flight Planner
 * Repository: https://github.com/SMUCSE2341/22s-pa04-KZhang2002
 *
 * Class: SMU CS 2341 (4649)
 *
 * Desc: Takes in two text files. One containing the flight data and one containing the flight requests.
 * Outputs all possible itineraries for the flight request.
 *
 * Date Released: 4/6/2022
 * Last Updated: 4/6/2022
 */

#include <iostream>
#include <fstream>

/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */
#include "catch_setup.h"
#include "flight_planner.h"

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        //Driver code
        ifstream flightData(argv[1]);
        ifstream requestData(argv[2]);
        ofstream output(argv[3]);

        flight_planner fPlanner;

        fPlanner.inputRequests(requestData);
        //fPlanner.outputRequests(); //debug, uncomment to see parsed requests

        fPlanner.inputFlights(flightData);
        //fPlanner.outputPorts(); //debug, uncomment to see parsed ports

        fPlanner.planFlights();
        fPlanner.outputResults(output);

        flightData.close();
        requestData.close();
        output.close();
    }
    return 0;
}