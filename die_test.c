/** 
 * @brief It tests die module
 * 
 * @file die_test.c
 * @author Manuel Ardid Clavería
 * @date 01-03-2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "die_test.h"
#include "die.h"
#include "types.h"
#include "test.h"

#define MAX_TESTS 40
#define ID_TEST 0
#define MAX_TEST 6
#define MIN_TEST 1

/** 
 * @brief Main function for DIE unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
int main(int argc, char **argv)
{

    int test = 0;
    int all = 1;

    if (argc < 2)
    {
        printf("Running all test for module die:\n");
    }
    else
    {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS)
        {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1)
        test1_die_create();
    if (all || test == 2)
        test2_die_create();
    if (all || test == 3)
        test1_die_get_id();
    if (all || test == 4)
        test2_die_get_id();
    if (all || test == 5)
        test1_die_get_min();
    if (all || test == 6)
        test2_die_get_min();
    if (all || test == 7)
        test1_die_get_max();
    if (all || test == 8)
        test2_die_get_max();
    if (all || test == 9)
        test1_die_get_last_num();
    if (all || test == 10)
        test2_die_get_last_num();
    if (all || test == 11)
        test1_die_roll();
    if (all || test == 12)
        test2_die_roll();
    if (all || test == 13)
        test1_die_print();
    if (all || test == 14)
        test2_die_print();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_die_create()
{
    Die *d;
    d = die_create(ID_TEST, MAX_TEST, MIN_TEST);
    PRINT_TEST_RESULT(d !=NULL);
    die_destroy(d);
}

void test2_die_create()
{
    Die *d;
    d = die_create(ID_TEST, MAX_TEST, MIN_TEST);
    PRINT_TEST_RESULT(die_get_id(d) == ID_TEST);
}

void test1_die_get_id()
{
    Die *d;
    d = die_create(ID_TEST, MAX_TEST, MIN_TEST);
    PRINT_TEST_RESULT(die_get_id(d) == ID_TEST);
    die_destroy(d);
}

void test2_die_get_id()
{
    Die *d = NULL;
    PRINT_TEST_RESULT(die_get_id(d) != ID_TEST);
}

void test1_die_get_min()
{
    Die *d = NULL;
    PRINT_TEST_RESULT(die_get_min(d) != MIN_TEST);
}

void test2_die_get_min()
{
    Die *d;
    d = die_create(ID_TEST, MAX_TEST, MIN_TEST);
    PRINT_TEST_RESULT(die_get_min(d) == MIN_TEST);
    die_destroy(d);
}

void test1_die_get_max()
{
    Die *d = NULL;
    PRINT_TEST_RESULT(die_get_max(d) != MAX_TEST);
}

void test2_die_get_max()
{
    Die *d;
    d = die_create(ID_TEST, MAX_TEST, MIN_TEST);
    PRINT_TEST_RESULT(die_get_max(d) == MAX_TEST);
    die_destroy(d);
}

void test1_die_get_last_num()
{
    Die *d = NULL;
    PRINT_TEST_RESULT(die_get_last_num(d) == -1);
}

void test2_die_get_last_num()
{
    Die *d;
    STATUS st = ERROR;
    d = die_create(ID_TEST, MAX_TEST, MIN_TEST);
    die_roll(d);

    if(die_get_last_num(d) > MIN_TEST - 1 && die_get_last_num(d) < MAX_TEST + 1)
    st = OK;

    PRINT_TEST_RESULT(st == OK);
    die_destroy(d);
}

void test1_die_roll()
{
    Die *d = NULL;
    PRINT_TEST_RESULT(die_roll(d) == ERROR);
}

void test2_die_roll()
{
    Die *d;
    d = die_create(ID_TEST, MAX_TEST, MIN_TEST);
    PRINT_TEST_RESULT(die_roll(d) == OK);
    die_destroy(d);
}

void test1_die_print()
{
    Die *d = NULL;
    PRINT_TEST_RESULT(die_print(d) == ERROR);
}

void test2_die_print()
{
    Die *d = NULL;
    d = die_create(ID_TEST, MAX_TEST, MIN_TEST);
    PRINT_TEST_RESULT(die_print(d) == OK);
    die_destroy(d);
}
