#include "Map.hpp"

Map::Map()
{

}

Map::~Map()
{

}

void Map::setMapTile(const char* tileset_filename)
{
	int i = 0;
	int x_offset_in_pix=0;
	int y_offset_in_pix=0;

	for(i = 0; i < MAP_LENGTH*MAP_WIDTH; i++){

		m_tile_array[i].setTexture(tileset_filename);

		x_offset_in_pix = (int) m_tile_array_index[i]%TILESET_LENGTH_ELEMENTS;
		y_offset_in_pix = m_tile_array_index[i]/TILESET_WIDTH_ELEMENTS;
		// printf("== x off: %d   x off : %d \n",x_offset_in_pix,y_offset_in_pix );
		m_tile_array[i].setSprite(	((int) i%MAP_LENGTH)*TILE_SIZE,
									 (i/MAP_WIDTH)*TILE_SIZE,
									x_offset_in_pix,
									y_offset_in_pix);

	}	
}

void Map::drawMap( sf::RenderWindow & window_to_draw)
{
	int i = 0;

	for(i = 0 ; i  < MAP_LENGTH*MAP_WIDTH ; i++)
		m_tile_array[i].drawTile(window_to_draw);
}

void Map::setMapIndex( const char* map_filename )
{
	FILE* map_file;
	int i = 0, j = 0;
	char current_str[4*MAP_LENGTH];
	char* to_free;
	char* tok;
	char* end;


	map_file = fopen(map_filename,"r");
	if(map_file == NULL)
		fprintf(stderr, "Can not open Map : \"%s\"\n",map_filename );

	do{
		fgets(current_str,sizeof(current_str),map_file);
		printf("%s",current_str);
		to_free = strdup(current_str);
		tok = to_free;
		end = to_free;
		while(tok != NULL){
			strsep(&end, ",");
			// puts(tok);
			m_tile_array_index[j] = atoi(tok);
			tok = end;
			
			j++;
		}		
		i++;
	}while( i < MAP_WIDTH );

	// for(i = 0 ; i  < MAP_WIDTH*MAP_LENGTH; i++){
	// 	if(i%MAP_LENGTH == 0)
	// 		printf("\n");
	// 	printf("%d  ",m_tile_array_index[i]);
	// }



	free(tok);
	free(end);
	free(to_free);
	fclose(map_file);
}