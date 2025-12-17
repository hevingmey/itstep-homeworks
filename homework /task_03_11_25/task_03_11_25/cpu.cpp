#include "cpu.h"

Cpu::Cpu(const string& model, int cores, double fGHz, int threads)
    : model{ model }, cores{ cores }, fGHz{ fGHz }, threads{ threads }
{
}

string Cpu::getModel() const
{
    return model;
}

int Cpu::getCores() const
{
    return cores;
}

double Cpu::getFGHz() const
{
    return fGHz;
}

int Cpu::getThreads() const
{
    return threads;
}
