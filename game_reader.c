#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"

STATUS game_reader_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char cad1[INC2 + 1] = "", cad2[INC2 + 1] = "", cad3[INC2 + 1] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  int i;
  
  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  
  while (fgets(line, WORD_SIZE, file)) {
    for (i = 0; i < INC2; i++) {
      cad1[i] = ' ';
      cad2[i] = ' ';
      cad3[i] = ' ';
    }

    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      if (toks != NULL) {
        strcpy(cad1, toks);      
        toks = strtok(NULL, "|");
        strcpy(cad2, toks);
        toks = strtok(NULL, "|");
        strcpy(cad3, toks);
      }
#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%s|%s|%s|\n", id, name, north, east, south, west, cad1, cad2, cad3);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_add_space(game, space);
        space_set_gdesc(space, cad1, 0);
        space_set_gdesc(space, cad2, 1);
        space_set_gdesc(space, cad3, 2);
      }
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}

STATUS game_reader_load_objects(Game *game, char *filename)
{
	FILE *file = NULL;
	char line[WORD_SIZE] = "";
	char name[WORD_SIZE] = "";
	char *toks = NULL;
	Id id = NO_ID, position = NO_ID;
	Object *object = NULL;
	STATUS status = OK;

	if (!filename || !game)
	{
		return ERROR;
	}

	file = fopen(filename, "r");
	if (file == NULL)
	{
		return ERROR;
	}

	while (fgets(line, WORD_SIZE, file))
	{
		if (strncmp("#o:", line, 3) == 0)
		{
			toks = strtok(line + 3, "|");
			id = atol(toks);
			toks = strtok(NULL, "|");
			strcpy(name, toks);
			toks = strtok(NULL, "|");
			position = atol(toks);

#ifdef DEBUG
			printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
			object = object_create(id);
			if (object != NULL)
			{
				object_set_name(object, name);
				space_set_object(game_get_space(game, position), object_get_id(object));
				game_add_object(game, object);
			}
		}
	}

	if (ferror(file))
	{
		status = ERROR;
	}

	fclose(file);

	return status;
}

STATUS game_reader_create_from_file(Game *game, char *filename)
{
	game->last_cmd_st = OK;

	if (game_create(game) == ERROR)
		return ERROR;

	if (game_reader_load_spaces(game, filename) == ERROR)
		return ERROR;

	if (game_reader_load_objects(game, filename) == ERROR)
		return ERROR;

	game_set_player_location(game, game_get_space_id_at(game, 0));
	game_set_object_location(game, 1, 0);

	return OK;
}
