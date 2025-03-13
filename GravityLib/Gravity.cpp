/**
 * @file Gravity.cpp
 * @author Aidan Keighron
 */

#include "pch.h"
#include "Gravity.h"

#include "Planet.h"

using namespace std;

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

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Gravity::Update(double elapsed)
{
    for (auto planet : mPlanets)
    {
        planet->Update(elapsed);
    }
}

void Gravity::AddPlanet(std::shared_ptr<Planet> planet)
{
    mPlanets.push_back(planet);
}