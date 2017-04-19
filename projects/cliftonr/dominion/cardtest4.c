//
// Created by Robert Clifton on 4/18/17.
//

//gcc dominion.c rngs.c cardtest4.c -o cardtest4

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

    char testCard[] = "feast";
    struct gameState G, copyG;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    int numbPlayers = 2;
    int randSeed = 2;
    int handPos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int bonus = 0;


    //initialize game state
    initializeGame(numbPlayers, k, randSeed, &G);


    printf("\n->->->    - TESTING CARD: %s -    <-<-<-\n\n", testCard);
    printf("\n----  - TEST 1: Function Return  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    int retVal = cardEffect(feast, choice1, choice2, choice3, &copyG, handPos, &bonus);

    printf("Return Value: %d, Expected: %d \n\n", retVal, 0);
    assert(retVal == 0);

    printf("\n----  - TEST 2: Hand Count  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    int addedCards = 3;
    int discard = 1;
    int currentPlayer = whoseTurn(&G);
    cardEffect(smithy, choice1, choice2, choice3, &copyG, handPos, &bonus);

    printf("Hand Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer], G.handCount[currentPlayer]+addedCards-discard);
    assert(copyG.handCount[currentPlayer] == G.handCount[currentPlayer]+addedCards-discard);

    printf("->->  - TEST SUCCESSFULLY COMPLETED -  <-<-\n");

    return 0;
};