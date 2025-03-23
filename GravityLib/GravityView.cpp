/**
 * @file GravityView.cpp
 * @author Aidan Keighron
 */

#include "pch.h"
#include "GravityView.h"
#include "ids.h"
#include <wx/dcbuffer.h>
#include <math.h>
#include "Planet.h"

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Initialize the gravity view class.
 * @param parent The parent window for this class
 */
void GravityView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &GravityView::OnPaint, this);
    Bind(wxEVT_TIMER, &GravityView::TimerEvent, this);

    Bind(wxEVT_LEFT_DOWN, &GravityView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &GravityView::OnLeftUp, this);
    Bind(wxEVT_MOTION, &GravityView::OnMouseMove, this);
    Bind(wxEVT_MOUSEWHEEL, &GravityView::OnMouseWheel, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GravityView::AddPlanet, this, IDM_ADDPLANET);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GravityView::Clear, this, IDM_CLEAR);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();

    mMouseX = 500;
    mMouseY = 500;
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GravityView::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    auto newTime = mStopWatch.Time();
    auto dt = (double)(newTime - mTime) * 0.001;
    mTime = newTime;
    mGravity.Update(dt);

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    wxFont font(wxSize(0, 20), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    dc.SetFont(font);
    dc.SetTextForeground(wxColour(0, 64, 0));
    int y = 10;
    dc.DrawText(L"Simulation", 10, y);
    dc.DrawText(L"Radius: " + std::to_string(mRadius) + L" (Scroll to change)", 10, y += 30);
    dc.DrawText(L"Weight: " + std::to_string(mMass) + L" (Scroll+Shift to change)", 10, y += 30);

    mGravity.OnDraw(&dc);

    if (mMouseDown)
    {
        dc.SetBrush(wxColour(0, 0, 0));
        dc.SetPen(*wxTRANSPARENT_PEN);
        dc.DrawCircle(mMouseX, mMouseY, 5);

        dc.SetPen(wxColour(0, 0, 0));
        dc.DrawLine(mVelocityVector[0][0], mVelocityVector[0][1], mVelocityVector[1][0], mVelocityVector[1][1]);
    }
}

/**
* Handle the timer event
* @param event
*/
void GravityView::TimerEvent(wxTimerEvent &event)
{
    Refresh();
}

void GravityView::AddPlanet(wxCommandEvent& event)
{
    auto planet = make_shared<Planet>(mRadius, mMass);
    double vx = mVelocityVector[1][0] - mVelocityVector[0][0];
    double vy = mVelocityVector[1][1] - mVelocityVector[0][1];
    planet->SetLocation(mMouseX, mMouseY, vx/10.0, vy/10.0);
    mGravity.AddPlanet(planet);
}

void GravityView::Clear(wxCommandEvent& event)
{
    mGravity.Clear();
}

void GravityView::OnLeftDown(wxMouseEvent &event)
{
    mMouseX = event.GetX();
    mMouseY = event.GetY();

    mVelocityVector[0][0] = mMouseX;
    mVelocityVector[0][1] = mMouseY;
    mVelocityVector[1][0] = mMouseX;
    mVelocityVector[1][1] = mMouseY;

    mMouseDown = true;
}

void GravityView::OnLeftUp(wxMouseEvent &event)
{
    auto planet = make_shared<Planet>(mRadius, mMass);
    double vx = mVelocityVector[1][0] - mVelocityVector[0][0];
    double vy = mVelocityVector[1][1] - mVelocityVector[0][1];
    planet->SetLocation(mMouseX, mMouseY, vx, vy);
    mGravity.AddPlanet(planet);

    mMouseDown = false;
}

void GravityView::OnMouseMove(wxMouseEvent &event)
{
    int mouseX = event.GetX();
    int mouseY = event.GetY();

    mVelocityVector[0][0] = mMouseX;
    mVelocityVector[0][1] = mMouseY;
    mVelocityVector[1][0] = mouseX;
    mVelocityVector[1][1] = mouseY;
}

void GravityView::OnMouseWheel(wxMouseEvent &event) {
    int wheelRotation = 0;

    wheelRotation += event.GetWheelRotation();
    int lines = wheelRotation / event.GetWheelDelta();

    if (event.m_shiftDown)
    {
        mRadius += lines * 10;
    }
    else
    {
        mMass += lines * 10;
    }
}