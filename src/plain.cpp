//------------------------------------------------------------------------------
// plain.cpp - содержит методы самолёта
//------------------------------------------------------------------------------

#include "transport.h"
#include "plain.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void Plain::In(ifstream &ifst) {
    ifst >> speed >> distance >> fly_distance >> lifting_capacity;
}

// Случайный ввод параметров прямоугольника
void Plain::InRnd() {
    fly_distance = Transport::rnd20.Get();
    lifting_capacity = Transport::rnd20.Get();
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Plain::Out(ofstream &ofst) {
    ofst << "It is Plain: speed = " << speed 
        << ", distance = " << distance 
        << ", fly distance = " << fly_distance 
        << ", lifting capacity = " << lifting_capacity
        << ". Optimal time = " << OptimalTime() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double Plain::OptimalTime() {
    return static_cast<double>(fly_distance) / static_cast<double>(speed);
}
