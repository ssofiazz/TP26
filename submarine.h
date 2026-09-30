#pragma once
#include <fstream>
#include "keeper.h"
#include "ship.h"

using namespace std;

class Submarine : public ship
{
private:
    double lenght;
    double weight;
    double crew;
    double time_underwater;
    double speed_underwater;
    string armament;
public:
    Submarine();
    Submarine(const Submarine& other);
    ~Submarine();
    void setVal() override;
    friend ofstream& operator << (ofstream& fout, Submarine& obj);
    friend ifstream& operator >> (ifstream& fin, Submarine& obj);
    friend ostream& operator << (ostream& out, Submarine& obj);
    friend istream& operator >> (istream& in, Submarine& obj);
    Submarine& operator =(const Submarine& other);
};
