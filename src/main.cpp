/*
 *
 * This project was created to learn how to compute simple animation
 * All theory was learned on the SFML's Github server especially the
 * wiki page into github.
 * We will refer for ::
 * -> https://github.com/SFML/SFML/wiki/Source:-AnimatedSprite
 * -> https://github.com/SFML/SFML/wiki/Sources
 * -> https://github.com/SFML/SFML/wiki/Tutorial%3A-Basic-Game-Engine
 * main.cpp
 *
 *  Created on: 17 juin 2018
 *      Author: alex
 */
#include <SFML/Graphics.hpp>
#include "src/AnimatedSprite.hpp"
#include <iostream>

#include "Map.hpp"

int main()
{
    // setup window
    sf::Vector2i screenDimensions(640,480);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "First 2D Game!");
    window.setFramerateLimit(60);

    // load texture (spritesheet)
    sf::Texture texture;
    if (!texture.loadFromFile("./Tilesets/Animation_char0.png"))
    {
        std::cout << "Failed to load player spritesheet!" << std::endl;
        return 1;
    }


    Map background(15,15,32);
    // Map background_1(50,50,16);
    // Map background_2(50,50,16);
    background.setMapIndex("./Map_Drawing/map15x15_0.csv");
    background.setMapTile("./Tilesets/background_T.png");

    // background_1.setMapIndex("./Map_Drawing/map1_toprint_MainLayer.csv");
    // background_1.setMapTile("./Tilesets/Overworld.png");


    // background_2.setMapIndex("./Map_Drawing/map1_toprint_Houses.csv");
    // background_2.setMapTile("./Tilesets/Overworld.png");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

       
        // draw
        window.clear();
        background.drawMap(window);
        // background_1.drawMap(window);
        // background_2.drawMap(window);

        window.display();
    }

    return 0;
}
