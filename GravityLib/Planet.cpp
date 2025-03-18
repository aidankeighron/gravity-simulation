/**
 * @file Planet.cpp
 * @author Aidan Keighron
 */
 
#include "Planet.h"

Planet::Planet()
{
    mAX = 0;
    mAY = 0;
}

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

Planet::Planet(double radius, double mass)
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

void Planet::SetLocation(double x, double y, double vx, double vy)
{
    mX = x;
    mY = y;
    mVX = vx;
    mVY = vy;
    mAX = 0;
    mAY = 0;
}

void Planet::Update(double dt)
{
    double Fx = 0;
    double Fy = 0;
    for (auto velocity : mActingForces)
    {
        Fx += velocity.mFX;
        Fy += velocity.mFY;
    }
    mActingForces.clear();

    // F = ma
    // F/m = a
    double ax = Fx/mMass;
    double ay = Fy/mMass;

    mAX += ax;
    mAY += ay;

    mX += mVX * dt + 0.5 * mAX * dt * dt;
    mY += mVY * dt + 0.5 * mAY * dt * dt;
}

void Planet::Draw(wxDC *dc)
{
    dc->SetBrush(mColour);
    dc->SetPen(*wxTRANSPARENT_PEN);
    dc->DrawCircle((int)mX, (int)mY, (int)(mRadius));
}