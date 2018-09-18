#ifndef MAP_HPP
#define MAP_HPP 

#include "Tile.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

#include <vector>

class Map
{
public:
	Map();
	Map(unsigned int map_height, unsigned int map_width,unsigned int tile_size);
	~Map();

	void setMapIndex( const char* map_filename, const char * map_texture_filename);

	void drawMap_sprite(sf::RenderWindow & window_to_draw);



private:
	unsigned int 		m_map_width;
	unsigned int 		m_map_height;
	unsigned int  		m_tile_size;
	sf::Texture 		m_map_texture;
	sf::Sprite 			m_map_sprite;
	std::vector<int> 	m_tile_array_index;
};


#endif