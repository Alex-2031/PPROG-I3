#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "command.h"

char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"n", "Next"}, {"b", "Back"}, {"t", "Take"}, {"d", "Drop"}, {"l", "Left"}, {"r", "Right"}, {"rl", "Roll"}};
Id take_option = 0;

T_Command command_get_user_input()
{
	T_Command cmd = NO_CMD;
	char input[CMD_LENGHT] = "";
	char take_opt[CMD_LENGHT] = "";
	char aux[CMD_LENGHT];
	int i = UNKNOWN - NO_CMD + 1;
	int num;

	if (scanf("%s", input) > 0)
	{
		cmd = UNKNOWN;

		while (cmd == UNKNOWN && i < N_CMD)
		{
			if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL]))
			{
				cmd = i + NO_CMD;
			}
			else
			{
				i++;
			}
		}

		if (cmd == TAKE)
		{
			scanf("%s", take_opt);
			if (take_opt[0] != 79)
				return UNKNOWN;

			num = strlen(take_opt);
			for (i = 0; i < num; i++)
			{
				aux[i] = take_opt[i + 1];
			}
			strcpy(take_opt, aux);
			num = atoi(take_opt);
			take_option=num;
		}
	}

	return cmd;
}
