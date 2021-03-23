#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

#define PLA_ID1 0
#define DIE_ID1 0
#define MAX_DIE 6
#define MIN_DIE 1

typedef void (*callback_fn)(Game *game);

/**
   List of callbacks for each command in the game 
*/
void game_callback_unknown(Game *game);
void game_callback_exit(Game *game);
void game_callback_next(Game *game);
void game_callback_back(Game *game);
void game_callback_take(Game *game);
void game_callback_drop(Game *game);
void game_callback_left(Game *game);
void game_callback_right(Game *game);
void game_callback_left(Game *game);
void game_callback_roll(Game *game);

static callback_fn game_callback_fn_list[N_CALLBACK] = {
	game_callback_unknown,
	game_callback_exit,
	game_callback_next,
	game_callback_back,
	game_callback_take,
	game_callback_drop,
	game_callback_left,
	game_callback_right,
	game_callback_roll};

/**
   Game interface implementation
*/

STATUS game_create(Game *game)
{
	int i;

	for (i = 0; i < MAX_SPACES; i++)
	{
		game->spaces[i] = NULL;
	}

	for (i = 0; i < MAX_OBJECTS; i++)
	{
		game->objects[i] = NULL;
	}

	game->die = die_create(DIE_ID1, MAX_DIE, MIN_DIE);
	game->player = player_create(PLA_ID1);
	game->last_cmd = NO_CMD;

	return OK;
}

STATUS game_destroy(Game *game)
{
	int i = 0;

	for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++)
	{
		space_destroy(game->spaces[i]);
	}

	for (i = 0; (i < MAX_OBJECTS) && (game->objects[i] != NULL); i++)
	{
		object_destroy(game->objects[i]);
	}

	if (player_destroy(game->player) == ERROR)
		return ERROR;

	if (die_destroy(game->die) == ERROR)
		return ERROR;

	return OK;
}

STATUS game_add_object(Game *game, Object *object)
{
	int i = 0;

	if (!game || !object)
	{
		return ERROR;
	}

	while ((i < MAX_OBJECTS) && (game->objects[i] != NULL))
	{
		i++;
	}

	if (i >= MAX_SPACES)
	{
		return ERROR;
	}

	game->objects[i] = object;

	return OK;
}

STATUS game_add_space(Game *game, Space *space)
{
	int i = 0;

	if (space == NULL)
	{
		return ERROR;
	}

	while ((i < MAX_SPACES) && (game->spaces[i] != NULL))
	{
		i++;
	}

	if (i >= MAX_SPACES)
	{
		return ERROR;
	}

	game->spaces[i] = space;

	return OK;
}

Id game_get_space_id_at(Game *game, int position)
{

	if (position < 0 || position >= MAX_SPACES)
	{
		return NO_ID;
	}

	return space_get_id(game->spaces[position]);
}

Space *game_get_space(Game *game, Id id)
{
	int i = 0;

	if (id == NO_ID)
	{
		return NULL;
	}

	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
	{
		if (id == space_get_id(game->spaces[i]))
		{
			return game->spaces[i];
		}
	}

	return NULL;
}

STATUS game_set_player_location(Game *game, Id id)
{

	if (id == NO_ID)
	{
		return ERROR;
	}

	if (player_set_location(game->player, id) == ERROR)
		return ERROR;

	return OK;
}

STATUS game_set_object_location(Game *game, Id id, Id object)
{

	if (id == NO_ID)
		return ERROR;

	int i = 0;

	for (i = 0; (space_get_id(game->spaces[i]) != id); i++)
		;

	space_set_object(game->spaces[i], object);

	return OK;
}

Id game_get_player_location(Game *game)
{
	return player_get_location(game->player);
}

Id game_get_object_location(Game *game, Id id)
{
	int i = 0;
	BOOL st = FALSE;

	for (i = 0; i < MAX_SPACES && st == FALSE; i++)
	{
		st = space_has_object(game->spaces[i], id);
	}

	if (st == FALSE)
		return -1;

	return space_get_id(game->spaces[i - 1]);
}

int game_get_last_die(Game *game)
{
	if (!game)
		return 0;

	return die_get_last_num(game->die);
}

STATUS game_update(Game *game, T_Command cmd)
{
	game->last_cmd = cmd;
	(*game_callback_fn_list[cmd])(game);
	return OK;
}

T_Command game_get_last_command(Game *game)
{
	return game->last_cmd;
}

void game_print_data(Game *game)
{
	int i = 0;

	printf("\n\n-------------\n\n");

	printf("=> Spaces: \n");
	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
	{
		space_print(game->spaces[i]);
	}

	//printf("=> Object location: %d\n", (int)game_get_object_location(game));
	printf("=> Player location: %d\n", (int)game_get_player_location(game));
	printf("prompt:> ");
}


char *game_print_object_location(Game *game) {
  int i;
  char *objects = NULL, num_to_char[4] = "";
  Id obj_loc = NO_ID;
  Object *current_obj = NULL;

  objects = (char *) calloc(sizeof(char), WORD_SIZE +1);
  if (objects == NULL) {
    return NULL;
  }

  strcpy(objects, "  ");

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    current_obj = game->objects[i];
    obj_loc = game_get_object_location(game, object_get_id(current_obj));
    if (obj_loc != NO_ID) {
      strcat(objects, "O");
      sprintf(num_to_char, "%ld", object_get_id(current_obj));
      strcat(objects, num_to_char);
      strcat(objects, ":");
      sprintf(num_to_char, "%ld", obj_loc);
      strcat(objects, num_to_char);
      strcat(objects, " ");
    }
  }

  return objects;
}


BOOL game_is_over(Game *game)
{
	return FALSE;
}

/**
   Callbacks implementation for each action 
*/

void game_callback_unknown(Game *game)
{
	game->last_cmd_st = ERROR;
}

void game_callback_exit(Game *game)
{
	game->last_cmd_st = OK;
}

void game_callback_next(Game *game)
{
	int i = 0;
	Id current_id = NO_ID;
	Id space_id = NO_ID;

	space_id = game_get_player_location(game);
	if (space_id == NO_ID)
	{
		game->last_cmd_st = ERROR;
		return;
	}

	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
	{
		current_id = space_get_id(game->spaces[i]);

		if (current_id == space_id)
		{

			current_id = space_get_south(game->spaces[i]);

			if (current_id != NO_ID)
			{
				game_set_player_location(game, current_id);
				game->last_cmd_st = OK;
				return;
			}

			game->last_cmd_st = ERROR;
			return;
		}
	}
}

void game_callback_back(Game *game)
{
	int i = 0;
	Id current_id = NO_ID;
	Id space_id = NO_ID;

	space_id = game_get_player_location(game);

	if (NO_ID == space_id)
	{
		game->last_cmd_st = ERROR;
		return;
	}

	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
	{
		current_id = space_get_id(game->spaces[i]);
		if (current_id == space_id)
		{
			current_id = space_get_north(game->spaces[i]);

			if (current_id != NO_ID)
			{
				game_set_player_location(game, current_id);
				game->last_cmd_st = OK;
				return;
			}
			game->last_cmd_st = ERROR;
			return;
		}
	}
}

void game_callback_take(Game *game)
{
	Id current_player_object;
	Id current_space;
	Id selected_object;
	int num;
	STATUS aux;
	extern Id take_option;

	if (game == NULL)
	{
		game->last_cmd_st = ERROR;
		return;
	}

	current_space = game_get_player_location(game); //Obtener la casilla del jugador

	num = space_get_number_of_objects(game_get_space(game, current_space));
	if (num == 0)
	{ //Comprobar que el espacio tiene un objeto como mínimo
		game->last_cmd_st = ERROR;
		return;
	}
	selected_object = take_option; //Comprobar si el objeto seleccionado es válido
	if (selected_object == -1)
	{
		game->last_cmd_st = ERROR;
		return;
	}
	aux = space_has_object(game_get_space(game, current_space), selected_object); //Comprobar si el espacio tiene el objeto
	if (aux == ERROR)
	{
		game->last_cmd_st = ERROR;
		return;
	}
	current_player_object = player_get_object(game->player); //Comprobar que el jugador no tiene ningún objeto
	if (current_player_object != NO_ID)
	{
		game->last_cmd_st = ERROR;
		return;
	}
	player_set_object(game->player, selected_object); //Intercambiar el id del objeto del espacio al del jugador

	space_delete_object(game_get_space(game, current_space), selected_object); //Eliminar el objeto del espacio

	game->last_cmd_st = OK;
	return;
}

void game_callback_drop(Game *game)
{
	Id current_player_object;
	Id current_space;

	if (game == NULL)
	{
		game->last_cmd_st = ERROR;
		return;
	}
	current_space = game_get_player_location(game); //Obtener la casilla del jugador

	current_player_object = player_get_object(game->player); //Comprobar si el jugador tiene un objeto
	if (current_player_object == NO_ID)
	{
		game->last_cmd_st = ERROR;
		return;
	}
	current_player_object = player_get_object(game->player); //Obtiene el objeto del jugador

	player_set_object(game->player, NO_ID); //Quita el objeto del jugador

	space_set_object(game_get_space(game, current_space), current_player_object); //Añade el objeto al espacio

	game->last_cmd_st = OK;

	return;
}

void game_callback_right(Game *game)
{
	Id east_space_id;
	Id current_space;
	if (game == NULL)
		return;

	current_space = game_get_player_location(game); //Obtener la casilla del jugador

	if (space_get_east(game_get_space(game, current_space)) == -1)
	{ //Comprobar que el espacio actual esta enlazado por el este con otro espacio
		game->last_cmd_st = ERROR;
		return;
	}
	east_space_id = space_get_east(game_get_space(game, current_space)); //Obtener la id del espacio enlazado por el este

	game_set_player_location(game, east_space_id); //Cambiar la localización del jugador a la casilla enlazada
	game->last_cmd_st = OK;
	return;
}

void game_callback_left(Game *game)
{
	Id east_space_id;
	Id current_space;
	if (game == NULL)
		return;

	current_space = game_get_player_location(game); //Obtener la casilla del jugador

	if (space_get_west(game_get_space(game, current_space)) == -1)
	{ //Comprobar que el espacio actual esta enlazado por el oeste con otro espacio
		game->last_cmd_st = ERROR;
		return;
	}
	east_space_id = space_get_west(game_get_space(game, current_space)); //Obtener la id del espacio enlazado por el oeste

	game_set_player_location(game, east_space_id); //Cambiar la localización del jugador a la casilla enlazada
	game->last_cmd_st = OK;
	return;
}

void game_callback_roll(Game *game)
{
	if (game == NULL)
	{
		game->last_cmd_st = ERROR;
		return;
	}
	die_roll(game->die);
	game->last_cmd_st = OK;
	return;
}

STATUS game_get_last_command_st(Game *game)
{
	if (!game)
		return ERROR;

	return game->last_cmd_st;
}