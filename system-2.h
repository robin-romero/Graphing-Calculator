#ifndef SYSTEM_H
#define SYSTEM_H
#include <SFML/Graphics.hpp>
#include "grapher.h"

using namespace std;
class System
{
public:
    //lazy bum uses grapher to do all the work
    System();
    void Step(int command);
    void Draw(sf::RenderWindow& window);
    void setEquation(string equation);
private:
    Grapher graph;
    string equation;
};
#endif // SYSTEM_H
