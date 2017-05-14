//
// Created by Robert Clifton
//randomtestcard1 - random test for smithy card function
//
//to make and test: make randomtestcard1.out
//
//gcc dominion.c rngs.c randomtestcard1.c -o randomtestcard1

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

    int pass = 1;
    char testCard[] = "smithy";
    struct gameState G, copyG;
    //int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	int x = 1000;
    int i, n, retVal;
    int handPos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int bonus = 0;
	int currentPlayer;
	int addedCards = 3;
	int discard = 1;
	int totalCards, copytotalCards;


	//initialize random
	srand(time(NULL));


    printf("\n->->->    - TESTING CARD: %s -    <-<-<-\n", testCard);

	printf ("----  -RANDOM TESTS- ----\n");

	//fill game struct with random numbers
	for (i = 0; i < x; i++){
		for (n = 0; n < sizeof(struct gameState)/ sizeof(int); n++) {
			((int*)&G)[n] = rand() % 128;
		}

		//set important struct vars to valid random input
		G.numPlayers = (rand() % 3)+2;
		G.whoseTurn = rand() % G.numPlayers;
		currentPlayer = whoseTurn(&G);
		G.handCount[currentPlayer] = (rand() % (MAX_HAND/2))+1;
		G.deckCount[currentPlayer] = (rand() % (MAX_DECK/2))+1;
		G.discardCount[currentPlayer] = (rand() % (MAX_DECK/2))+1;
		handPos = (rand() % G.handCount[currentPlayer]);

		//copy struct for testing and compare
		memcpy(&copyG, &G, sizeof(struct gameState));

		//test return value
		retVal = cardEffect(smithy, choice1, choice2, choice3, &copyG, handPos, &bonus);
		if (retVal != 0) {
			printf("Return Fail");
			pass = 0;
		};

		//test hand count
		if (copyG.handCount[currentPlayer] != G.handCount[currentPlayer]+addedCards-discard){
			pass = 0;
			printf("Hand Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer], G.handCount[currentPlayer]+addedCards-discard);
		}

		//test deck and discard count
		totalCards = G.deckCount[currentPlayer] + G.discardCount[currentPlayer];
		copytotalCards = copyG.deckCount[currentPlayer] + copyG.discardCount[currentPlayer];
		if (copytotalCards != totalCards - addedCards) {
			pass = 0;
			printf("Total Cards: %d, Expected: %d \n\n", copytotalCards, totalCards-addedCards);
		};

    }


    //Final bool check to see if testing passed or failed,  prints result to standard out
    if (pass) {
        printf("->->  - TEST SUCCESSFULLY COMPLETED -  <-<-\n");
    } else{
        printf("->->  - TEST FAILED -  <-<-\n");
    }

    return 0;
};