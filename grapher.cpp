#include "grapher.h"
#include "screensize.h"
#include <iostream>
#include <algorithm>

using namespace std;

Grapher::Grapher()
{
    //create graph and draw x and y axis
    //plot points into the graph
    //takes in the user input from animate class and updates draw function
    //to draw new equation
    rectangle.setSize(sf::Vector2f(SCREEN_WIDTH * 10, 1));
    rectangle2.setSize(sf::Vector2f(1, SCREEN_HEIGHT * 10));
    rectangle.setOrigin(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y/2));
    rectangle2.setOrigin(sf::Vector2f(rectangle2.getSize().x/2, rectangle2.getSize().y/2));
    rectangle.setPosition(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
    rectangle2.setPosition(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
    rectangle.setFillColor(sf::Color().Red);
    rectangle2.setFillColor(sf::Color().Red);

    circle = sf::CircleShape(1);
    circle.setOrigin(sf::Vector2f(circle.getScale().x/2, circle.getScale().y/2));
    circle.setFillColor(sf::Color().Cyan);
}

Queue<Tokenizer*> Grapher::convert(string input)
{
    Queue<Tokenizer*> translate;
    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    for(int i = 0; i < input.length(); i++)
    {
        if(isalpha(input[i]) && !isalpha(input[i + 1]))
        {
            translate.push(new UnaryOp(input.substr(i ,1)));
        }
        else if(express.find(input[i]) != string::npos)
        {
            if(input[i] == '-' && (i == 0 || express.find(input[i - 1]) != string::npos))
            {
                translate.push(new Integer(-1));
                translate.push(new Operators("*"));
            }
            else
            {
                translate.push(new Operators(input.substr(i, 1)));
            }
        }
        else if(isdigit(input[i]))
        {
            int dig = 0;
            while(isdigit(input[i]) || input[i] == '.') dig++, i++;
            translate.push(new Integer(stod(input.substr(i - dig, dig))));
            if(isalpha(input[i])) translate.push(new Operators("*"));
            i--;
        }
        else if(isalpha(input[i]) && isalpha(input[i + 1]))
        {
            int funct = 0;
            while(isalpha(input[i])) funct++, i++;
            translate.push(new UnaryOp(input.substr(i - funct, funct)));
            i--;
        }
    }
//    cout << "Convert from string to queue: ";
//    cout << "string: " << input << endl;
//    cout << "Converted Queue: " << translate << endl;
    return translate;
}

void Grapher::setEquation(string equation)
{
//    cout << "goes into set equation in grapher" << endl;
    //calls function member convert to convert string input to tokens
    //to go in the specific class(operators, integers, unaryOperators)
    que = convert(equation);
//    cout << "before vect in grapher" << endl;
    vect = trans.Translate(que, -5, 5);
//    cout << "comes out of vect in grapher" << endl;
}

void Grapher::step(int command)
{
}


void Grapher::draw(sf::RenderWindow &window)
{
    //draws the graph
    window.draw(rectangle);
    window.draw(rectangle2);

    for(int i = 0; i < vect.Size(); i++)
    {

        circle.setPosition(sf::Vector2f(vect[i].x, vect[i].y));
        window.draw(circle);
    }
}
