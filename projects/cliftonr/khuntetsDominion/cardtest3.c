#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Village"


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

int main()
{
	int newCards = 0;
    int discarded = 1;
	int buy = 0;
	
    int j;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	
	//Kingdom cards
	int k[10] = {adventurer, embargo, village, minion, mine, 
				cutpurse, sea_hag, tribute, smithy, council_room};

						
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);


    printf("\n####################\n");
    
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	printf("TEST 1: player 1 receives +4 cards\n");
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	newCards = 4;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], 
	G.handCount[thisPlayer] + newCards - discarded);
	assertEqual(testG.handCount[thisPlayer], 
	G.handCount[thisPlayer] + newCards - discarded, 1);
	
	printf("TEST 2: player 1 gets +1 card\n");
	
	buy++;
	printf("buy count = %d, expected = %d\n", 
	testG.numBuys, G.numBuys + buy);
	assertEqual(testG.numBuys, G.numBuys + buy, 2);
	
	printf("TEST 3: State change should occur for other players\n");
	printf("player 2 hand count = %d, expected = %d\n", 
	testG.handCount[thisPlayer+1], G.handCount[thisPlayer+1] + 1);
	
	assertEqual(testG.handCount[thisPlayer+1], 
	G.handCount[thisPlayer+1] + 1, 3);
	
	printf("player 2 deck count = %d, expected = %d\n", 
	testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer+1] - 1);
	assertEqual(testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer+1] - 1, 3);

	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}