#include "coord.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#define RADIUS 1.0 
#define EP 15.0

void fractal(sf::CircleShape &p1, sf::CircleShape &p2, sf::RenderWindow* win);
sf::CircleShape create_point(float radius, sf::Vector2f pos);

int main()
{
    // create a window
    sf::RenderWindow window(sf::VideoMode(1150, 700), 
            "My Window Title");

    window.clear();

    /*
    sf::RenderTexture renderTexture;
    renderTexture.create(1000, 700);
    renderTexture.clear();
    */


    sf::CircleShape p1(RADIUS);
    p1.setOrigin(RADIUS, RADIUS);
    p1.setPosition(25, 400);
    p1.setFillColor(sf::Color::Red);

    sf::CircleShape p2(RADIUS);
    p2.setOrigin(RADIUS, RADIUS);
    p2.setPosition(1125, 400);
    p2.setFillColor(sf::Color::Red);


    window.draw(p1);
    window.draw(p2);

    fractal(p1, p2, &window);





    /*
    const sf::Texture& texture = renderTexture.getTexture();
    sf::Sprite sprite(texture);
    window.draw(sprite);
    */

    window.display();


    // main game loop
    while (window.isOpen())
    {
        // Events... loop through all the events
        sf::Event event;

        while (window.pollEvent(event))
        {
            // if user closes the window... close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

    }

    return EXIT_SUCCESS;
}

void fractal(sf::CircleShape &p1, 
        sf::CircleShape &p5, 
        sf::RenderWindow * window)
{
    if (dist(p1.getPosition(), p5.getPosition()) >= EP)
    {
        sf::CircleShape p2 = create_point(
                RADIUS,
                onethird(p1.getPosition(), p5.getPosition())
                );

        sf::CircleShape p4 = create_point (
                RADIUS,
                twothirds(p1.getPosition(), p5.getPosition())
                );

        sf::CircleShape p3 = create_point(
                RADIUS,
                rotate(p2.getPosition(), p1.getPosition(), 120.0)
                );

        window->draw(p2);
        window->draw(p3);
        window->draw(p4);

        fractal(p1,p2, window);
        fractal(p2,p3, window);
        fractal(p3,p4, window);
        fractal(p4,p5, window);
    }
    return;
}

sf::CircleShape create_point(float radius, sf::Vector2f pos)
{
    sf::CircleShape point(radius);
    point.setOrigin(radius, radius);
    point.setPosition(pos);
    return point;
}
