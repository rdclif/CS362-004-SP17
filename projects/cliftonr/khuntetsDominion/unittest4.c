/* -----------------------------------------------------------------------
 * Assignment 3
 * unittest4.c
 * Shreyans Khunteta
 *
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 *
 * -----------------------------------------------------------------------
 */

// unit testing the function isGameOver
#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// int isGameOver(struct gameState *state)
// returns 0 if the game is not over
// returns -1 if the game is over:
// the province supply is empty
// or three of the supply piles are empty
int main() {
    printf("\n###################\n");
    printf("Unit test 4 - shuffle()\n");

    int p, testOver;
    int seed = 999;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;

    for (p = 0; p < numPlayer; p++) {
        printf("\n--- Testing player %d\n", p);

        // clear the gameState
        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k, seed, &G);

        printf("TEST 1: Testing incomplete game\n");
        testOver = isGameOver(&G);
        if (testOver == 0)
            printf("isGameOver() passes -  game will continue\n");
        else
            printf("isGameOver() fails -  game ended incorrectly\n");

        printf("TEST 2: Testing empty Province pile "
         "as that ends the game\n");
        G.supplyCount[province] = 0;
        testOver = isGameOver(&G);
        if (testOver == 1)
            printf("isGameOver() passes -  game ended correctly\n");
        else
            printf("isGameOver() fails -  game continues\n");

        printf("TEST 3: Testing three empty supply piles\n");
        G.supplyCount[4] = 0;
        testOver = isGameOver(&G);
        if (testOver == 1)
            printf("isGameOver() passes -  game ended correctly\n");
        else
            printf("isGameOver() fails -  game continues\n");
    }
    return 0;
}