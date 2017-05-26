//
// Created by Robert Clifton on 4/18/17.
//cardtest4  unit test for the feast card function.
//
//to make and test: make unittestresults.out
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

    int pass = 1;
    char testCard[] = "feast";
    struct gameState G, copyG;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};
    int x = 1000;
    int i, retVal;
    int numbPlayers = 2;
    int randSeed = 2;
    int handPos = 0;
    int choice1 = 5, choice2 = 0, choice3 = 0;
    int bonus = 0;


    //initialize game state
    initializeGame(numbPlayers, k, randSeed, &G);


    printf("\n->->->    - TESTING CARD: %s -    <-<-<-\n\n", testCard);

    //basic test of return value
    printf("\n----  - TEST 1: Function Return  -  ----\n\n");

    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        retVal = cardEffect(feast, choice1, choice2, choice3, &copyG, handPos, &bonus);
        if (retVal != 0) {
            pass = 0;
            break;
        };
    };
    printf("Return Value: %d, Expected: %d \n\n", retVal, 0);

    //test and compare hand count in copied struct
    printf("\n----  - TEST 2: Hand Count  -  ----\n\n");

    int currentPlayer = whoseTurn(&G);

    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        cardEffect(feast, choice1, choice2, choice3, &copyG, handPos, &bonus);
        if (copyG.handCount[currentPlayer] != G.handCount[currentPlayer]) {
            pass = 0;
            break;
        };
    };

    printf("Hand Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer], G.handCount[currentPlayer]);

    //test result when player choie <= 0
    printf("\n----  - TEST 3: Choice1 <= 0 -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    int addedCard = 1;
    choice1 = 0;
    currentPlayer = whoseTurn(&G);

    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        cardEffect(feast, choice1, choice2, choice3, &copyG, handPos, &bonus);
        if (copyG.handCount[currentPlayer] != G.handCount[currentPlayer]) {
            pass = 0;
            break;
        };
    };

    printf("Deck Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer]+copyG.deckCount[currentPlayer]+ copyG.discardCount[currentPlayer], G.handCount[currentPlayer]+ G.deckCount[currentPlayer]+ G.discardCount[currentPlayer]+addedCard);

    //test result when player choie <= 5
    printf("\n----  - TEST 4: Choice1 <= 5 -  ----\n\n");

    choice1 = 5;
    currentPlayer = whoseTurn(&G);

    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        cardEffect(feast, choice1, choice2, choice3, &copyG, handPos, &bonus);

        if (copyG.handCount[currentPlayer] != G.handCount[currentPlayer]) {
            pass = 0;
            break;
        };
    };
    printf("Deck Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer]+copyG.deckCount[currentPlayer]+ copyG.discardCount[currentPlayer], G.handCount[currentPlayer]+ G.deckCount[currentPlayer]+ G.discardCount[currentPlayer]+addedCard);

    //test result when player choie > 5
    printf("\n----  - TEST 5: Choice1 > 5 -  ----\n\n");

    choice1 = 6;
    currentPlayer = whoseTurn(&G);

    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        cardEffect(feast, choice1, choice2, choice3, &copyG, handPos, &bonus);

        if (copyG.handCount[currentPlayer] != G.handCount[currentPlayer]) {
            pass = 0;
            break;
        };
    };
    printf("Deck Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer]+copyG.deckCount[currentPlayer]+ copyG.discardCount[currentPlayer], G.handCount[currentPlayer]+ G.deckCount[currentPlayer]+ G.discardCount[currentPlayer]+addedCard);

    //test result when player card supply <= 0
    printf("\n----  - TEST 6: Supply <= 0 -  ----\n\n");

    choice1 = 0;
    currentPlayer = whoseTurn(&G);

    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        copyG.supplyCount[0] = 0;
        cardEffect(feast, choice1, choice2, choice3, &copyG, handPos, &bonus);

        if (copyG.handCount[currentPlayer] == G.handCount[currentPlayer]) {
            pass = 0;
            break;
        };
    };

    //Final bool check to see if testing passed or failed,  prints result to standard out
    printf("Deck Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer]+copyG.deckCount[currentPlayer]+ copyG.discardCount[currentPlayer], G.handCount[currentPlayer]+ G.deckCount[currentPlayer]+ G.discardCount[currentPlayer]+addedCard);
    if (pass) {
        printf("->->  - TEST SUCCESSFULLY COMPLETED -  <-<-\n");
    } else{
        printf("->->  - TEST FAILED -  <-<-\n");
    }

    return 0;
};