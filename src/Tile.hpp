#ifndef TILE_HPP_
#define TILE_HPP_

#include <SFML/Graphics.hpp>

#define TILE_SIZE	32
#define TILESET_LENGTH_ELEMENTS	16
#define TILESET_WIDTH_ELEMENTS	16
#define TILESET_LENGTH	512
#define TILESET_WIDTH 	512

class Tile
{
public:
	Tile();
	Tile(int pos_x, int pos_y);
	// Tile(sf::Texture text,int pos_x, int pos_y);
	~Tile();
	void setTexture(const char* filename);

	void setSprite(	int map_pos_x, int map_pos_y,  
					int texture_offset_x, int texture_offset_y);

	void setPosition();
	void drawTile(sf::RenderWindow & window_to_draw);
	sf::Sprite getSprite();

private:
	sf::Texture   	m_tile_texture;
	sf::Sprite 		m_sprite;

	int 	m_position_x;
	int 	m_position_y;

	int m_collision_type;

	
};

#endif