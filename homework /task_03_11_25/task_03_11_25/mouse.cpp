#include "mouse.h"

Mouse::Mouse(const string& brand, int dpi, bool wireless)
    : brand{ brand }, dpi{ dpi }, wireless{ wireless }
{
}

string Mouse::getBrand() const
{
    return brand;
}

int Mouse::getDpi() const
{
    return dpi;
}

bool Mouse::isWireless() const
{
    return wireless;
}

