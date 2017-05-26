//
// Created by Robert Clifton on 4/18/17.
//unittest4  unit test for the isGameOver function.
//
//to make and test: make unittestresults.out
//
//gcc dominion.c rngs.c unittest4.c -o unittest4

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    int pass = 1;
    char testFunction[] = "isGameOver()";
    struct gameState G, copyG;
    int x = 1000;
    int i;
    int retVal;

    int randSeed = 2;
    int numbPlayers = 2;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    initializeGame(numbPlayers, k, randSeed, &G);

    printf("\n->->->    - TESTING CARD: %s -    <-<-<-\n\n", testFunction);

    //basic test of return value
    printf("\n----  - TEST 1: Return Value = 0 -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    for (i = 0; i < x; i++) {
        retVal = isGameOver(&copyG);
        if (retVal != 0) {
            printf("test 1 fail Return != 0");
            pass = 0;
        };
    }

    //test when two supply piles are at 0
    printf("\n----  - TEST 2: Two Supply Piles = 0 -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    //set supply count of two piles to  0;
    copyG.supplyCount[1] = 0;
    copyG.supplyCount[2] = 0;

    for (i = 0; i < x; i++) {
        retVal = isGameOver(&copyG);
        if (retVal != 0) {
            printf("test 2 fail Return != 0");
            pass = 0;
        };
    }

    //test when province pile count is at 0
    printf("\n----  - TEST 3: Province Count = 0 -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    copyG.supplyCount[province] = 0;

    for (i = 0; i < x; i++) {
        retVal = isGameOver(&copyG);
        if (retVal != 1) {
            printf("test 3 fail Return != 1");
            pass = 0;
        };
    }

    //test when > three supply piles are at 0
    printf("\n----  - TEST 4 > Three Supply Piles = 0 -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    copyG.supplyCount[duchy] = 0;
    copyG.supplyCount[estate] = 0;
    copyG.supplyCount[copper] = 0;
    copyG.supplyCount[gold] = 0;

    for (i = 0; i < x; i++) {
        retVal = isGameOver(&copyG);
        if (retVal != 1) {
            printf("test 4 fail Return != 1");
            pass = 0;
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