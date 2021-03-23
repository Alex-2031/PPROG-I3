/** 
 * @brief Define un conjunto que contiene ids de objetos
 * 
 * @file set.h
 * @author Alejandro Domínguez Abad
 * @date 3-03-2021
 */

#ifndef __SET__
#define __SET__

#include "types.h"

#define MAX_ID 100

/** 
 * @brief Estructura que define el TAD Set, incluye una array de ids y un entero del total de ids
 * 
 * @author  Alejandro Domínguez Abad
 * @date 3-03-2021
 */
typedef struct _Set Set;

/**
* @brief Crea un conjunto e inicializa sus datos
*
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad 
*
* @return Puntero al conjunto creado
*/
Set *set_create();

/**
* @brief Libera la memoria de un conjunto
*
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad 
*
* @param set Puntero al conjunto
* @return OK si todo es correcto o ERROR si falla algo
*/
STATUS set_destroy(Set *set);

/**
* @brief Obtiene el número de objetos del conjunto
*
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad 
*
* @param set Puntero al conjunto
* @return Número de objetos del conjunto
*/
int set_get_num_of_ids(Set *set);

/**
* @brief comprueba si el conjunto tiene un objeto
*
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad 
*
* @param set Puntero al conjunto
* @param id Id del objeto
* @return OK si todo es correcto o ERROR si falla algo
*/
STATUS set_has_object(Set *set, Id id);

/**
* @brief Obtiene el objeto que hay en la posición indicada
*
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad 
*
* @param set Puntero al conjunto
* @param pos Posición del objeto
* @return Id del objeto
*/
Id set_get_object_from_pos(Set *set, int pos);

/**
* @brief Añade un nuevo id al conjunto
*
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad 
*
* @param set Puntero al conjunto 
* @param id Id que se quiere añadir al conjunto
* @return OK si todo es correcto o ERROR si falla algo
*/
STATUS set_add(Set *set, Id id);

/**
* @brief Elimina un id del conjunto
*
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad 
*
* @param set Puntero al conjunto 
* @param id Id que se quiere borrar del conjunto
* @return OK si todo es correcto o ERROR si falla algo
*/
STATUS set_del(Set *set, Id id);

/**
* @brief Imprime los datos del conjunto
*
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad 
*
* @param set Puntero al objeto
* @return OK si todo es correcto o ERROR si falla algo
*/
STATUS set_print(Set *set);



#endif