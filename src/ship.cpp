//------------------------------------------------------------------------------
// ship.cpp - содержит функции обработки кораблей
//------------------------------------------------------------------------------

#include "ship.h"

void Ship::In(ifstream &ifst) {
    ifst >> speed >> distance >> displace;
}

void Ship::InRnd() {
    speed = Transport::rnd20.Get();
    distance = Transport::rnd20.Get();
    displace = Transport::rnd20.Get();
}

void Liner::Out(ofstream &ofst) {
    ofst << "It is Ship Liner: speed = " 
         << speed << ", distance = " << distance
         << ", displace = " << displace
         << ". Optimal time = " << OptimalTime() << "\n";
}

void Tug::Out(ofstream &ofst) {
    ofst << "It is Ship Tug: speed = " 
         << speed << ", distance = " << distance
         << ", displace = " << displace
         << ". Optimal time = " << OptimalTime() << "\n";
}

void Tanker::Out(ofstream &ofst) {
    ofst << "It is Ship Tanker: speed = " 
         << speed << ", distance = " << distance
         << ", displace = " << displace
         << ". Optimal time = " << OptimalTime() << "\n";
}

double Ship::OptimalTime() {
    return static_cast<double>(distance) / static_cast<double>(speed);
}
