#include "Tile.hpp"

Tile::Tile(int pos_x, int pos_y)
{
	m_position_x     = pos_x;
	m_position_y     = pos_y;
	m_collision_type = 0;
}

Tile::Tile()
{

}


// Tile::Tile(sf::Texture text,int pos_x, int pos_y)
// {
// 	m_tile_texture   = text;
// 	m_position_x     = pos_x;
// 	m_position_y     = pos_y;
// 	m_collision_type = 0;
// }


void Tile::setTexture(const char* filename)
{
	sf::Texture text;
	text.loadFromFile(filename);
	m_tile_texture = text;
}

void Tile::setSprite(int map_pos_x, int map_pos_y,  
					 int texture_offset_x, int texture_offset_y)
{
	sf::Sprite sprite;
	sprite.setTexture(m_tile_texture);
	sprite.setTextureRect( sf::IntRect( texture_offset_x*TILE_SIZE,
										texture_offset_y*TILE_SIZE,
										TILE_SIZE,
										TILE_SIZE) );
	sprite.setPosition( map_pos_x,map_pos_y );
	m_sprite = sprite;
}

void Tile::drawTile(sf::RenderWindow & window_to_draw)
{
	window_to_draw.draw(m_sprite);
}

sf::Sprite Tile::getSprite()
{
	return m_sprite;
}


Tile::~Tile()
{

}