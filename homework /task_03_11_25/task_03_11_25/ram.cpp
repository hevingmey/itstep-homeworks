#include "ram.h"

Ram::Ram(int sizeGb, const string& type, int fMHz, int chanls)
    : sizeGb{ sizeGb }, type{ type }, fMHz{ fMHz }, chanls{ chanls }
{
}

int Ram::getSizeGb() const
{
    return sizeGb;
}

string Ram::getType() const
{
    return type;
}

int Ram::getFMHz() const
{
    return fMHz;
}

int Ram::getChanls() const
{
    return chanls;
}
