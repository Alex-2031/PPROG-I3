#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "die.h"

/**
* @brief Estructura que contiene los datos del dado: id, valor máximo, valor mínimo y último resultado
*
* @param max_die valor máximo del dado
* @param min_die valor mínimo del dado
* @param last_num último valor del dado
* @param id id del dado
* @date 01-03-2021
* @author: Manuel Ardid Clavería
*/
typedef struct _Die
{
    int max_die;
    int min_die;
    int last_num;
    Id id;
} Die;

Die *die_create(Id id, int max, int min)
{

    if (!max || !min)
        return NULL;

    Die *NewDie = NULL;

    NewDie = (Die *)malloc(sizeof(Die));
    if (NewDie == NULL)
        return NULL;

    NewDie->max_die = max;
    NewDie->min_die = min;
    NewDie->id = id;
    NewDie->last_num = 0;

    return NewDie;
}

STATUS die_destroy(Die *die)
{
    if (!die)
        return ERROR;

    free(die);

    die = NULL;

    return OK;
}

Id die_get_id(Die *die)
{
    if (!die)
        return NO_ID;

    return die->id;
}

int die_get_min(Die *die)
{
    if (!die)
        return -1;

    return die->min_die;
}

int die_get_max(Die *die)
{
    if (!die)
        return -1;

    return die->max_die;
}

int die_get_last_num(Die *die)
{
    if (!die)
        return -1;

    return die->last_num;
}

STATUS die_roll(Die *die)
{
    if (!die)
        return ERROR;

    srand(time(NULL));

    die->last_num = 1 + rand() % die->max_die;

    return OK;
}

STATUS die_print(Die *die)
{
    if (!die)
    {
        return ERROR;
    }

    fprintf(stdout, "--> Die (Id: %ld; Max: %d; Min: %d; Last_num: %d)\n", die->id, die->max_die, die->min_die, die->last_num);

    return OK;
}