#ifndef ANIMATE_H
#define ANIMATE_H
#include <SFML/Graphics.hpp>
#include "system.h"

class Animate
{
public:
    //called in main and calls on system to call onto grapher to draw and plot the graph
    Animate();
    void processEvents();
    void run();
    void update();
    void render();
    void draw();
    void setEquation();

private:
    sf::RenderWindow window;
    System system;
    string equation;
    double num1, num2;
    int command;
};

#endif // ANIMATE_H
