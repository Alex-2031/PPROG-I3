/** 
 * @brief Maneja los comandos de juego
 * 
 * @file command.h
 * @author Manuel Ardid Clavería 
 * @date 12-02-2021
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define N_CMDT 2
#define N_CMD 10
#define CMD_LENGHT 30

#define MIN_OBJECT 1

/**
* @brief Enumeración que contiene los tipos de comando
*
* @date 14-02-2021
* @author: Alejandro Domínguez Abad
*
*/
typedef enum enum_CmdType
{
	CMDS,
	CMDL
} T_CmdType;

/**
* @brief Enumeración que contiene los tipos de salida del comando
*
* @date 14-02-2021
* @author: Alejandro Domínguez Abad
*
*/
typedef enum enum_Command
{
	NO_CMD = -1,
	UNKNOWN,
	EXIT,
	NEXT,
	BACK,
	TAKE,
	DROP,
	LEFT,
	RIGHT,
	ROLL
} T_Command;

/**
* @brief Lee el comando introducido por el jugador
*
* @date 14-02-2021
* @author: Alejandro Domínguez Abad
*
* @return Devuelve el comando introducido
*/
T_Command command_get_user_input();


#endif
