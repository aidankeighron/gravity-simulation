/**
 * @file Gravity.h
 * @author Aidan Keighron
 *
 *
 */
 
#ifndef GRAVITY_H
#define GRAVITY_H

#include <vector>
#include <memory>

class Planet;

/**
 * Gravity class
 */
class Gravity {
private:
    std::vector<std::shared_ptr<Planet>> mPlanets;
public:
    Gravity();
    void OnDraw(wxDC* dc);
    void Update(double elapsed);
    void AddPlanet(std::shared_ptr<Planet> planet);
};



#endif //GRAVITY_H
