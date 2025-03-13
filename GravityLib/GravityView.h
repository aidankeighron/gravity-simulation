/**
 * @file GravityView.h
 * @author Aidan Keighron
 */
 
#ifndef GRAVITYVIEW_H
#define GRAVITYVIEW_H

#include "Gravity.h"

class Planet;

/**
 * Gravity window
 */
class GravityView : public wxWindow {
private:
    void OnPaint(wxPaintEvent&);
    void TimerEvent(wxTimerEvent& event);
    void AddPlanet(wxCommandEvent& event);
    void OnLeftDown(wxMouseEvent& event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnMouseWheel(wxMouseEvent& event);

    Gravity mGravity; /// Reference to the Gravity

    wxTimer mTimer; /// The timer that allows for animation
    wxStopWatch mStopWatch; /// Stopwatch used to measure elapsed time
    long mTime = 0; /// The last stopwatch time

    int mMouseX = 0;
    int mMouseY = 0;

    bool mMouseDown = false;
    int mRadius = 20;
    int mMass = 100.0;

    int mVelocityVector[2][2] = {{0,0},{0,0}};
public:
    void Initialize(wxFrame*);
};

#endif //GRAVITYVIEW_H
