//------------------------------------------------------------------------------
// train.cpp - содержит функции обработки поезда
//------------------------------------------------------------------------------

#include "train.h"

void Train::In(ifstream &ifst) {
    ifst >> speed >> distance >> cars_counter;
}

void Train::InRnd() {
    speed = Transport::rnd20.Get();
    distance = Transport::rnd20.Get();
    cars_counter = Transport::rnd20.Get();
}

void Train::Out(ofstream &ofst) {
    ofst << "It is Train: speed = " 
         << speed << ", distance = " << distance
         << ", cars counter = " << cars_counter
         << ". Optimal time = " << OptimalTime() << "\n";
}

double Train::OptimalTime() {
    return static_cast<double>(distance) / static_cast<double>(speed);
}
