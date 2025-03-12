/**
 * @file GravityView.h
 * @author Aidan Keighron
 */
 
#ifndef GRAVITYVIEW_H
#define GRAVITYVIEW_H

#include "Gravity.h"

/**
 * Gravity window
 */
class GravityView : public wxWindow {
private:
    void OnPaint(wxPaintEvent&);
    void TimerEvent(wxTimerEvent& event);

    Gravity  mGravity; /// Reference to the Gravity
    wxTimer mTimer; /// The timer that allows for animation
    wxStopWatch mStopWatch; /// Stopwatch used to measure elapsed time
    long mTime = 0; /// The last stopwatch time
public:
    void Initialize(wxFrame*);
};

#endif //GRAVITYVIEW_H
