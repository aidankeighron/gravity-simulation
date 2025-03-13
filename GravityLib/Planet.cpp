/**
 * @file Planet.cpp
 * @author Aidan Keighron
 */
 
#include "Planet.h"

wxColour HSVtoRGB(double h, double s, double v) {
    if (s == 0.0) {
        return wxColour(v * 255, v * 255, v * 255);
    }

    h = fmod(h, 360);
    h /= 60.0;
    int i = floor(h);
    double f = h - i;
    double p = v * (1 - s);
    double q = v * (1 - s * f);
    double t = v * (1 - s * (1 - f));

    double r, g, b;
    switch (i) {
    case 0: r = v; g = t; b = p; break;
    case 1: r = q; g = v; b = p; break;
    case 2: r = p; g = v; b = t; break;
    case 3: r = p; g = q; b = v; break;
    case 4: r = t; g = p; b = v; break;
    default: // case 5:
        r = v; g = p; b = q; break;
    }
    return wxColour(r * 255, g * 255, b * 255);
}

Planet::Planet(int radius, double mass)
{
    mRadius = radius;
    mMass = mass;
    mX = 0;
    mY = 0;

    std::random_device rd;
    mRandom.seed(rd());

    std::uniform_real_distribution<> colorDistribution(0, 360);
    double hue = colorDistribution(mRandom);

    mColour = HSVtoRGB(hue, 0.7, 0.7);
}

void Planet::SetLocation(int x, int y, int vx, int vy)
{
    mX = x;
    mY = y;
    mVX = vx;
    mVY = vy;
}

void Planet::Update(double dt)
{
    mX += mVX * dt;
    mY += mVY * dt;
}

void Planet::Draw(wxDC *dc)
{
    dc->SetBrush(mColour);
    dc->SetPen(*wxTRANSPARENT_PEN);
    dc->DrawCircle(mX, mY, mRadius);
}