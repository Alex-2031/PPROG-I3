#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

/**
* @brief Estructura que contiene los datos del jugador: id, nombre, localización y objeto
*
* @param id id del jugador
* @param name cadena de caracteres con el nombre del jugador 
* @param location id del espacio en el que se encuentra el jugador
* @param object id del objeto que carga el jugador
* 
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*/
struct _Player
{
	Id id;
	char name[WORD_SIZE + 1];
	Id location;
	Id object;
};

Player *player_create(Id id)
{

	Player *newPlayer = NULL;

	if (id == NO_ID)
		return NULL;

	newPlayer = (Player *)malloc(sizeof(Player));

	if (newPlayer == NULL)
	{
		return NULL;
	}

	newPlayer->id = id;

	newPlayer->name[0] = '\0';

	newPlayer->location = NO_ID;

	newPlayer->object = NO_ID;

	return newPlayer;
}

STATUS player_destroy(Player *player)
{
	if (!player)
	{
		return ERROR;
	}

	free(player);
	player = NULL;

	return OK;
}

Id player_get_id(Player *player)
{
	if (!player)
	{
		return NO_ID;
	}

	return player->id;
}

STATUS player_set_id(Player *player, Id id)
{
	if (!player)
	{
		return ERROR;
	}

	player->id = id;

	return OK;
}

STATUS player_set_name(Player *player, char *name)
{
	if (!player || !name)
	{
		return ERROR;
	}

	if (!strcpy(player->name, name))
	{
		return ERROR;
	}

	return OK;
}

const char *player_get_name(Player *player)
{
	if (!player)
	{
		return NULL;
	}

	return player->name;
}

STATUS player_set_location(Player *player, Id location)
{
	if (!player)
	{
		return ERROR;
	}

	player->location = location;

	return OK;
}

Id player_get_location(Player *player)
{
	if (!player)
	{
		return NO_ID;
	}

	return player->location;
}

STATUS player_set_object(Player *player, Id id)
{
	if (!player)
	{
		return ERROR;
	}

	player->object = id;

	return OK;
}

Id player_get_object(Player *player)
{
	if (!player)
	{
		return NO_ID;
	}

	return player->object;
}

STATUS player_print(Player *player)
{
	if (!player)
	{
		return ERROR;
	}

	fprintf(stdout, "--> Plyer (Id: %ld; Name: %s; location: %ld; object: %ld)\n", player->id, player->name, player->location, player->object);

	return OK;
}
