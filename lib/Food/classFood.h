#ifndef Food_h
#define Food_h

#include <Arduino.h>

class Food{
    public:
        uint8_t x;
        uint8_t y;
        void newXCoord();
        void newYCoord();
        void newLocation();
};

#endif