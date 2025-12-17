#pragma once
#include <string>
#include <iostream>

#include "mouse.h"
#include "keyboard.h"
#include "cpu.h"
#include "ram.h"
#include "webcam.h"

using namespace std;


class PC
{
private:
    string ownerName;

    Cpu cpu;
    Ram ram;

    Mouse* mouse;
    Keyboard* keyboard;
    Webcam* webcam;

public:
    PC(const string& ownerName,
       const string& cpuModel, int cpuCores, double cpuFreqGHz, int cpuThreads,
       int ramSizeGb, const string& ramType, int ramFreqMHz, int ramChannels,
       Mouse* mouse, Keyboard* keyboard, Webcam* webcam);

    void show() const;
};

