/**
 * @file Gravity.cpp
 * @author Aidan Keighron
 */

#include "pch.h"
#include "Gravity.h"

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
    wxFont font(wxSize(0, 20), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);
    dc->SetTextForeground(wxColour(0, 64, 0));
    dc->DrawText(L"Simulation", 10, 10);
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Gravity::Update(double elapsed)
{
}