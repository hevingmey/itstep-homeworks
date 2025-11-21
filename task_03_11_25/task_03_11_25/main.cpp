#include "pc.h"

int main()
{
    Mouse mouse("Logitech", 1600, true);
    Keyboard keyboard("HyperX", 104, true);
    Webcam webcam("1920x1080", 60);

    PC myPc(
        "Vlad",
        "Intel Core i5-12400F", 6, 2.5, 12,
        16, "DDR4", 3200, 2,
        &mouse, &keyboard, &webcam
    );

    myPc.show();

    return 0;
}

