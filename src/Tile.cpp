#include "Tile.hpp"

Tile::Tile()
{

}

Tile::Tile(unsigned char tile_size,int pos_x, int pos_y)
{
	m_tile_size = tile_size;
	m_position_x     = pos_x;
	m_position_y     = pos_y;
	m_collision_type = 0;
}

Tile::Tile(unsigned char tile_size)
{
	m_tile_size = tile_size;
}

sf::Texture Tile::getTexture()
{
	return m_tile_texture;
}

void Tile::setTexture(const char* filename)
{
	sf::Texture text;
	bool load_texture;
	load_texture = text.loadFromFile(filename);
	if(!load_texture)
		printf("Error: can not laod texture %s\n",filename);
	m_tile_texture = text;
}

void Tile::setSprite(int map_pos_x, int map_pos_y,  
					 int texture_offset_x, int texture_offset_y)
{
	sf::Sprite sprite;
	sprite.setTexture(m_tile_texture);
	sprite.setTextureRect( sf::IntRect( texture_offset_x*m_tile_size,
										texture_offset_y*m_tile_size,
										m_tile_size,
										m_tile_size) );
	// printf("Texture Rect :: %d %d %d %d\n",texture_offset_x*m_tile_size,texture_offset_y*m_tile_size,m_tile_size,m_tile_size);
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