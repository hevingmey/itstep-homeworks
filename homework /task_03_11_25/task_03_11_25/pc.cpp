#include "pc.h"

PC::PC(const string& ownerName,
       const string& cpuModel, int cpuCores, double cpuFreqGHz, int cpuThreads,
       int ramSizeGb, const string& ramType, int ramFreqMHz, int ramChannels,
       Mouse* mouse, Keyboard* keyboard, Webcam* webcam)
    : ownerName{ ownerName },
      cpu{ cpuModel, cpuCores, cpuFreqGHz, cpuThreads },
      ram{ ramSizeGb, ramType, ramFreqMHz, ramChannels },
      mouse{ mouse }, keyboard{ keyboard }, webcam{ webcam }
{
}

void PC::show() const
{
    cout << "PC owner: " << ownerName << endl;

    cout << "CPU: " << cpu.getModel()
         << ", cores: " << cpu.getCores()
         << ", threads: " << cpu.getThreads()
         << ", freq: " << cpu.getFGHz() << " GHz" << endl;

    cout << "RAM: " << ram.getSizeGb() << " GB "
         << ram.getType() << ", "
         << ram.getFMHz() << " MHz, "
         << "channels: " << ram.getChanls() << endl;

    if (mouse)
    {
        cout << "Mouse: " << mouse->getBrand()
             << ", dpi: " << mouse->getDpi()
             << ", wireless: " << (mouse->isWireless() ? "yes" : "no")
             << endl;
    }
    else
        cout << "No mouse connected" << endl;

    if (keyboard)
    {
        cout << "Keyboard: " << keyboard->getBrand()
             << ", keys: " << keyboard->getKCount()
             << ", backlight: " << (keyboard->Blight() ? "yes" : "no")
             << endl;
    }
    else
        cout << "No keyboard connected" << endl;

    if (webcam)
    {
        cout << "Webcam: " << webcam->getResol()
             << ", " << webcam->getFps() << " fps" << endl;
    }
    else
        cout << "No webcam connected" << endl;
}
