#pragma once
#include <fstream>
#include "ship.h"
#include "keeper.h"

using namespace std;

class boats : public ship {
private:
    string purpose;
    string housing_material;
    string driving_qualities;
    int speed;
    int capacity;
public:
    boats();
    ~boats();
    boats(const boats&);
    void setVal() override;
    friend ofstream& operator << (ofstream& fout, boats& obj);
    friend ifstream& operator >> (ifstream& fin, boats& obj);
    friend ostream& operator << (ostream& out, boats& obj);
    friend istream& operator >> (istream& in, boats& obj);
    boats& operator =(const boats& other);
};
