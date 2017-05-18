/* -----------------------------------------------------------------------
 * Assignment 3
 * unittest2.c
 * Shreyans Khunteta
 *
 * Include the following lines in your makefile:
 *
 * unittest1: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 *
 * -----------------------------------------------------------------------
 */

// unit testing for the getCost function
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// getCost takes one parameter: int cardNumber
// it uses a switch to match the card with its cost, which is returned.
int main() {
    printf("\n####################\n");
    printf("Unit test 2 - getCost()\n");
    // to test these, we will simply pass any out of the 27 card types
    // and compare the results of the getCost function
    
    printf("TEST 1: Get cost of curse: \n ");
    if(getCost(0) == 0)
        printf("getCost passes - cost of Curse is correct\n");
    else
        printf("getCost() fails -  cost of Curse is incorrect\n");

	printf("TEST 2: Get cost of copper: \n");
    if(getCost(4) == 0)
        printf("getCost passes - cost of Copper is correct\n");
    else
        printf("getCost() fails -  cost of Copper is incorrect\n");

	printf("TEST 3: Get cost of silver: \n");
    if(getCost(5) == 3)
        printf("getCost passes - cost of Silver is correct\n");
    else
        printf("getCost() fails -  cost of Silver is incorrect\n");


    return 0;
}