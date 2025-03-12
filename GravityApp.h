/**
 * @file GravityApp.h
 * @author Aidan Keighron
 */
 
#ifndef GRAVITYAPP_H
#define GRAVITYAPP_H

#include <wx/wx.h>

/**
 * Main application class
 */
class GravityApp : public wxApp {
private:

public:
    bool OnInit() override;
};

#endif //GRAVITYAPP_H
