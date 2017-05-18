/* -----------------------------------------------------------------------
 * Assignment 3
 * unittest3.c
 * Shreyans Khunteta
 *
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 *
 * -----------------------------------------------------------------------
 */

// unit testing for the scoreFor function
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// int scoreFor (int player, struct gameState *state)
// returns the point total from a player's hand, deck, and discard pile
int main() {
    printf("\n####################\n");
    printf("Unit test 3 - scoreFor()\n");

    int i, p, r, testReturn;
    int seed = 999;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int handCount = 5;
    int discardCount = 10;
    int deckCount = 15;
    int estates[MAX_HAND];
    int great_halls[MAX_HAND];
    int gardenses[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        estates[i] = estate;
        great_halls[i] = great_hall;
        gardenses[i] = gardens;
    }

    // cycle through each player
    for (p = 0; p < numPlayer; p++) {
        printf("\n--- Testing player %d\n", p);

        memset(&G, 23, sizeof(struct gameState));
        r = initializeGame(numPlayer, k, seed, &G);
        G.handCount[p] = handCount;
        G.discardCount[p] = discardCount;
        G.deckCount[p] = deckCount;

        printf("TEST 1: Testing Estates: 5 in hand, 10 in discard, 15 in deck\n");
        memcpy(G.hand[p], estates, sizeof(int) * handCount);
        memcpy(G.discard[p], estates, sizeof(int) * discardCount);
        memcpy(G.deck[p], estates, sizeof(int) * deckCount);

        testReturn = scoreFor(p, &G);
        if (testReturn == 30)
            printf("scoreFor() passes -  returned score 30\n");
        else
            printf("scoreFor() fails -  returned score %d, expected 30\n", testReturn);

        printf("TEST 2: Testing Great Halls: 5 in hand, 10 in discard, 15 in deck\n");
        memcpy(G.hand[p], great_halls, sizeof(int) * handCount);
        memcpy(G.discard[p], great_halls, sizeof(int) * discardCount);
        memcpy(G.deck[p], great_halls, sizeof(int) * deckCount);

        testReturn = scoreFor(p, &G);
        if (testReturn == 180)
            printf("scoreFor() passes -  returned score 180\n");
        else
            printf("scoreFor() fails -  returned score %d, expected 180\n", testReturn);


        printf("TEST 3: Testing Gardens: 5 in hand, 10 in discard, 15 in deck\n");
        memcpy(G.hand[p], gardenses, sizeof(int) * handCount);
        memcpy(G.discard[p], gardenses, sizeof(int) * discardCount);
        memcpy(G.deck[p], gardenses, sizeof(int) * deckCount);


        testReturn = scoreFor(p, &G);
        if (testReturn == 90)
            printf("scoreFor() passes -  returned score 90\n");
        else
            printf("scoreFor() fails -  returned score %d, expected 90\n", testReturn);
    }
    return 0;
}