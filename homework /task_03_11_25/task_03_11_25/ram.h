#pragma once

#include <string>
using namespace std;

class Ram
{
private:
    int sizeGb;
    string type;      
    int fMHz;
    int chanls;

public:
    Ram() = default;
    Ram(int sizeGb, const string& type, int fMHz, int chanls);

    int getSizeGb() const;
    string getType() const;
    int getFMHz() const;
    int getChanls() const;
};

