#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

/** 
 * @brief Estructura que define el TAD Object, incluye una Id y un nombre del objeto
 * 
 * @param id id del objeto
 * @param name cadena de caracteres con el nombre del objeto
 * 
 * @author Manuel Ardid Clavería 
 * @date 12-02-2021
 */
struct _Object
{
    Id id;
    char name[WORD_SIZE + 1];
};

Object *object_create(Id id)
{

    Object *NewObject = NULL;

    if (id == NO_ID)
        return NULL;

    NewObject = (Object *)malloc(sizeof(Object));
    if (NewObject == NULL)
        return NULL;

    NewObject->id = id;
    NewObject->name[0] = '\0';

    return NewObject;
}

STATUS object_destroy(Object *object)
{
    if (!object)
    {
        return ERROR;
    }

    free(object);
    object = NULL;

    return OK;
}

STATUS object_set_id(Object *object, Id id)
{
    if (!object || !id)
        return ERROR;
    object->id = id;
    return OK;
}

Id object_get_id(Object *object)
{
    if (!object)
        return NO_ID;

    return object->id;
}

STATUS object_set_name(Object *object, char *name)
{
    if (!object || !name)
        return ERROR;

    if (!strcpy(object->name, name))
    {
        return ERROR;
    }

    return OK;
}

const char *object_get_name(Object *object)
{
    if (!object)
        return NULL;

    return object->name;
}

STATUS object_print(Object *object)
{
    if (!object)
        return ERROR;

    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

    return OK;
}
