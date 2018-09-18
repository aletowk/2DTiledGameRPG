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

    // 32x32 Tileset
    Map background(15,15,32);
    Map background_1(15,15,32);
    background.setMapIndex("./Map_Drawing/map15x15_0.csv","./Tilesets/background_T.png");
    background_1.setMapIndex("./Map_Drawing/assets2_32x32.csv","./Tilesets/background_T.png");
    
    // 16x16 Tileset
    // Map background_layer(10,10,16);
    // // Map houses_layer(10,10,16);
    // Map assets_layer(10,10,16);
    // // Map trees_layer(10,10,16);


    // background_layer.setMapIndex("./Map_Drawing/MyMap0_BackgroundLayer.csv","./Tilesets/Overworld.png");
    // // houses_layer.setMapIndex("./Map_Drawing/MyMap0_HousesLayer.csv");
    // assets_layer.setMapIndex("./Map_Drawing/MyMap0_AssetsLayer.csv","././Tilesets/Overworld.png");
    // // trees_layer.setMapIndex("./Map_Drawing/MyMap0_TreesLayer1.csv");


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



        // background_layer.drawMap_sprite(window);
        // assets_layer.drawMap_sprite(window);
 

        
        background.drawMap_sprite(window);
        background_1.drawMap_sprite(window);
        
        window.display();
    }

    return 0;
}
