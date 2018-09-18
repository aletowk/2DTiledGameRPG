#include "Map.hpp"

Map::Map(){

}

Map::Map(unsigned int map_height, unsigned int map_width,unsigned int tile_size)
{
	m_map_width = map_width;
	m_map_height = map_height;
	m_tile_size = tile_size;
}

Map::~Map()
{
}

void Map::setMapTile(const char* tileset_filename)
{
	int i = 0;
	int x_offset_in_pix=0;
	int y_offset_in_pix=0;

	for(i = 0; i < m_map_height*m_map_width; i++){
		printf("Loading map %s %d / %d\n",tileset_filename,i,m_map_width*m_map_height);
		m_tile_array[i].setTexture(tileset_filename);

		x_offset_in_pix = (int) m_tile_array_index[i]%(m_tile_array[i].getTexture().getSize().x / (m_tile_size));
		y_offset_in_pix = (int) m_tile_array_index[i]/(m_tile_array[i].getTexture().getSize().y / (m_tile_size));
		
		if(m_tile_array_index[i] == -1){
			m_tile_array[i].setSprite(0,0,0,0);
		}else{
			m_tile_array[i].setSprite(	(i%m_map_height)*m_tile_size,
										(i/m_map_width)*m_tile_size,
										x_offset_in_pix,
										y_offset_in_pix);
		}
	}	
}

void Map::drawMap_sprite(sf::RenderWindow & window_to_draw,const char* tileset_filename)
{
	sf::Texture texture;
	sf::Sprite  main_sprite;

	unsigned int i      = 0;
	unsigned int j      = 0;
	int x_offset_in_pix = 0;
	int y_offset_in_pix = 0;


	texture.loadFromFile(tileset_filename);
	main_sprite.setTexture(texture);
	// printf("\n==========\n");
	
	// for( i = 0; i  < m_map_width ;i++){

	// 	for(j = 0 ; j < m_map_height; j ++){

	// 		if(m_tile_array_index[i+j*m_map_width] == -1){
	// 			main_sprite.setTextureRect( sf::IntRect( 0*m_tile_size,
	// 									0*m_tile_size,
	// 									0,
	// 									0) );
	// 			main_sprite.setPosition(0,0);
	// 		}else{
	// 			x_offset_in_pix = (int) m_tile_array_index[i+j*m_map_width]%(texture.getSize().x / (m_tile_size));
	// 			y_offset_in_pix = (int) m_tile_array_index[i+j*m_map_width]/(texture.getSize().y / (m_tile_size));


	// 		// if( y_offset_in_pix > 500){
	// 		// 	printf("\n\nExceed in %d\n\n",m_tile_array_index[i]);
	// 		// 	printf("\n\nExceed in %d,%d\n\n",(texture.getSize().x )/m_tile_size,(texture.getSize().y)/m_tile_size);
	// 		// 	printf("\n\nExceed in %d,%d\n\n",(i%m_map_width),(i/m_map_height));
	// 		// }


	// 			main_sprite.setTextureRect( sf::IntRect( 	(x_offset_in_pix)*(m_tile_size),
	// 													 	(y_offset_in_pix-1)*(m_tile_size),
	// 														m_tile_size,
	// 														m_tile_size) );

	// 			// printf("\npos %d,%d\n",(i%m_map_width),(i/m_map_height));
	// 			main_sprite.setPosition( i*(m_tile_size),j*(m_tile_size) );
	// 		}
	// 		// if(i % m_map_width == 0 )
	// 		// 	printf("--\n");
	// 		// printf("%d,%d \n",x_offset_in_pix,y_offset_in_pix);
	// 		window_to_draw.draw(main_sprite);


			
	// 	}

	// }


	


	for( i = 0 ; i  < m_map_width*m_map_height ; i++)
	{
		

		if(m_tile_array_index[i] == -1){
			main_sprite.setTextureRect( sf::IntRect( 0*m_tile_size,
										0*m_tile_size,
										0,
										0) );
			main_sprite.setPosition(0,0);
		}else{
			x_offset_in_pix = (int) m_tile_array_index[i]%(texture.getSize().x / (m_tile_size));
			y_offset_in_pix = (int) m_tile_array_index[i]/(texture.getSize().y / (m_tile_size));


			// if( y_offset_in_pix > 500){
			// 	printf("\n\nExceed in %d\n\n",m_tile_array_index[i]);
			// 	printf("\n\nExceed in %d,%d\n\n",(texture.getSize().x )/m_tile_size,(texture.getSize().y)/m_tile_size);
			// 	printf("\n\nExceed in %d,%d\n\n",(i%m_map_width),(i/m_map_height));
			// }


			main_sprite.setTextureRect( sf::IntRect( (x_offset_in_pix)*(m_tile_size),
										(y_offset_in_pix)*(m_tile_size),
										m_tile_size,
										m_tile_size) );
				printf("\npos %d,%d\n",(i%m_map_width),(i/m_map_height));
			main_sprite.setPosition( (i%(m_map_width))*(m_tile_size),(i/(m_map_height))*(m_tile_size) );
		}
		if(i % m_map_width == 0 )
			printf("--\n");
		printf("%d,%d \n",x_offset_in_pix,y_offset_in_pix);
		window_to_draw.draw(main_sprite);
	}

}

void Map::drawMap( sf::RenderWindow & window_to_draw)
{
	int i = 0;

	for(i = 0 ; i  < m_map_height*m_map_width ; i++)
		m_tile_array[i].drawTile(window_to_draw);
}

void Map::setMapIndex( const char* map_filename)
{
	FILE* map_file;
	int i = 0, j = 0;
	// char current_str[4*map_width];
	char* current_str =(char*) malloc(sizeof(char)*5*m_map_width);
	char* to_free;
	char* tok;
	char* end;
	Tile* tile;

	// printf("Malloc : %d\n\r",sizeof(char)*4*m_map_width);


	map_file = fopen(map_filename,"r");
	if(map_file == NULL)
		fprintf(stderr, "Can not open Map : \"%s\"\n",map_filename );

	do{
		fgets(current_str,4*m_map_width,map_file);
		// printf("%s",current_str);
		
		to_free = strdup(current_str);
		tok = to_free;
		end = to_free;
		while(tok != NULL){
			strsep(&end, ",");
			// puts(tok);
			m_tile_array_index.push_back( atoi(tok));
			tile = new Tile(m_tile_size);
			m_tile_array.push_back(*tile);
			tok = end;
			j++;
			
		}		
		i++;
	}while( i < m_map_height );
	free(tok);
	free(end);
	free(to_free);
	fclose(map_file);
}