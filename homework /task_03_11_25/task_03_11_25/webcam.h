#pragma once

#include <string>
using namespace std;

class Webcam
{
private:
    string resol;
    int fps;

public:
    Webcam() = default;
    Webcam(const string& resol, int fps);

    string getResol() const;
    int getFps() const;
};

