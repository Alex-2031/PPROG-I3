/** 
 * @brief Define varios valores de retorno y constantes utilizados en el proyecto
 * 
 * @file types.h
 * @author Manuel Ardid Clavería 
 * @date 12-02-2021
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000 /*Tamaño máximo de palabra*/
#define NO_ID -1	   /*Valor para Ids no válidas*/

typedef long Id; /*Deficnición de Ids como enteros long*/

/**
* @brief Enumeración booleana con FALSE = 0 y TRUE = 1
*
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*/
typedef enum
{
	FALSE,
	TRUE
} BOOL;

/**
* @brief Enumeración Status con ERROR = 0 y OK = 1
*
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*/
typedef enum
{
	ERROR,
	OK
} STATUS;

/**
* @brief Enumeración de puntos cardinales con N = 0, S = 1, E = 2, W = 3
*
* @date 15-02-2021
* @author: Manuel Ardid Clavería
*/
typedef enum
{
	N,
	S,
	E,
	W
} DIRECTION;

#endif
