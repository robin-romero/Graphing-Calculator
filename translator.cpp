#include "translator.h"
#include "screensize.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Translator::Translator()
{

}

//does the translation from plotter x and y values to the screen x and y values
//basically calculates the ratio needed to draw the new plot on the screen
//was told calculations was wrong but this is as good as i was able to get for plots
//to show on the screen
VectorC<sf::Vector2f> Translator::Translate(Queue<Tokenizer *> main, float start, float end)
{
    vect = plot.PreGraph(main, start, end);

    for(float i = 0; i <= vect.Size(); i++)
    {
        translate[i].x = (SCREEN_WIDTH * 0.1) * vect[i].x + SCREEN_WIDTH / 2;
        translate[i].y = SCREEN_HEIGHT / 2 - (SCREEN_HEIGHT * 0.1) * vect[i].y;
    }
    return translate;
}
