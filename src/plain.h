#ifndef __plain__
#define __plain__

//------------------------------------------------------------------------------
// plain.h - содержит описание самолёта  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "transport.h"

class Plain: public Transport {
public:
    virtual ~Plain() {}

    virtual void In(ifstream &ifst);

    virtual void InRnd();

    virtual void Out(ofstream &ofst);

    virtual double OptimalTime();
private:
    int fly_distance, lifting_capacity;
};

#endif //__plain__
