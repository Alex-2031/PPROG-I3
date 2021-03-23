/** 
 * @brief Maneja la pantalla de juego
 * 
 * @file screen.h
 * @author Manuel Ardid Clavería 
 * @date 12-02-2021
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80

#define ROWS 32
#define COLUMNS 80
#define TOTAL_DATA (ROWS * COLUMNS) + 1

#define BG_CHAR '~'
#define FG_CHAR ' '
#define PROMPT " prompt:> "

#define ACCESS(d, x, y) (d + ((y)*COLUMNS) + (x))

typedef struct _Area Area;

/**
* @brief Reserva memoria e inicializa la pantalla
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*/
void screen_init();

/**
* @brief Libera la memoria utilizada por la pantalla
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*/
void screen_destroy();

/**
* @brief Dibuja en pantalla
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*/
void screen_paint();

/**
* @brief Reserva memoria para el área a utilizar de la pantalla e iniciializa sus valores
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*
* @param x coordenada x del área
* @param y coordenada y del área
* @param width ancho del área
* @param height alto del área
*
* @return devuelve puntero al área
*/
Area *screen_area_init(int x, int y, int width, int height);

/**
* @brief Libera la memoria utilizada en el área de pantalla
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*
* @param area puntero al área
*/
void screen_area_destroy(Area *area);

/**
* @brief Borra lo que hay impreso en el área de pantalla
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*
* @param area puntero al área
*/
void screen_area_clear(Area *area);

void screen_area_reset_cursor(Area *area);
void screen_area_puts(Area *area, char *str);

#endif
