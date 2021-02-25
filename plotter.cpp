#include "plotter.h"
#include <iostream>

using namespace std;

Plotter::Plotter()
{
}

VectorC<sf::Vector2f> Plotter::PreGraph(Queue<Tokenizer *> main, float begin, float end)
{
    //takes in queue and sends prefix queue into shunting yard to convert into
    //a postfix queue for Rpn to be able to calculate
    //returns x and y values of the rpn preConverted graph
    hold = yard.PostFix(main);

    float first = 0;

    for(float i = begin; i <= end; i+=.05)
    {
        preChart[first].x = i;
        preChart[first].y = rpn.evaluation(hold, i);
        first++;
    }
    return preChart;
}
