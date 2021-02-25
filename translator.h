#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include "plotter.h"
#include "queue.h"
#include "vectorc.h"

class Translator
{
public:
    //translates the plotter x and y values to fit the sfml screen
    Translator();
    VectorC<sf::Vector2f> Translate(Queue<Tokenizer*> main, float start, float end);
private:
    Plotter plot;
    VectorC<sf::Vector2f> vect;
    VectorC<sf::Vector2f> translate;
};

#endif // TRANSLATOR_H
