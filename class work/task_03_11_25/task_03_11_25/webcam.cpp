#include "webcam.h"

Webcam::Webcam(const string& resol, int fps)
    : resol{ resol }, fps{ fps }
{
}

string Webcam::getResol() const
{
    return resol;
}

int Webcam::getFps() const
{
    return fps;
}
