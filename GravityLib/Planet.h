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
    class Vector2D;
private:
    double mX, mY;
    double mVX, mVY;
    double mAX, mAY;

    double mRadius;
    double mMass;

    std::vector<Vector2D> mActingForces;
    wxColour mColour;

    std::mt19937 mRandom;


public:
    Planet();
    Planet(double radius, double mass);
    void SetLocation(double x, double y, double vx, double vy);
    void Update(double dt);
    void Draw(wxDC* dc);

    double GetMass() const { return mMass; }
    double GetRadius() const { return mRadius; }
    double GetVX() const { return mVX; }
    double GetVY() const { return mVY; }
    double GetAX() const { return mAX; }
    double GetAY() const { return mAY; }
    double GetX() const { return mX; }
    double GetY() const { return mY; }

    void addForce(double fx, double fy)
    {
        mActingForces.push_back(Vector2D(fx, fy));
    }
    class Vector2D
    {
        public:
            double mFX, mFY;
            Vector2D(double x, double y) : mFX(x), mFY(y) {};
    };
};

#endif //PLANET_H
