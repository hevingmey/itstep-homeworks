#pragma once

#include <string>
using namespace std;

class Keyboard
{
private:
    string brand;
    int kCount;
    bool blight;

public:
    Keyboard() = default;
    Keyboard(const string& brand, int kCount, bool blight);

    string getBrand() const;
    int getKCount() const;
    bool Blight() const;
};


