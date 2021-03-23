/** 
 * @brief define los espacios de juego
 * 
 * @file space.h
 * @author Manuel Ardid Clavería 
 * @date 12-02-2021
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"

/**
* @brief Estructura con los datos de un espacio
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*/
typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1
#define INC1 3
#define INC2 7

/**
* @brief Inicializa los datos del espacio
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param id Id del espacio
* @return Devuelve el espacio creado
*/
Space *space_create(Id id);

/**
* @brief Destruye un espacio y libera su memoria
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero a un espacio
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS space_destroy(Space *space);

/**
* @brief Comprueba si el espacio tiene el objeto indicado
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad
*
* @param space puntero a un espacio
* @param Id del objeto  
* @return OK o ERROR si ha habido algún problema
*/
STATUS space_has_object(Space *space, Id id);

/**
* @brief Obtiene el Id de un espacio
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero a un espacio
* @return Devuelve la Id del espacio
*/
Id space_get_id(Space *space);

/**
* @brief Cambia el nombre un espacio
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero a un espacio
* @param name nombre del espacio 
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS space_set_name(Space *space, char *name);

/**
* @brief Obtiene el nombre de un espacio
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero a un espacio
* @return Devuelve el nombre del espacio
*/
const char *space_get_name(Space *space);

/**
* @brief space set graphic description
*
* space_set_gdesc It gives a graphic description to the space
*
* @date 14/03/2021
* @author: Emilia Cheng
*
* @param space where it's going to be saved
* @param gdesc the string with the description
* @param row it indicates the row of the graphic
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_set_gdesc(Space *space, char *gdesc, int row);

/**
* @brief Cambia el Id de north
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero al espacio
* @param id Id nuevo para north
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS space_set_north(Space *space, Id id);

/**
* @brief Obtiene el Id de north
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero a un espacio
* @return Devuelve el Id de north
*/
Id space_get_north(Space *space);

/**
* @brief Cambia el Id de south
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero al espacio
* @param id Id nuevo para south
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS space_set_south(Space *space, Id id);

/**
* @brief Obtiene el Id de south
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero a un espacio
* @return Devuelve el Id de south
*/
Id space_get_south(Space *space);

/**
* @brief Cambia el Id de east
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero al espacio
* @param id Id nuevo para east
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS space_set_east(Space *space, Id id);

/**
* @brief Obtiene el Id de south
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería
*
* @param space puntero a un espacio
* @return Devuelve el Id de south
*/
Id space_get_east(Space *space);

/**
* @brief Cambia el Id de west
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero al espacio
* @param id Id nuevo para west
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS space_set_west(Space *space, Id id);

/**
* @brief Obtiene el Id de west
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero a un espacio
* @return Devuelve el Id de west
*/
Id space_get_west(Space *space);

/**
* @brief Añande un objeto a un espacio
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad
*
* @param space puntero a un espacio
* @param Id del objeto a añadir  
* @return OK o ERROR si ha habido algún problema
*/
STATUS space_set_object(Space *space, Id value);

/**
* @brief space get graphic description
*
* space_get_gdesc where we can get the graphic description of the space 
* in regards of the specific row
*
* @date 14/03/2021
* @author: Emilia Cheng
*
* @param space where it get the direction of the gdesc
* @param row it indicates the row of the graphic
* @return the string with the graphic of the specific row or NULL if it failes 
*/
char *space_get_gdesc(Space *space, int fil);

/**
* @brief Elimina un objeto de un espacio
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad
*
* @param space puntero a un espacio
* @param Id del objeto a eliminar  
* @return OK o ERROR si ha habido algún problema
*/
STATUS space_delete_object(Space *space, Id value);

/**
* @brief Obtiene el número de objetos de un spacio
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad 
*
* @param puntero a un espacio
* @return Devuelve el nñemero de objetos del espacio
*/
int space_get_number_of_objects(Space *space);

/**
* @brief Obtiene los ids de los objetos del espacio
*
* @date 3-03-2021
* @author: Alejandro Domínguez Abad 
*
* @param space puntero a un espacio
* @return Devuelve la dirrecion de una array con los ids
*/
Id *space_get_objects(Space *space);

/**
* @brief Imprime el espacio
*
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*
* @param space puntero a un espacio
* @return Devuelve OK o ERROR si ha habido algún problema
*/
STATUS space_print(Space *space);

#endif
