/** 
 * @brief Maneja los espacios de juego
 * 
 * @file game_reader.h
 * @author Manuel Ardid Clavería 
 * @date 12-02-2021
 */

#ifndef GAME_READER
#define GAME_READER

#include "game.h"
#include "space.h"

/**
* @brief Carga los espacios de juego
*
*
* @date 12-02-2021
* @author: Manuel Ardid Clavería 
*
* @param game puntero al juego
* @param filename archivo de datos a partir del que se crea el juego
* @return devuelve OK o ERROR
*/
STATUS game_reader_load_spaces(Game *game, char *filename);

/**
* @brief Carga el juego a partir de un archivo
*
*
* @date 12-02-2021
* @author: Manuel Ardid Clavería 
*
* @param game puntero al juego
* @param filename archivo de datos a partir del que queremos crear el juego
* @return devuelve OK o ERROR
*/
STATUS game_reader_create_from_file(Game *game, char *filename);
#endif
