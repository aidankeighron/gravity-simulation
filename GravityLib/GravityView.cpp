/**
 * @file GravityView.cpp
 * @author Aidan Keighron
 */

#include "pch.h"
#include "GravityView.h"
#include "ids.h"
#include <wx/dcbuffer.h>

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

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GravityView::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;
    mGravity.Update(elapsed);

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    mGravity.OnDraw(&dc);
}

/**
* Handle the timer event
* @param event
*/
void GravityView::TimerEvent(wxTimerEvent &event)
{
    Refresh();
}