#pragma once

#include <string>
using namespace std;

class Mouse
{
private:
    string brand;
    int dpi;
    bool wireless;

public:
    Mouse() = default;
    Mouse(const string& brand, int dpi, bool wireless);

    string getBrand() const;
    int getDpi() const;
    bool isWireless() const;
};


