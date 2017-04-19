//
// Created by Robert Clifton on 4/18/17.
//

//gcc dominion.c rngs.c cardtest3.c -o cardtest3

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

    char testCard[] = "council_room";
    struct gameState G, copyG;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};
    int i;
    int numbPlayers = 2;
    int randSeed = 10000000;
    int handPos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int bonus = 0;


    //initialize game state
    initializeGame(numbPlayers, k, randSeed, &G);


    printf("\n->->->    - TESTING CARD: %s -    <-<-<-\n\n", testCard);
    printf("\n----  - TEST 1: Function Return  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    int retVal = cardEffect(council_room, choice1, choice2, choice3, &copyG, handPos, &bonus);

    printf("Return Value: %d, Expected: %d \n\n", retVal, 0);
    assert(retVal == 0);

    printf("\n----  - TEST 2: Hand Count  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    int addedCards = 4;
    int discard = 1;
    int currentPlayer = whoseTurn(&G);
    cardEffect(council_room, choice1, choice2, choice3, &copyG, handPos, &bonus);

    printf("Hand Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer], G.handCount[currentPlayer]+addedCards-discard);
    assert(copyG.handCount[currentPlayer] == G.handCount[currentPlayer]+addedCards-discard);


    printf("\n----  - TEST 3: Number of Buys  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    int addedBuys = 1;
    currentPlayer = whoseTurn(&G);
    cardEffect(council_room, choice1, choice2, choice3, &copyG, handPos, &bonus);

    printf("Buy Count: %d, Expected: %d \n\n", copyG.numBuys, G.numBuys+addedBuys);
    assert(copyG.numBuys == G.numBuys+addedBuys);

    printf("\n----  - TEST 4: Other Player Draw -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    int playerHand[4];
    int copyPlayerHand[4];
    addedCards = 1;
    currentPlayer = whoseTurn(&G);
    cardEffect(council_room, choice1, choice2, choice3, &copyG, handPos, &bonus);

    for (i = 0; i < G.numPlayers; i++)
    {
        if ( i != currentPlayer )
        {
            copyPlayerHand[i] = copyG.handCount[i];
            playerHand[i] =  G.handCount[i];
        }
    }


    for (i = 0; i < G.numPlayers; i++)
    {
        if ( i != currentPlayer )
        {
            printf("Player %d Hand Count: %d, Expected: %d \n\n", i+1, copyPlayerHand[i], playerHand[i]+addedCards);
            assert(copyPlayerHand[i] == playerHand[i]+addedCards);
        }
    }

    printf("->->  - TEST SUCCESSFULLY COMPLETED -  <-<-\n");

    return 0;
};