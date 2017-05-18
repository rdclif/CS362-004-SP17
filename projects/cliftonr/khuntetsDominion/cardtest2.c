
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


#define TESTCARD "Smithy"

//int smithyEffect(struct gameState *state, int currentPlayer, int handPos);
// returns 0 on normal exit
// should add three cards to hand
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
    printf("\n####################\n");
    
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    int handCount = 1;
    int deckCount = 3;
    int coppers[MAX_HAND];
    int smithys[MAX_HAND];
    int testSmithy;
    int i, p;
    int seed = 999;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    for (i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
        smithys[i] = smithy;
    }

    // cycle through each player
    for (p = 0; p < numPlayer; p++) {
        printf("\nTesting player %d\n", p);

		//now for the actual cycling.
        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k, seed, &G);
        //keep a counter to track hand and deck.
        G.handCount[p]  = handCount;
        G.deckCount[p] = deckCount;
        // There is a single Smithy in hand
        memcpy(G.hand[p], smithys, sizeof(int) * handCount);
        // and three Coppers in deck available to draw
        memcpy(G.deck[p], coppers, sizeof(int) * deckCount);

        printf("TEST 1: Testing successful return: \n");
    	testSmithy = smithyEffect(&G, p, 0);
    	if (testSmithy == 0)
            printf("playSmithy(): PASSED\n");
    	else
    	    printf("playSmithy(): FAILED\n");
    	    
        printf("TEST 2: Testing hand count\n");
        if (G.handCount[p] == 3)
            printf("smithyEffect(): PASSED - the hand holds 3 cards\n");
        else
            printf("smithyEffect(): FAIL - the hand holds %d cards, expected 3\n", G.handCount[p]);

        printf("TEST 3: Testing discard\n");
        if (G.handCount[p] > 0) {
            int count = 0;
            for (i = 0; i < G.handCount[p]; i++) {
                if (G.hand[p][i] == smithy)
                    count++;
            }
            if (count != 0)
                printf("smithyEffect(): FAIL smithy card has not been discarded\n");
            else
                printf("smithyEffect(): PASS smithy card has been discarded\n");
        }
        else
            printf("smithyEffect(): PASS smithy card has been discarded\n");

    }

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
    return 0;
}