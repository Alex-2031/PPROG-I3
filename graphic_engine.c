#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "screen.h"
#include "graphic_engine.h"
#include "command.h"

#define MAX_CHAR 64
#define WIDE 11

/**
* @brief Estructura del motor gráfico que define las áreas de la pantalla dedicadas a una tarea concreta
*
* @param map puntero al área del mapa de juego
* @param descript puntero al área de las descripciones del juego
* @param banner puntero al área del letrero del juego
* @param help puntero al área de la ventana de ayuda del jugador
* @param feedback puntero al área de la ventana de feedback al jugador
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*/
struct _Graphic_engine
{
	Area *map, *descript, *banner, *help, *feedback;
};

Graphic_engine *graphic_engine_create()
{
	static Graphic_engine *ge = NULL;

	if (ge)
		return ge;

	screen_init();

	ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));

	if (ge == NULL)
		return NULL;

	ge->map = screen_area_init(1, 1, 48, 22);
	ge->descript = screen_area_init(50, 1, 29, 22);
	ge->banner = screen_area_init(28, 24, 23, 1);
	ge->help = screen_area_init(1, 25, 78, 2);
	ge->feedback = screen_area_init(1, 28, 78, 3);

	return ge;
}

void graphic_engine_destroy(Graphic_engine *ge)
{
	if (!ge)
		return;

	screen_area_destroy(ge->map);
	screen_area_destroy(ge->descript);
	screen_area_destroy(ge->banner);
	screen_area_destroy(ge->help);
	screen_area_destroy(ge->feedback);

	screen_destroy();
	free(ge);
}

/*private*/

STATUS set_string_obj(Game *game, char *obj, Space *space);

STATUS set_string_obj(Game *game, char *obj, Space *space)
{
	Id *id;
	int i, j, num;

	if (!obj || !space)
		return ERROR;

	id = space_get_objects(space);
	num = space_get_number_of_objects(space);

	if (id == NULL)
	{
		for (i = strlen(obj); i < WIDE; i++)
		{
			obj[i] = 32;
		}
		obj[11] = '\0';

		return ERROR;
	}

	obj[0] = '\0';

	for (i = 0; i < MAX_OBJECTS; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (object_get_id(game->objects[i]) == id[j])
			{

				strcat(obj, object_get_name(game->objects[i]));
				strcat(obj, " ");
			}
		}
	}
	i = strlen(obj);
	for (i = strlen(obj); i < WIDE; i++)
	{
		obj[i] = 32;
	}
	obj[11] = '\0';

	free(id);
	return OK;
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
	Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, ply_loc = NO_ID;
	Space *space_act = NULL;
	char obj[MAX_CHAR] = "";
	char *objs=NULL;
	char str[255], str_feedback[MAX_CHAR];
	T_Command last_cmd = UNKNOWN;
	extern char *cmd_to_str[N_CMD][N_CMDT];
	extern Id take_option;
	int last_die =0, i=0;

	/* Paint the in the map area */
	screen_area_clear(ge->map);

	if ((id_act = game_get_player_location(game)) != NO_ID)
	{
		space_act = game_get_space(game, id_act);
		id_back = space_get_north(space_act);
		id_next = space_get_south(space_act);

		set_string_obj(game, obj, game_get_space(game, id_back));

		if (id_back != NO_ID)
		{
			sprintf(str, "  |         %2d|", (int)id_back);
			screen_area_puts(ge->map, str);
			for (i = 0; i < INC1; i++) {
        		sprintf(str, "  |%s    |", space_get_gdesc(game_get_space(game, id_back), i));
        		screen_area_puts(ge->map, str);
     		 }
			sprintf(str, "  |%s|", obj);
			screen_area_puts(ge->map, str);
			sprintf(str, "  +-----------+");
			screen_area_puts(ge->map, str);
			sprintf(str, "        ^");
			screen_area_puts(ge->map, str);
		}
		obj[0] = '\0';

		set_string_obj(game, obj, game_get_space(game, id_act));

		if (id_act != NO_ID)
		{
			sprintf(str, "  +-----------+");
			screen_area_puts(ge->map, str);
			sprintf(str, "  | 8D      %2d|", (int)id_act);
			screen_area_puts(ge->map, str);
			for (i = 0; i < INC1; i++) {
        		sprintf(str, "  |%s    |", space_get_gdesc(game_get_space(game, id_act), i));
        		screen_area_puts(ge->map, str);
     		 }
			sprintf(str, "  |%s|", obj);
			screen_area_puts(ge->map, str);
			sprintf(str, "  +-----------+");
			screen_area_puts(ge->map, str);
		}
		obj[0] = '\0';

		set_string_obj(game, obj, game_get_space(game, id_next));

		if (id_next != NO_ID)
		{
			sprintf(str, "        v");
			screen_area_puts(ge->map, str);
			sprintf(str, "  +-----------+");
			screen_area_puts(ge->map, str);
			sprintf(str, "  |         %2d|", (int)id_next);
			screen_area_puts(ge->map, str);
			for (i = 0; i < INC1; i++) {
        		sprintf(str, "  |%s    |", space_get_gdesc(game_get_space(game, id_next), i));
        		screen_area_puts(ge->map, str);
     		 }
			sprintf(str, "  |%s|", obj);
			screen_area_puts(ge->map, str);
		}
		obj[0] = '\0';
	}

	/* Paint in the description area */
	screen_area_clear(ge->descript);

	screen_area_clear(ge->descript);
  	sprintf(str, "  Objects location: ");
  	screen_area_puts(ge->descript, str);
 	objs = game_print_object_location(game);
  	screen_area_puts(ge->descript, objs);
  	free(objs);

	sprintf(str, " ");
	screen_area_puts(ge->descript, str);

	ply_loc = game_get_player_location(game);
	sprintf(str, "  Player location: %d", (int)ply_loc);
	screen_area_puts(ge->descript, str);

	sprintf(str, " ");
	screen_area_puts(ge->descript, str);

	last_die = game_get_last_die(game);
	sprintf(str, "  Last die value: %d", last_die);
	screen_area_puts(ge->descript, str);

	/* Paint in the banner area */
	screen_area_puts(ge->banner, " The game of the Goose ");

	/* Paint in the help area */
	screen_area_clear(ge->help);
	sprintf(str, " The commands you can use are:");
	screen_area_puts(ge->help, str);
	sprintf(str, "next/n, back/b,take/t + <object name>, drop/d, left/l, right/r, roll/rl,exit/e");
	screen_area_puts(ge->help, str);

	/* Compruebo si el último comando se ha ejecutado correctamente antes de imprimir el feedback */

	if (game->last_cmd_st == OK)
	{
		strcpy(str_feedback, "OK");
	}
	else
		strcpy(str_feedback, "ERROR");

	/* Paint in the feedback area */

	last_cmd = game_get_last_command(game);
	if (last_cmd != TAKE)
		sprintf(str, " %s (%s): %s", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS], str_feedback);
	if (last_cmd == TAKE)
		sprintf(str, " %s O%ld: %s", cmd_to_str[last_cmd - NO_CMD][CMDL], take_option, str_feedback);
	screen_area_puts(ge->feedback, str);

	/* Dump to the terminal */
	screen_paint();
	printf("prompt:> ");
}
