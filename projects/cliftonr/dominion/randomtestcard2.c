//
// Created by Robert Clifton
//randomtestcard2  - random test for council room card function
//
//to make and test: make randomtestcard2.out
//
//gcc dominion.c rngs.c randomtestcard2.c -o randomtestcard2

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
    char testCard[] = "council_room";
    struct gameState G, copyG;
    //int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    int x = 1000;
    int i, n, retVal;
    int handPos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int bonus = 0;
    int currentPlayer;
    int addedCards = 4;
    int discard = 1;
    int addedBuys = 1;
    int otherPlrAdded = 1;
    int playerHand[4];
    int copyPlayerHand[4];
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
        G.numBuys = 0;
        handPos = (rand() % G.handCount[currentPlayer]);


        //copy struct for testing and compare
        memcpy(&copyG, &G, sizeof(struct gameState));

        //test return value
        retVal = cardEffect(council_room, choice1, choice2, choice3, &copyG, handPos, &bonus);
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

        //test buy count
        if (copyG.numBuys != G.numBuys + addedBuys) {
            pass = 0;
            printf("Buy Count: %d, Expected: %d \n\n", copyG.numBuys, G.numBuys+addedBuys);
        }

        for (n = 0; n < G.numPlayers; n++) {
            if (n != currentPlayer) {
                copyPlayerHand[n] = copyG.handCount[n];
                playerHand[n] = G.handCount[n];
            }
        }

        //test the other players hand count
        for (n = 0; n < G.numPlayers; n++) {
            if (n != currentPlayer) {
                if (copyPlayerHand[n] != playerHand[n] + otherPlrAdded) {
                    pass = 0;
                    //printf("%d, %d, %d, %d, %d", G.numPlayers, G.whoseTurn, G.handCount[currentPlayer], G.deckCount[currentPlayer], G.discardCount[currentPlayer]);
					printf("Other Player Hand Count: %d, Expected: %d \n\n", copyPlayerHand[n],  playerHand[n] + otherPlrAdded);
                }
            }
        }
    
    }


    //Final bool check to see if testing passed or failed,  prints result to standard out
    if (pass) {
        printf("->->  - TEST SUCCESSFULLY COMPLETED -  <-<-\n");
    } else{
        printf("->->  - TEST FAILED -  <-<-\n");
    }

    return 0;
};