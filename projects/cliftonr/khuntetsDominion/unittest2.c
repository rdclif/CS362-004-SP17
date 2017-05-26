//
// Created by Robert Clifton on 4/18/17.
//unittest2  unit test for the fullDeckCount function.
//
//to make and test: make unittestresults.out
//
//gcc dominion.c rngs.c unittest2.c -o unittest2

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

    int pass = 1;
    int i;
    int x = 1000;
    int retVal;


    char testFunction[] = "fullDeckCount()";
    struct gameState G, copyG;
    int randSeed = 2;
    int numbPlayers = 2;
    int player = 0;
    int card = 0;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    initializeGame(numbPlayers, k, randSeed, &G);


    printf("\n->->->    - TESTING FUNCTION: %s -    <-<-<-\n\n", testFunction);

    //basic test of return value
    printf("\n----  - TEST 1:  Return Value -  ----\n\n");

    memcpy(&copyG, &G, sizeof(struct gameState));


    for (i = 0; i < x; i++) {
        retVal = fullDeckCount(player, card, &copyG);
        if (retVal != 0) {
            printf("Test 1 Fail\n");
            pass = 0;
        }
    }
    printf("Return Value: %d, Expected: %d \n\n", retVal, 0);

    //test and compare hand count in copied struct
    printf("\n----  - TEST 2: Hand Count  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    card = 4;

    for (i = 0; i < x; i++) {
        fullDeckCount(player, card, &copyG);
        if (copyG.handCount[player] != G.handCount[player]) {
            printf("test 2 hand count fail, Got: %d, Expected: %d\n", copyG.handCount[player], G.handCount[player]);
            pass = 0;
        };
    }

    printf("Hand Count: %d, Expected: %d \n\n", copyG.handCount[player], G.handCount[player]);

    //test and compare deck count in copied struct
    printf("\n----  - TEST 3: Deck Count  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    card = 3;

    for (i = 0; i < x; i++) {
        fullDeckCount(player, card, &copyG);
        if (copyG.deckCount[player] != G.deckCount[player]) {
            printf("test 2 hand count fail, Got: %d, Expected: %d\n", copyG.deckCount[player], G.deckCount[player]);
            pass = 0;
        };
    }

    printf("Deck Count: %d, Expected: %d \n\n", copyG.deckCount[player], G.deckCount[player]);

    //test and compare deck count in copied struct
    printf("\n----  - TEST 4: Discard Count  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    card = 5;

    for (i = 0; i < x; i++) {
        fullDeckCount(player, card, &copyG);
        if (copyG.discardCount[player] != G.discardCount[player]) {
            printf("test 2 hand count fail, Got: %d, Expected: %d\n", copyG.discardCount[player], G.discardCount[player]);
            pass = 0;
        };
    }

    printf("Deck Count: %d, Expected: %d \n\n", copyG.discardCount[player], G.discardCount[player]);

    //Final bool check to see if testing passed or failed,  prints result to standard out
    if (pass) {
        printf("->->  - TEST SUCCESSFULLY COMPLETED -  <-<-\n");
    } else{
        printf("->->  - TEST FAILED -  <-<-\n");
    }

    return 0;
};
