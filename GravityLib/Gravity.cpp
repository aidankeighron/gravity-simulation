/**
 * @file Gravity.cpp
 * @author Aidan Keighron
 */

#include "pch.h"
#include "Gravity.h"
#include <math.h>
#include "Planet.h"

using namespace std;

const double G = 6.67e11;
const double g = 9.87;

/**
 * Gravity Constructor
 */
Gravity::Gravity()
{

}

/**
 * Draw the simulation
 * @param dc The device context to draw on
 */
void Gravity::OnDraw(wxDC *dc)
{
    for (auto planet : mPlanets)
    {
        planet->Draw(dc);
    }
}

double Distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double Distance(Planet planet1, Planet planet2)
{
    return sqrt(pow(planet2.GetX() - planet1.GetX(), 2) + pow(planet2.GetY() - planet1.GetY(), 2));
}

/**
 * Handle updates for animation
 * @param dt The time since the last update
 */
void Gravity::Update(double dt)
{
    for (int i = 0; i < mPlanets.size(); ++i)
    {
        for (int j = 0; j < mPlanets.size(); ++j)
        {
            if (i == j)
            {
                continue;
            }
            double distance = Distance(*mPlanets[i], *mPlanets[j]);
            if (distance < mPlanets[i]->GetRadius() || distance < mPlanets[j]->GetRadius())
            {
                continue;
            }
            // Fg = G*m1*m2 / r^2
            double Fg = (100000*mPlanets[i]->GetMass()*mPlanets[j]->GetMass()) / pow(distance, 2);
            if (Fg < 0) { Fg *= -1; }
            // dx = x1 - x0
            double dx = mPlanets[j]->GetX() - mPlanets[i]->GetX();
            double dy = mPlanets[j]->GetY() - mPlanets[i]->GetY();
            // theta = atan(y/x)
            double theta = atan2(dy, dx);

            // x = Fcos(theta)
            double Fx = Fg*cos(theta);
            // sin
            double Fy = Fg*sin(theta);

            mPlanets[i]->addForce(Fx, Fy);
        }
    }

    for (auto planet : mPlanets)
    {
        planet->Update(dt);
    }
}

void Gravity::AddPlanet(std::shared_ptr<Planet> planet)
{
    mPlanets.push_back(planet);
}

void Gravity::Clear()
{
    mPlanets.clear();
}