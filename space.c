#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "space.h"
#include "object.h"
#include "set.h"

/**
* @brief Estructura con los datos de un espacio
*
* @param id id del espacio
* @param name cadena de caracteres con el nombre del espacio
* @param north del espacio al norte del espacio actual
* @param south del espacio al sur del espacio actual
* @param east del espacio al este del espacio actual
* @param west del espacio al oeste del espacio actual
* @param objecys conjunto de objetos en el espacio
* @param gdesc descripción gráfica del espacio 
* @date 14-02-2021
* @author: Manuel Ardid Clavería 
*/
struct _Space
{
	Id id;
	char name[WORD_SIZE + 1];
	Id north;
	Id south;
	Id east;
	Id west;
	Set *objects;
	char gdesc[INC1][INC2+1];
};

Space *space_create(Id id)
{
	int i, j;
	Space *newSpace = NULL;

	if (id == NO_ID)
		return NULL;

	newSpace = (Space *)malloc(sizeof(Space));

	if (newSpace == NULL)
	{
		return NULL;
	}

	newSpace->id = id;

	newSpace->name[0] = '\0';

	newSpace->north = NO_ID;
	newSpace->south = NO_ID;
	newSpace->east = NO_ID;
	newSpace->west = NO_ID;

	Set *newObjects = NULL;

	newObjects = set_create();
	if (newObjects == NULL)
		return NULL;

	newSpace->objects = newObjects;

	for (i = 0; i < INC1; i++)
	{
		for (j = 0; j < INC2; j++)
		{
			newSpace->gdesc[i][j] = 32;
		}
	}

	return newSpace;
}

STATUS space_destroy(Space *space)
{
	if (!space)
	{
		return ERROR;
	}

	set_destroy(space->objects);

	free(space);
	space = NULL;

	return OK;
}

STATUS space_has_object(Space *space, Id id)
{
	STATUS st;
	if (!space)
		return ERROR;

	st = set_has_object(space->objects, id);

	return st;
}

STATUS space_set_name(Space *space, char *name)
{
	if (!space || !name)
	{
		return ERROR;
	}

	if (!strcpy(space->name, name))
	{
		return ERROR;
	}

	return OK;
}

STATUS space_set_north(Space *space, Id id)
{
	if (!space || id == NO_ID)
	{
		return ERROR;
	}
	space->north = id;
	return OK;
}

STATUS space_set_south(Space *space, Id id)
{
	if (!space || id == NO_ID)
	{
		return ERROR;
	}
	space->south = id;
	return OK;
}

STATUS space_set_east(Space *space, Id id)
{
	if (!space || id == NO_ID)
	{
		return ERROR;
	}

	space->east = id;

	return OK;
}

STATUS space_set_west(Space *space, Id id)
{
	if (!space || id == NO_ID)
	{
		return ERROR;
	}

	space->west = id;

	return OK;
}

STATUS space_set_gdesc(Space *space, char *gdesc, int row) {
  if (!space || !gdesc || row >= INC1 || row < 0) {
    return ERROR;
  }

  strcpy(space->gdesc[row], gdesc);

  return OK;
}

STATUS space_set_object(Space *space, Id value)
{
	STATUS st;
	if (!space)
	{
		return ERROR;
	}

	st = set_add(space->objects, value);
	if (st == ERROR)
		return ERROR;

	return OK;
}

STATUS space_delete_object(Space *space, Id value)
{
	STATUS st;
	if (!space)
		return ERROR;

	st = set_del(space->objects, value);

	return st;
}

int space_get_number_of_objects(Space *space)
{
	int num;
	if (!space)
		return -1;

	num = set_get_num_of_ids(space->objects);

	return num;
}

const char *space_get_name(Space *space)
{
	if (!space)
	{
		return NULL;
	}

	return space->name;
}

Id space_get_id(Space *space)
{
	if (!space)
	{
		return NO_ID;
	}

	return space->id;
}

Id space_get_north(Space *space)
{
	if (!space)
	{
		return NO_ID;
	}

	return space->north;
}

Id space_get_south(Space *space)
{
	if (!space)
	{
		return NO_ID;
	}

	return space->south;
}

Id space_get_east(Space *space)
{
	if (!space)
	{
		return NO_ID;
	}

	return space->east;
}

Id space_get_west(Space *space)
{
	if (!space)
	{
		return NO_ID;
	}

	return space->west;
}

char *space_get_gdesc(Space *space, int row) {
  if (!space || row >= INC2 || row < 0) {
    return NULL;
  }

  return space->gdesc[row];
}

Id *space_get_objects(Space *space)
{
	Id *ids;
	int num, i;
	if (!space)
	{
		return NULL;
	}

	num = space_get_number_of_objects(space);
	if (num == 0)
		return NULL;

	ids = (Id *)malloc(num * sizeof(Id));
	if (ids == NULL)
		return NULL;

	for (i = 0; i < num; i++)
	{
		ids[i] = set_get_object_from_pos(space->objects, i);
	}

	return ids;
}

STATUS space_print(Space *space)
{
	Id idaux = NO_ID;
	Id *aux;
	int num;
	int i;
	char *pal;

	if (!space)
	{
		return ERROR;
	}

	fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

	idaux = space_get_north(space);
	if (NO_ID != idaux)
	{
		fprintf(stdout, "---> North link: %ld.\n", idaux);
	}
	else
	{
		fprintf(stdout, "---> No north link.\n");
	}

	idaux = space_get_south(space);
	if (NO_ID != idaux)
	{
		fprintf(stdout, "---> South link: %ld.\n", idaux);
	}
	else
	{
		fprintf(stdout, "---> No south link.\n");
	}

	idaux = space_get_east(space);
	if (NO_ID != idaux)
	{
		fprintf(stdout, "---> East link: %ld.\n", idaux);
	}
	else
	{
		fprintf(stdout, "---> No east link.\n");
	}

	idaux = space_get_west(space);
	if (NO_ID != idaux)
	{
		fprintf(stdout, "---> West link: %ld.\n", idaux);
	}
	else
	{
		fprintf(stdout, "---> No west link.\n");
	}

	num = space_get_number_of_objects(space);
	if (num != 0)
	{
		aux = space_get_objects(space);
		for (i = 0; i < num; i++)
		{
			fprintf(stdout, "%ld ", aux[i]);
		}
		fprintf(stdout, "---> Objects in the space.\n");
	}
	if (num == 0)
	{
		fprintf(stdout, "---> No object in the space.\n");
	}

	fprintf(stdout, "Gdesc:\n");

	for (i = 0; i < INC1; i++)
	{
		pal = space_get_gdesc(space, i);
		fprintf(stdout, "%s\n", pal);
	}

	return OK;
}
