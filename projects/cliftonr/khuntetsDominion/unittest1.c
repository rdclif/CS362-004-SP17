/* -----------------------------------------------------------------------
 * Assignment 3
 * unittest1.c
 * Shreyans Khunteta
 *
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// int buyCard(int supplyPos, struct gameState *state)
// returns 0 on normal exit if a card was purchased
// returns -1 if a card could not be purchased
int main() {
    printf("\n####################\n");
    printf("Unit test 1 - buyCard()\n");

    int i, p, r, testReturn;
    int seed = 999;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int preSupply = G.supplyCount[1];
    int handCount = 5;
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
        silvers[i] = silver;
	    golds[i] = gold;
    }

    // cycle through each player.
    for (p = 0; p < numPlayer; p++) {
        printf("\n--- Testing player %d\n", p);

        // clear the gameState for each character, then set relevant variables
        memset(&G, 23, sizeof(struct gameState));
        r = initializeGame(numPlayer, k, seed, &G);
        G.handCount[p] = handCount;
        memcpy(G.hand[p], coppers, sizeof(int) * handCount);
        
        G.numBuys = 2;
        updateCoins(p, &G, 0);

        printf("TEST 1: Testing successful buy\n");
        testReturn = buyCard(1, &G);
        if (testReturn == -1)
            printf("buyCard() fails -  expected function to return 0\n");
        else {
            printf("buyCard() passes -  function exited without error\n");

            // test numBuys decrement
            if (G.numBuys == 1)
                printf("buyCard() passes -  numBuys decremented after buy\n");
            else
                printf("buyCard() fails -  numBuys did not decrement\n");

            // test that payment has been taken
            if (G.coins == 0)
                printf("buyCard() passes -  currency was removed from hand\n");
            else
                printf("buyCard() fails -  currency was not removed from hand\n");

            if (G.handCount[p] == 6) {
            if (G.hand[p][5] == k[1])
                printf("buyCard() passes -  the correct card is found in hand\n");
            else
                printf("buyCard() fails -  incorrect card added to hand\n");
            }
            else
                printf("buyCard() fails -  no card added to hand\n");
        }

        printf("TEST 2: Testing unsuccessful buy (not enough coins)\n");
        G.coins = 0;
        testReturn = buyCard(1, &G);
        if (testReturn == -1)
            printf("buyCard() passes -  -1 return value\n");
        else
            printf("buyCard() fails -  unexpected 0 return value\n");

        printf("TEST 3: Testing unsuccessful buy (empty supply)\n");
        G.supplyCount[1] = 0;
        G.coins = 5;
        testReturn = buyCard(1, &G);
        if (testReturn == -1)
            printf("buyCard() passes -  -1 return value\n");
        else
            printf("buyCard() fails -  unexpected 0 return value\n");

    }

    return 0;
}