#include "system.h"
#include "screensize.h"
#include <iostream>

using namespace std;

//just calls into graph to do the work for it(system is a lazy bum)
System::System()
{

}
//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command)
{
    graph.step(command);
}

void System::Draw(sf::RenderWindow& window)
{
    graph.draw(window);
}

void System::setEquation(string equation)
{
    graph.setEquation(equation);
}
