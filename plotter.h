#ifndef PLOTTER_H
#define PLOTTER_H
#include "rpn.h"
#include "queue.h"
#include "tokenizer.h"
#include "syard.h"
#include "integer.h"
#include <SFML/Graphics.hpp>
#include "vectorc.h"

class Plotter
{
public:
    //uses the shunting yard and rpn to calculate pretranslated graph points
    Plotter();
    VectorC<sf::Vector2f> PreGraph(Queue<Tokenizer*> main, float begin, float end);

private:
    RPN rpn;
    Queue<Tokenizer*> hold;
    SYard yard;
    VectorC<sf::Vector2f> preChart;
};

#endif // PLOTTER_H
