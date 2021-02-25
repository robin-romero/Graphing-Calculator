#ifndef GRAPHER_H
#define GRAPHER_H
#include <SFML/Graphics.hpp>
#include "translator.h"
#include "queue.h"
#include "vectorc.h"
#include "tokenizer.h"

class Grapher
{
public:
    //Plots the graph of the new x and y values used in the translator
    Grapher();
    Queue<Tokenizer*> convert(string input);
    void draw(sf::RenderWindow& window);
    void step(int command);
    void setEquation(string equation);
private:
    sf::RectangleShape rectangle;
    sf::RectangleShape rectangle2;
    sf::CircleShape circle;
    VectorC<sf::Vector2f> vect;
    Queue<Tokenizer*> que;
    Translator trans;
    Tokenizer token;
    string express = "+-*/^";
    int domain;
    int last;
};

#endif // GRAPHER_H
