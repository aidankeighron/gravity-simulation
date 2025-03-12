/**
 * @file MainFrame.h
 * @author Aidan Keighron
 */

#ifndef GRAVITY_MAINFRAME_H
#define GRAVITY_MAINFRAME_H

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame {
private:

public:
 void Initialize();
 void OnExit(wxCommandEvent& event);
};

#endif //GRAVITY_MAINFRAME_H