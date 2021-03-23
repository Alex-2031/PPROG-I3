/** 
 * @brief Define un dado y maneja e imprime u información
 * 
 * @file die.h
 * @author Manuel Ardid Clavería
 * @date 01-03-2021
 */

#ifndef __DIE__
#define __DIE__

#include "types.h"

/**
* @brief Estructura que contiene los datos del dado: id, valor máximo, valor mínimo y último resultado
*
* @date 01-03-2021
* @author: Manuel Ardid Clavería
*/
typedef struct _Die Die;

/**
* @brief Reserva memoria para el dado e inicializa sus datos
*
* @date 01-03-2021
* @author: Manuel Ardid Clavería
*
* @param id Id del dado
* @param max valor máximo del dado
* @param min valor mínimo del dado
* @return Puntero al dado creado
*/
Die *die_create(Id id, int max, int min);

/**
* @brief Libera la memoria utilizada en el dado
*
* @date 01-03-2021
* @author: Manuel Ardid Clavería
*
* @param die Puntero al dado 
* @return OK o ERROR si ha habido algún problema
*/
STATUS die_destroy(Die *die);

/**
* @brief Devuelve el número identificador del dado
*
* @date 01-03-2021
* @author: Manuel Ardid Clavería
*
* @param die Puntero al dado 
* @return Id del dado 
*/
Id die_get_id(Die *die);

/**
* @brief Devuelve el valor mínimo del dado
*
* @date 01-03-2021
* @author: Manuel Ardid Clavería
*
* @param die Puntero al dado 
* @return valor mínimo del dado o -1 en caso de error
*/
int die_get_min(Die *die);

/**
* @brief Devuelve el valor máximo del dado
*
* @date 01-03-2021
* @author: Manuel Ardid Clavería
*
* @param die Puntero al dado 
* @return valor máximo del dado o -1 en caso de error
*/
int die_get_max(Die *die);

/**
* @brief Devuelve el resultado de la última tirada del dado
*
* @date 01-03-2021
* @author: Manuel Ardid Clavería
*
* @param die Puntero al dado 
* @return último resultado o -1 en caso de error
*/
int die_get_last_num(Die *die);

/**
* @brief Tira el dado y actualiza el último resultado
*
* @date 01-03-2021
* @author: Manuel Ardid Clavería
*
* @param die Puntero al dado 
* @return OK o ERROR si ha habido algún problema
*/
STATUS die_roll(Die *die);

/**
* @brief Imprime la información del dado
*
* @date 01-03-2021
* @author: Manuel Ardid Clavería
*
* @param die Puntero al dado 
* @return OK o ERROR si ha habido algún problema
*/
STATUS die_print(Die *die);
#endif