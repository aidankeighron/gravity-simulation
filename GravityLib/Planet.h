/**
 * @file Planet.h
 * @author Aidan Keighron
 *
 *
 */
 
#ifndef PLANET_H
#define PLANET_H

#include <random>

class Planet {
private:
    int mX;
    int mY;
    double mVX;
    double mVY;

    int mRadius;
    double mMass;

    wxColour mColour;

    std::mt19937 mRandom;

public:
    Planet(int radius, double mass);
    void SetLocation(int x, int y, int vx, int vy);
    void Update(double dt);
    void Draw(wxDC* dc);
};



#endif //PLANET_H
