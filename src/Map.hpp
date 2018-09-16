#ifndef MAP_HPP
#define MAP_HPP 

#include "Tile.hpp"
#include <iostream>
#include <cstring>

#define MAP_LENGTH 	15
#define MAP_WIDTH 	15

class Map
{
public:
	Map();
	~Map();

	void setMapIndex(const char* map_filename);

	void setMapTile(const char* tileset_filename);

	void drawMap( sf::RenderWindow & window_to_draw);

private:
	Tile 	m_tile_array[MAP_WIDTH*MAP_LENGTH];
	int 	m_tile_array_index[MAP_WIDTH*MAP_LENGTH];
};

#endif