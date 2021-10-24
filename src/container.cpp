//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

Container::Container(): len{0} { }

Container::~Container() {
    Clear();
}

void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

void Container::In(ifstream &ifst) {
    while(!ifst.eof()) {
        if((storage[len] = Transport::StaticIn(ifst)) != 0) {
            len++;
        }
    }
}

void Container::InRnd(int size) {
    while(len < size) {
        if((storage[len] = Transport::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        ofst << i << ": ";
        storage[i]->Out(ofst);
    }
}

void Container::StraightSelectionSort() {
    for (int i = 0; i < len; ++i) {
        int min_index = i; // первые i мы уже отсочтирвали 
        //первое не отсортированное число находится под индексом i

        for (int j = i; j < len; ++j) {
            if (storage[j]->OptimalTime() < storage[i]->OptimalTime()) {
                min_index = j;
            }
        }
        // мы нашли индекс минимального не отсортированного элемента
        // и перемещаем его в первую неотсортированную позицию
        Transport* tmp = storage[i];
        storage[i] = storage[min_index];
        storage[min_index] = tmp;
        // теперь она стала отсортированной
    }
}

