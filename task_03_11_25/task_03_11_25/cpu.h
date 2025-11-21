#pragma once

#include <string>
using namespace std;

class Cpu
{
private:
    string model;
    int cores;
    double fGHz;
    int threads;

public:
    Cpu() = default;
    Cpu(const string& model, int cores, double fGHz, int threads);

    string getModel() const;
    int getCores() const;
    double getFGHz() const;
    int getThreads() const;
};

