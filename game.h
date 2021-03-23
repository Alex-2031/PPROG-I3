/** 
 * @brief Define y maneja el juego
 * 
 * @file game.h
 * @author Manuel Ardid Clavería 
 * @date 12-02-2021
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "die.h"

#define N_CALLBACK 10
/**
   Define the function type for the callbacks
*/

/**
* @brief Estructura del juego que incluye, jugador, onjeto, espacio y comandos
*
* @param player puntero al jugador
* @param objects puntero a la array de objetos
* @param spaces puntero a la array de espacios
* @param die puntero al dado
* @param last_cmd último comando introducido por el jugador
* @param last_cmd_st estado del último comando introducido por el jugadorS
*
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*/
typedef struct _Game
{
  Player *player;
  Object *objects[MAX_OBJECTS];
  Space *spaces[MAX_SPACES + 1];
  Die *die;
  T_Command last_cmd;
  STATUS last_cmd_st;
} Game;

/**
* @brief Inicializa los valores de la estructura game
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param game puntero al juego
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS game_create(Game *game);

/**
* @brief Añade un espacio al juego
*
*
* @date 12-02-2021
* @author: Alejandro Domínguez Abad
*
* @param game puntero al juego
* @param space puntero al espacio
* @return OK o ERROR si ha habido algún problema
*/
STATUS game_add_space(Game *game, Space *space);

/**
* @brief Añade un objeto al juego
*
*
* @date 09-03-2021
* @author: Manuel Ardid Clavería
*
* @param game puntero al juego
* @param space puntero al objeto
* @return OK o ERROR si ha habido algún problema
*/
STATUS game_add_object(Game *game, Object *object);

/**
* @brief Actualiza la posición del jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param game puntero al juego
* @param id id del nuevo espacio
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS game_set_player_location(Game *game, Id id);

/**
* @brief Actualiza la posición del objeto
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param game puntero al juego
* @param id id del nuevo espacio
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS game_set_object_location(Game *game, Id id, Id object);

/**
* @brief Devuelve el ID del espacio en la posición indicada
*
* @date 15-02-2021
* @author: Manuel Ardid Clavería 
*
* @param game puntero al juego
* @param position posición del espacio
* @return Devuelve el ID
*/
Id game_get_space_id_at(Game *game, int position);

/**
* @brief Obtiene el último valor del dado
*
* @date 16-03-2021
* @author: Alejandro Dominguez Abad 
*
* @param game puntero al juego
* @return Devuelve el valor del último dado
*/
int game_get_last_die(Game *game);

/**
* @brief Actualiza el juego después de redibir un comando
*
* @date 15-02-2021
* @author: Manuel Ardid Clavería 
*
* @param game puntero a Game
* @param cmd Comando introducido por el usuario
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS game_update(Game *game, T_Command cmd);

/**
* @brief Libera el espacio en memoria utilizado por el juego
*
* @date 15-02-2021
* @author: Manuel Ardid Clavería 
*
* @param game puntero a Game
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS game_destroy(Game *game);

/**
* @brief Declara el fin del juego
*
* @date 15-02-2021
* @author: Manuel Ardid Clavería 
*
* @param game puntero al juego
* @return Devuelve FALSE
*/
BOOL game_is_over(Game *game);

/**
* @brief Inorime tanto los espacios como la información del objeto y del jugador
*
* @date 15-02-2021
* @author: Manuel Ardid Clavería 
*
* @param game puntero al juego
*/
void game_print_data(Game *game);

/**
* @brief Print the information of the objects and it's location
*
* game_print_object_location It gets the string with the object information
*
* @date 19-03-2021
* @author: Emilia Cheng
*
* @param game where it gets the information of the game
* @return the string with the objects or NULL if it fails
*/
char *game_print_object_location(Game *game);

/**
* @brief Obtiene un espacio de la array de la estructura del juego
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param game puntero al juego
* @param id Id del espacio
* @return Devuelve puntero al espacio o NULL si ha habido algún problema
*/
Space *game_get_space(Game *game, Id id);

/**
* @brief Obtiene la localizaición del jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param game puntero al juego
* @return id del espacio que contiene al jugador
*/
Id game_get_player_location(Game *game);

/**
* @brief Obtiene la localización del objeto
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param game puntero al juego
* @param id del objeto
* @return id del espacio que contiene al objeto
*/
Id game_get_object_location(Game *game, Id id);

/**
* @brief Obtiene el último comando introducido por el usuario
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param game puntero al juego
* @return Devuelve el ultimo comando introducido por el usuario
*/
T_Command game_get_last_command(Game *game);

/**
* @brief Obtiene el estado del último comando ejecutado, STATUS = OK si el comando se
* ha ejecutado correctamente, STATUS = ERROR si el comando no se ha ejecutado correctamente
* o incumple la lógica del juego
* @date 15-03-2021
* @author: Manuel Ardid Clavería
*
* @param game puntero al juego
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS game_get_last_command_st(Game *game);

#endif