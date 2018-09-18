#include "Map.hpp"

Map::Map(){

}

Map::Map(unsigned int map_height, unsigned int map_width,unsigned int tile_size)
{
	m_map_width = map_width;
	m_map_height = map_height;
	m_tile_size = tile_size;
	m_tile_array_index.clear();
}

Map::~Map()
{
}


void Map::drawMap_sprite(sf::RenderWindow & window_to_draw)
{

	unsigned int i      = 0;
	unsigned int j      = 0;
	int x_offset_in_pix = 0;
	int y_offset_in_pix = 0;

	for( i = 0 ; i  < m_map_width*(m_map_height) ; i++)
	{
		

		if(m_tile_array_index[i] == -1){
			m_map_sprite.setTextureRect( sf::IntRect( 0*m_tile_size,
										0*m_tile_size,
										0,
										0) );
			m_map_sprite.setPosition(0,0);
		}else{
			x_offset_in_pix = (int) m_tile_array_index[i]%(m_map_texture.getSize().x / (m_tile_size));
			y_offset_in_pix = (int) m_tile_array_index[i]/(m_map_texture.getSize().y / (m_tile_size));


			m_map_sprite.setTextureRect( sf::IntRect( (x_offset_in_pix)*(m_tile_size),
										(y_offset_in_pix)*(m_tile_size),
										m_tile_size,
										m_tile_size) );
				// printf("\npos %d,%d\n",(i%m_map_width),(i/m_map_height));
			m_map_sprite.setPosition( (i%(m_map_width))*(m_tile_size),(i/(m_map_height))*(m_tile_size) );
		}

		window_to_draw.draw(m_map_sprite);
	}

}

void Map::setMapIndex( const char* map_filename, const char * map_texture_filename)
{
	FILE* map_file;
	int i = 0, j = 0;
	char* current_str;
	char* to_free;
	char* tok;
	char* end;
	bool  open_texture_file;

	open_texture_file = m_map_texture.loadFromFile(map_texture_filename);
	if(!open_texture_file)
		printf("ERROR Can not open texure file %s\n",map_texture_filename);

	m_map_sprite.setTexture(m_map_texture);

	printf("Texture Dim : %d,%d\n\n",m_map_texture.getSize().x,m_map_texture.getSize().y);

	current_str = (char*) malloc(sizeof(char)*5*m_map_texture.getSize().x);

	map_file = fopen(map_filename,"r");
	if(map_file == NULL)
		fprintf(stderr, "Can not open Map : \"%s\"\n",map_filename );

	do{
		fgets(current_str,5*m_map_texture.getSize().x,map_file);
		printf("Srting :: %s",current_str);
		
		to_free = strdup(current_str);
		tok = to_free;
		end = to_free;
		while(tok != NULL){
			strsep(&end, ",");
			// printf("Toks :: ");
			// puts(tok);
			m_tile_array_index.push_back( atoi(tok));
			tok = end;
			j++;
			
		}
		i++;
	}while( i < m_map_height );
	printf("\n\n");

	for(i = 0; i < m_tile_array_index.size() ; i++ ){
		if(i%m_map_width == 0)
			printf("\n");
		printf("%d  ", m_tile_array_index[i] );
	}

	free(current_str);
	free(tok);
	free(end);
	free(to_free);
	fclose(map_file);
}