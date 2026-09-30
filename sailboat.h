#pragma once
#include <fstream>
#include "ship.h"
#include "keeper.h"

using namespace std;

class Sailboat : public ship
{
private:
    string type;
    string name;
    string peaceful_military;
    double body_length;
    double speed;
    double crew;
public:
    Sailboat();
    ~Sailboat();
    Sailboat(const Sailboat&);
    void setVal() override;
    friend ofstream& operator << (ofstream& fout, Sailboat& obj);
    friend ifstream& operator >> (ifstream& fin, Sailboat& obj);
    friend ostream& operator << (ostream& out, Sailboat& obj);
    friend istream& operator >> (istream& in, Sailboat& obj);
    Sailboat& operator =(const Sailboat& other);
};
