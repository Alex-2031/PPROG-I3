/** 
 * @brief Define el apartado gráfico del juego
 * 
 * @file graphic_engine.h
 * @author Manuel Ardid Clavería 
 * @date 12-02-2021
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

/**
* @brief Estructura del motor gráfico que define las áreas de la pantalla dedicadas a una tarea concreta
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*/
typedef struct _Graphic_engine Graphic_engine;

/**
* @brief Función principal que llama al resto de funciones, además, se muestra un código de error si no se especifican los dos argumentos("./" y "data.dat")
*
* @date 14-02-2021
* @author: Alejandro Domínguez Abad
*
* @param argc Número de argumentos Nombre de los argumentos
* @param argv Nombre de los argumentos
* @return Devuelve 1 si el número de argumentos es incorrecto y 0 en caso contrario
*/
int main(int argc, char *argv[]);

/**
* @brief Inicializa el juego llamando a las funciones "game_reader_create_from_file" y "*gengine = graphic_engine_create()"
*
* @date 14-02-2021
* @author: Alejandro Domínguez Abad
*
* @param game puntero al juego
* @param gengine doble puntero al motor gráfico
* @param file_name nombre del archivo a partir del cual se crea el tablero de juego
* @return Devuelve 0 si no hay errores y 1 en caso contrario
*/
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

/**
* @brief Pinta una casilla, obtiene el comando introducido y lo pasa a la función game_update, opcionalmente crea un registro de los comandos utilizados por el jugador
*
* @date 14-02-2021
* @author:Alejandro Domínguez Abad
*
* @param game puntero al juego
* @param gengine puntero al motor gráfico
* @param log puntero al fichero de registro
*/
void game_loop_run(Game game, Graphic_engine *gengine, FILE *log);

/**
* @brief Elimina los espacios y libera la memoria
*
* @date 14-02-2021
* @author: Alejandro Domínguez Abad
*
* @param game puntero al juego
* @param gengine puntero al motor gráfico
*/
void game_loop_cleanup(Game game, Graphic_engine *gengine);

/**
* @brief Escribe en un archivo de registro cómo se han ido ejecutando los comandos del jugador
*
* @date 19-03-2021
* @author: Manuel Ardid Clavería
*
* @param game puntero al juego
* @param log puntero al archivo de registro
*/
void game_loop_print_log(Game *game, FILE *log);

/**
* @brief reserva espacio en memoria para el motor gráfico e inicializa sus campos
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería
*
* @return puntero al motor gráfico
*/
Graphic_engine *graphic_engine_create();

/**
* @brief Libera la memoria utilizada por el motor gráfico
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería
*
* @param ge puntero al motor gráfico
*/
void graphic_engine_destroy(Graphic_engine *ge);

/**
* @brief Dibuja en pantalla el tablero de juego
*
* @date 23-03-2021
* @author: Alejandro Dominguez Abad
*
* @param ge puntero al motor gráfico
* @param game puntero al juego
*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
