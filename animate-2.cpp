#include "animate.h"
#include "screensize.h"
#include <iostream>
#include "system.h"

using namespace std;

Animate::Animate()
{
    //create window for sfml
    cout << "Animate: TOP" << endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Graphing Calculator");

    window.setFramerateLimit(60);

    cout << "Animate instantiated successfully" << endl;
}

void Animate::processEvents()
{
    //must be able to close window or it crashes without this
    //process event
    sf::Event event;

    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Animate::setEquation()
{
    //take in user input to send to grapher class to convert string
    //into tokens
    cout << "Enter an Equation: " << endl;
    getline(cin, equation);
    system.setEquation(equation);
}

void Animate::draw()
{
    //calls all the way down to grapher to draw the graph
    system.Draw(window);
}

void Animate::update()
{
    system.Step(command);
    command = 0;
}

void Animate::render()
{
    //clears window, draws on window, displays window
    window.clear();
    draw();
    window.display();
}

void Animate::run()
{
    while(window.isOpen())
    {
        //whole window is open run member functions consistently
        processEvents();
        update();
        setEquation();
        render(); //clear, draw, display//
    }

    cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}
