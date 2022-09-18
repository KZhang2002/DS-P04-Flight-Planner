///Flight Planner cpp file
///Contains function definitions.
///Created by Kenny Zhang
///"The word of today, kids, is spaghetti!"

#include "flight_planner.h"

///Constructors
flight_planner::flight_planner() = default;

flight_planner::~flight_planner() {
    delete airports;
    delete reqList;
}

///Data Input
/**
 * Takes in requests from "file". Request objects
 * are added to requests list from here.
 * @param file
 */
void flight_planner::inputRequests(std::ifstream &file) {
    if (file.is_open()) {
        char buffer[8] = "null";
        file.getline(buffer, 8);
        int numRequests = atoi(buffer);
        file.clear();

        if (file.peek() != EOF) {
            for (int i = 0; i < numRequests; i++) {
                char beg[64] = "null"; //beg = beginning
                char dest[64] = "null"; //dest = destination
                char sort[8] = "null";
                bool sortByCost = false;

                file.getline(beg, 64, ' ');
                file.clear();

                file.getline(dest, 64, ' ');
                file.clear();

                file.getline(sort, 3);
                if (tolower(sort[0]) == 't') { sortByCost = true; }
                file.clear();

                reqList->push_back(request(DSString(beg), DSString(dest), sortByCost));
            }
        } else {
            cout << "File has not been successfully opened. Closing program." << endl;
            throw;
        }
    }
}

/**
 * Takes in flight data from "file". For each new location
 * seen in the flight data, a new "port" object is made.
 * Then the relevant flights are added to the "port" object's
 * destList.
 * @param file
 */
void flight_planner::inputFlights(std::ifstream &file) {
    if (file.is_open()) {
        char buffer[8] = "null";
        file.getline(buffer, 8, '\r');
        int numRequests = atoi(buffer);
        file.clear();

        if (file.peek() != EOF) {
            for (int i = 0; i < numRequests; i++) {
                char begBuffer[64] = "null"; //beg = beginning
                char destBuffer[64] = "null"; //dest = destination
                char airlineBuffer[64] = "null";
                char costBuffer[5] = "null";
                char timeBuffer[5] = "null";

                int price = 0;
                int time = 0;

                file.ignore(3, '\n');

                file.getline(begBuffer, 64, ' ');
                DSString beg(begBuffer);
                file.clear();

                file.getline(destBuffer, 64, ' ');
                DSString dest(destBuffer);
                file.clear();

                file.getline(costBuffer, 5, ' ');
                price = atoi(costBuffer);
                file.clear();

                file.getline(timeBuffer, 5, ' ');
                time = atoi(timeBuffer);
                file.clear();

                file.getline(airlineBuffer, 64, '\r');
                DSString airline(airlineBuffer);
                file.clear();

                bool destExists = false;
                int destInd = airports->getNumMembers();
                for (int j = 0; j < airports->getNumMembers(); j++) {
                    if (strcmp(airports->get_at(j).getName().c_str(), dest.c_str()) == 0) {
                        destExists = true;
                        destInd = j;
                        break;
                    }
                }

                if (!destExists) {
                    airports->push_back(port(destBuffer)); //Memory leaked
                }

                flight flDestBuffer(dest, beg, price, time, airline);
                airports->get_at(destInd).getDestList().push_back(flDestBuffer);

                bool begExists = false;
                int begInd = airports->getNumMembers();
                for (int j = 0; j < airports->getNumMembers(); j++) {
                    if (strcmp(airports->get_at(j).getName().c_str(), beg.c_str()) == 0) {
                        begExists = true;
                        begInd = j;
                        break;
                    }
                }

                if (!begExists) {
                    airports->push_back(port(begBuffer)); //Memory leaked
                }

                flight flBegBuffer(beg, dest, price, time, airline);
                airports->get_at(begInd).getDestList().push_back(flBegBuffer);
            }
        } else {
            cout << "File has not been successfully opened. Closing program." << endl;
            throw;
        }
    }
}

///Data Output
/**
 * Outputs all requests in reqList. Used for debugging.
 * Not necessary for main program function.
 */
void flight_planner::outputRequests() {
    std::ofstream file("Parsed Requests.txt");

    if (file.is_open()) {
        file << "Requested Flights:\n";
        for (int i = 0; i < reqList->getNumMembers(); i++) {
            file << "\tFlight " << i << ": ";
            file << reqList->get_at(i).getStart() << ", " << reqList->get_at(i).getDest();
            if (reqList->get_at(i).isSortByCost()) { file << " (Cost)\n"; } else { file << " (Time)\n"; }
        }
    } else {
        cout << "File has not been successfully opened. Closing program." << endl;
        throw;
    }
}

/**
 * Outputs all ports in airports. Used for debugging.
 * Not necessary for main program function.
 */
void flight_planner::outputPorts() {
    std::ofstream file("Ports.txt");

    if (file.is_open()) {
        file << "Ports:\n";
        for (int i = 0; i < airports->getNumMembers(); i++) {
            file << "\tCity: " << airports->get_at(i).getName() << "\n";

            for (int j = 0; j < airports->get_at(i).getDestList().getNumMembers(); j++) {
                auto flight = airports->get_at(i).getDestList().get_at(j);
                file << "\t\tStart: " << flight.getL1() << " | End: " << flight.getL2();
                file << " | Price: " << flight.getPrice() << " | Time: " << flight.getTime();
                file << " | Airline: " << flight.getAirline() << "\n";

            }
        }
    } else {
        cout << "File has not been successfully opened. Closing program." << endl;
        throw;
    }
}

/**
 * Outputs all elements in "stackVal". Used for debugging.
 * Not necessary for main program function.
 */
void flight_planner::printStack(DSStack<port> *stackVal) {
    cout << "STACK: ";
    node<port>* itr;
    itr = stackVal->getStack().getHead();
    for (int i = 0; i < stackVal->getStack().getNumMembers(); i++) {
        DSString tempName(itr->getData().getName());
        cout << tempName;
        if (i != stackVal->getStack().getNumMembers() - 1) { cout << " -> "; }
        itr = itr->getNext();
    }
    cout << endl;
}

/**
 * Outputs all flights in all the itineraries to "output".
 * @param output
 */
void flight_planner::outputResults(std::ofstream &output) {
    for (int i = 0; i < reqList->getNumMembers(); i++) {
        request tempReq = reqList->get_at(i);
        output << "Flight " << i + 1 << ": " << tempReq.getStart() << ", " << tempReq.getDest();
        if (tempReq.isSortByCost()) { output << " (Time)\n"; } else { output << " (Cost)\n"; }
        for (int j = 0; j < reqList->get_at(i).getItList().getNumMembers(); j++) {
            output << "\tItinerary " << j + 1 << ":\n";
            for (int l = 0; l < reqList->get_at(i).getItList().get_at(j).getFlightList().getNumMembers(); l++) {
                flight temp = reqList->get_at(i).getItList().get_at(j).getFlightList().get_at(l);
                output << "\t\t" << temp.getL1() << " -> " << temp.getL2() << " (" << temp.getAirline() << ")\n";
            }
            output << "\t\tTotals for Itinerary " << j + 1 << "  Time: " << reqList->get_at(i).getItList().get_at(j).getTime() << " Cost: " << reqList->get_at(i).getItList().get_at(j).getCost() << ".00\n";
        }
    }
}

///Pathfinding Methods
/**
 * Driver function for iterative backtracking search.
 * Finds itnieraries for all requests in reqList.
 */
void flight_planner::planFlights() {
    for (int i = 0; i < reqList->getNumMembers(); i++) {
        airports->resetIterator();
        for (int i = 0; i < airports->getNumMembers(); i++) { airports->get_at(i).getDestList().resetIterator(); }
        cout << "Itinerary search started." << endl;
        findItineraries(reqList->get_at(i));
        cout << "Request " << i + 1 << " is completed" << endl;
        reqList->get_at(i).sortItList();
    }
}

/**
 * Find all possible itineraries from two cities given by "req".
 * Itineraries are added to req's itList. Uses iterative backtracking.
 * @param req
 * @param index
 */
void flight_planner::findItineraries(request &req) {
    DSStack<port> *tempStack = new DSStack<port>;
    tempStack->push(*strToPtr(req.getStart()));
    tempStack->top().getDestList().resetIterator();
    int iterations = 0; //debug commenting
    int numFLists = 0;

    while (!tempStack->checkEmpty()) {
        iterations++; //debug commenting
        cout << endl << "Iteration " << iterations << endl;

        if (tempStack->top().getName() == req.getDest()) {
            //Creates new flight object from stack and then pops stack.
            itinerary fList;
            req.getItList().push_back(fList);
            for (int n = 0; n < tempStack->getStack().getNumMembers() - 1; n++) {
                for (int j = 0; j < tempStack->getStack().get_at(n).getDestList().getNumMembers(); j++) {
                    if (tempStack->getStack().get_at(n).getDestList().get_at(j).getL2() == tempStack->getStack().get_at(n + 1).getName()) {
                        flight temp(tempStack->getStack().get_at(n).getDestList().get_at(j));
                        req.getItList().get_at(numFLists).addFlight(flight(temp.getL1(), temp.getL2(), temp.getPrice(), temp.getTime(), temp.getAirline()));
                        break;
                    }
                }
            }
            numFLists++;
            tempStack->pop();
        } else {
            //searches new path
            if (tempStack->top().getDestList().getIterator()->getNext() == nullptr) {
                //moves the airport "backwards"
                tempStack->pop();
                printStack(tempStack);

            } else {
                if (isInStack(*tempStack, *strToPtr(tempStack->top().getDestList().getIterator()->getNext()->getData().getL2()))) { //todo seg fault here
                    //Changes location being searched
                    //Moves airport "sideways"
                    tempStack->top().getDestList().incrementIterator();
                    printStack(tempStack);
                } else {
                    //Adds location to stack.
                    //moves "forward" one airport.
                    tempStack->push(*strToPtr(tempStack->top().getDestList().getIterator()->getNext()->getData().getL2()));

                    //increments the previous airport of stack
                    tempStack->getStack().getTail()->getPrev()->getData().getDestList().incrementIterator();
                    printStack(tempStack);
                }
            }
        }
    }
    delete tempStack;
}

/**
 * Checks if port "p" is in stack "tempStack"
 * @param tempStack
 * @param p
 * @return
 */
bool flight_planner::isInStack(DSStack<port>& tempStack, port p) {
    int loopLimit = tempStack.getStack().getNumMembers();
    for (int i = 0; i < loopLimit; i++) {
        //takes every port in the stack and compares it with the name of port p
        DSString tempName(tempStack.getStack().get_at(i).getName());
        if (tempName == p.getName()) {
            return true;
        }
    }
    return false;
}

/**
 * Returns pointer to airport that corresponds to str.
 * @param str
 * @return
 */
port *flight_planner::strToPtr(DSString str) {
    for (int i = 0; i < airports->getNumMembers(); i++) {
        if (str == airports->get_at(i).getName()) {
            return &airports->get_at(i);
        }
    }
    return nullptr;
}