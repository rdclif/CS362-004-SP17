
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// returns 0 for a successful return

void assertEqual(int before, int after, int testNum)
{
	if(before == after)
	{
		printf("\n----------------- Test #%d: Passed -----------------\n", testNum);
	}
	else{
		printf("\n----------------- Test #%d: Failed -----------------\n", testNum);
	}
}

int main() {


	printf("Working on it.");
   /* printf("\n####################\n");
    printf("Card test (unit test) - Adventurer\n");

    // set function parameters
    int i, p, z, cardDrawn;
    int seed = 999;
    int numPlayer = 2;
    struct gameState G;
    int drawntreasure = 0;
    int tempHand[MAX_HAND];
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int handCount = 5;
    int deckCount = 3;
    int silvers[MAX_HAND];
    int estates[MAX_HAND];
    int adventurers[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        silvers[i] = silver;
        estates[i] = estate;
        adventurers[i] = adventurer;
    }

    for (p = 0; p < numPlayer; p++) {
        printf("\n--- Testing player %d\n", p);

        // clear gameState, set the hand
        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k, seed, &G);
        G.handCount[p] = handCount;
        memcpy(G.hand[p], adventurers, sizeof(int) * handCount);    // all cards in hand are adventurers, can be counted later
        G.deckCount[p] = deckCount;
        memcpy(G.deck[p], estates, sizeof(int));          // this estate will be drawn but should not remain in hand
        for (i = 1; i < 3; i++)
            memcpy(G.deck[p], silvers, sizeof(int));      // the cards we are looking for in hand will be silvers

	printf("-- Testing successful return\n");
        assert(playAdventurer(&G, p, drawntreasure, tempHand, z, cardDrawn) == 0);
        printf("adventurerEffect(): PASS successful return\n");

	printf("These cards are in hand:\n");
        int count = 0;
        for (i = 0; i < G.handCount[p]; i++) {
	    printf("%d\n", G.hand[p][i]);
            if (G.hand[p][i] == adventurer)
                count++;
        }
        if (count == 4)
            printf("playAdventurer(): PASS adventurer discarded from hand\n");
        else
            printf("playadventurer(): FAIL adventurer card is still in hand\n");

        count = 0;
        for (i = 0; i < G.handCount[p]; i++) {
            if (G.hand[p][i] == silver)
                count++;
        }
        if (count == 2)
            printf("playAdventurer(): PASS 2 silvers found in hand\n");
        else
            printf("playAdventurer(): FAIL expected 2 silvers in hand, found %d\n", count);
    }
    
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
*/
    return 0;
}

