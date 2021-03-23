/** 
 * @brief Define un jugador e imprime su información
 * 
 * @file player.h
 * @author Alejandro Domínguez Abad
 * @date 15-02-2021
 */

#ifndef __PLAYER__
#define __PLAYER__

#include "types.h"

/**
* @brief Estructura que contiene los datos del jugador: id, nombre, localización y objeto
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*/
typedef struct _Player Player;

/**
* @brief Inicializa los datos del jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param Id Id del jugador
* @return Estructura del jugador creado
*/
Player *player_create(Id id);

/**
* @brief Destruye un jugador y libera su memoria
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param player puntero al jugador
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS player_destroy(Player *player);

/**
* @brief Obtiene la id de un jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param player puntero al jugador
* @return Devuelve id del jugador
*/
Id player_get_id(Player *player);

/**
* @brief Cambia el id de un jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param player puntero al jugador
* @param id Id del jugador
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS player_set_id(Player *player, Id id);

/**
* @brief Obtiene el nombre del jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param player puntero al jugador
* @return Devuelve el nombre del jugador
*/
const char *player_get_name(Player *player);

/**
* @brief Actualiza el nombre del jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param player puntero al jugador
* @param name nombre del jugador
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS player_set_name(Player *player, char *name);

/**
* @brief Obtiene la localización del jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param player puntero al jugador
* @return Devuelve el id del espacio que contiene al jugador
*/
Id player_get_location(Player *player);

/**
* @brief Actualiza la localización del jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param player puntero al jugador
* @param location id del espacio en el que queremos situar al jugador
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS player_set_location(Player *player, Id location);

/**
* @brief Obtiene el objeto del jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param player puntero al jugador
* @return Devuelve el id del objeto del jugador
*/
Id player_get_object(Player *player);

/**
* @brief Actualiza el objeto del jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param player puntero al jugador
* @param id Id del objeto
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS player_set_object(Player *player, Id id);

/**
* @brief Imprime la información del jugador
*
* @date 15-02-2021
* @author: Alejandro Domínguez Abad
*
* @param player puntero al jugador
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS player_print(Player *player);

#endif
