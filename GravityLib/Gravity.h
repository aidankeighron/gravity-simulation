/**
 * @file Gravity.h
 * @author Aidan Keighron
 *
 *
 */
 
#ifndef GRAVITY_H
#define GRAVITY_H

/**
 * Gravity class
 */
class Gravity {
private:

public:
    Gravity();
    void OnDraw(wxDC* dc);
    void Update(double elapsed);
};



#endif //GRAVITY_H
