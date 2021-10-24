#ifndef __transport__
#define __transport__

//------------------------------------------------------------------------------
// transport.h - содержит описание обобщающей транспорт
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"

class Transport {
protected:
    static Random rnd20;
    static Random rnd3;
    int speed, distance;
public:
    virtual ~Transport() {}
    // Ввод обобщенной фигуры
    static Transport *StaticIn(ifstream &ifdt);
    // Ввод обобщенной фигуры
    virtual void In(ifstream &ifdt) = 0;
    // Случайный ввод обобщенной фигуры
    static Transport *StaticInRnd();
    // Виртуальный метод ввода случайной фигуры
    virtual void InRnd() = 0;
    // Вывод обобщенной фигуры
    virtual void Out(ofstream &ofst) = 0;
    // Вычисление периметра обобщенной фигуры
    virtual double OptimalTime() = 0;
};


#endif //__transport__
