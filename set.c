#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

/** 
 * @brief Estructura que define el TAD Set, incluye una array de ids y un entero del total de ids
 * 
 * @param id array de ids de objetos del conjunto
 * @param numid número de ids que pertenecen al conjunto 
 * @author  Alejandro Domínguez Abad
 * @date 3-03-2021
 */
struct _Set
{
	Id id[MAX_ID];
	int numid;
};

Set *set_create()
{
	int i;
	Set *newSet = NULL;

	newSet = (Set *)malloc(sizeof(Set));
	if (newSet == NULL)
	{
		return NULL;
	}

	for (i = 0; i < MAX_ID; i++)
	{
		newSet->id[i] = NO_ID;
	}

	newSet->numid = 0;

	return newSet;
}

STATUS set_destroy(Set *set)
{

	if (!set)
	{
		return ERROR;
	}

	free(set);

	return OK;
}

int set_get_num_of_ids(Set *set)
{
	if (!set)
		return -1;

	return set->numid;
}

STATUS set_has_object(Set *set, Id id)
{
	int i;
	BOOL st = FALSE;
	if (!set)
		return ERROR;

	for (i = 0; i < set->numid && st == FALSE; i++)
	{
		if (set->id[i] == id)
			st = TRUE;
	}

	return st;
}

Id set_get_object_from_pos(Set *set, int pos)
{
	int num;
	if (!set)
		return NO_ID;

	num = set_get_num_of_ids(set);
	if (num == 0)
		return -1;

	return set->id[pos];
}

STATUS set_add(Set *set, Id id)
{
	int i;
	Id aux;
	STATUS st = OK;

	if (!set || id == NO_ID)
	{
		return ERROR;
	}

	if (set->numid == MAX_ID)
	{
		return ERROR;
	}

	for (i = 0; i < set->numid && st == OK; i++)
	{
		aux = set->id[i];
		if (aux == id)
		{
			st = ERROR;
		}
	}
	if (st == ERROR)
	{
		return ERROR;
	}

	set->id[set->numid] = id;

	set->numid++;

	return OK;
}

STATUS set_del(Set *set, Id id)
{
	int i;
	Id aux;
	STATUS st = ERROR;
	if (!set || id == NO_ID)
	{
		return ERROR;
	}

	if (set->numid == 0)
	{
		return ERROR;
	}

	for (i = 0; i < set->numid && st == ERROR; i++)
	{
		aux = set->id[i];
		if (aux == id)
		{
			st = OK;
			set->id[i] = set->id[set->numid - 1];
			set->id[set->numid - 1] = NO_ID;
			set->numid--;
		}
	}

	if (st == ERROR)
	{
		return ERROR;
	}

	return OK;
}

STATUS set_print(Set *set)
{
	int i;
	if (!set)
	{
		return ERROR;
	}

	for (i = 0; i < set->numid; i++)
	{
		fprintf(stdout, "%ld ", set->id[i]);
	}

	fprintf(stdout, "%d\n", set->numid);

	return OK;
}