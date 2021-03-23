#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphic_engine.h"
#include "game_reader.h"

#define MAX_CHAR 64

int main(int argc, char *argv[])
{
	Game game;
	Graphic_engine *gengine;
	char log_file_name[MAX_CHAR] = "";
	FILE *log = NULL;

	if (argc < 2 || argc == 3 || argc > 4)
	{
		fprintf(stderr, "Use: %s <game_data_file> or Use: %s <game_data_file> -l <game_log_file>\n", argv[0], argv[0]);
		return 1;
	}
	if (argc < 4 && argc != 2) {
    	fprintf(stderr, "Use: %s <game_data_file> -1 <game_log_file>\n", argv[0]);
    	return 1;
  	} 

	if (argc == 4)
	{
		if (strcmp(argv[2], "-l")) {
      		fprintf(stderr, "Use: %s <game_data_file> -1 <game_log_file>\n", argv[0]);
      		return 1;
    	}
		strcpy(log_file_name, argv[3]);
		log = fopen(log_file_name, "w");
	}

	if (!game_loop_init(&game, &gengine, argv[1]))
	{
		game_loop_run(game, gengine, log);
		game_loop_cleanup(game, gengine);
	}

	if (argc == 4)
	{
		fclose(log);
	}
	return 0;
}

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name)
{

	if (game_reader_create_from_file(game, file_name) == ERROR)
	{
		fprintf(stderr, "Error while initializing game.\n");
		return 1;
	}

	if ((*gengine = graphic_engine_create()) == NULL)
	{
		fprintf(stderr, "Error while initializing graphic engine.\n");
		game_destroy(game);
		return 1;
	}

	return 0;
}

void game_loop_run(Game game, Graphic_engine *gengine, FILE *log)
{
	T_Command command = NO_CMD;

	while ((command != EXIT) && !game_is_over(&game))
	{
		graphic_engine_paint_game(gengine, &game);
		command = command_get_user_input();
		game_update(&game, command);
		game_loop_print_log(&game, log);
	}
}

void game_loop_cleanup(Game game, Graphic_engine *gengine)
{
	game_destroy(&game);
	graphic_engine_destroy(gengine);
}

void game_loop_print_log(Game *game, FILE *log)
{
	char last_cmd_st[MAX_CHAR];

	extern char *cmd_to_str[N_CMD][N_CMDT];
	T_Command last_cmd = UNKNOWN;

	last_cmd = game_get_last_command(game);

	if (game_get_last_command_st(game) == OK)
	{
		strcpy(last_cmd_st, "OK");
	}

	else
		strcpy(last_cmd_st, "ERROR");

	if (log != NULL)
	{
		fprintf(log, " %s (%s): %s\n", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS], last_cmd_st);
	}

	return;
}
