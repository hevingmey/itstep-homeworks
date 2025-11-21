#include "keyboard.h"

Keyboard::Keyboard(const string& brand, int kCount, bool blight)
    : brand{ brand }, kCount{ kCount }, blight{ blight }
{
}

string Keyboard::getBrand() const
{
    return brand;
}

int Keyboard::getKCount() const
{
    return kCount;
}

bool Keyboard::Blight() const
{
    return blight;
}
