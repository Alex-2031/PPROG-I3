/** 
 * @brief Define los objetos del juego e imprime su información
 * 
 * @file object.h
 * @author Manuel Ardid Clavería 
 * @date 12-02-2021
 */

#ifndef OBJECT_H
#define OBJECT_H

#define MAX_OBJECTS 100

/** 
 * @brief Define un objeto
 * 
 * @file object.h
 * @author Manuel Ardid Clavería 
 * @date 12-02-2021
 */
#include "types.h"

/** 
 * @brief Estructura que define el TAD Object, incluye una Id y un nombre del objeto
 * 
 * @author Manuel Ardid Clavería 
 * @date 12-02-2021
 */
typedef struct _Object Object;

/**
* @brief Crea un objeto e inicializa sus datos
*
*
* @date 12-02-2021
* @author: Manuel Ardid Clavería 
*
* @param id número identificador del objeto
* @return devuelve un puntero al objeto creado
*/
Object *object_create(Id id);

/**
* @brief Libera la memoria utilizada por un objeto
*
*
* @date 12-02-2021
* @author: Manuel Ardid Clavería 
*
* @param object puntero al objeto
* @return devuelve OK o ERROR si ha habido algún problema
*/
STATUS object_destroy(Object *object);

/**
* @brief Actualiza el id de un objeto
*
*
* @date 12-02-2021
* @author: Manuel Ardid Clavería
*
* @param object puntero al objeto
* @param id número identificador del objeto
* @return devuelve OK o ERROR si ha habido algún problema
*/
STATUS object_set_id(Object *object, Id id);

/**
* @brief Obtiene el Id de un objeto
*
*
* @date 12-02-2021
* @author: Manuel Ardid Clavería 
*
* @param object puntero al objeto
* @return devuelve el Id del objeto
*/
Id object_get_id(Object *object);

/**
* @brief Actualiza el nombre de un objeto
*
*
* @date 12-02-2021
* @author: Manuel Ardid Clavería 
*
* @param object puntero al objeto
* @param name nombre del objeto
* @return devuelve OK o ERROR si ha habido algún problema
*/
STATUS object_set_name(Object *object, char *name);

/**
* @brief Obtiene el nombre de un objeto
*
*
* @date 12-02-2021
* @author: Manuel Ardid Clavería 
*
* @param object puntero al objeto
* @return devuelve el nombre del objeto
*/
const char *object_get_name(Object *object);

/**
* @brief Imprime por pantalla la información de un objeto
*
*
* @date 12-02-2021
* @author: Manuel Ardid Clavería 
*
* @param object puntero al objeto
* @return devuelve OK o ERROR si ha habido algún problema
*/
STATUS object_print(Object *object);

#endif