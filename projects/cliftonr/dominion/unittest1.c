//
// Created by Robert Clifton on 4/18/17.
//unittest1  unit test for the handCard function.
//
//to make and test: make unittestresults.out
//

//gcc dominion.c rngs.c unittest1.c -o unittest1

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

    int pass = 1;
    int i, z;
    int x = 1000;
    int retVal;


    char testFunction[] = "handCard()";
    struct gameState G, copyG;
    int randSeed = 2;
    int numbPlayers = 2;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    initializeGame(numbPlayers, k, randSeed, &G);


    printf("\n->->->    - TESTING FUNCTION: %s -    <-<-<-\n\n", testFunction);

    //basic test of return value
    printf("\n----  - TEST 1: Return Value -  ----\n\n");
    z = 0;
    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        copyG.whoseTurn = 0;
        retVal = handCard(z, &copyG);
        if (retVal != G.hand[0][z]) {
            printf("TEST 1 Fail");
            pass = 0;
        }
        z++;
        if (z > copyG.handCount[0]) {
            z = 0;
        }
    }
    printf("Return Value: %d, Expected: %d \n\n", retVal, 0);

    //Test the card values after running function on copied struct
    printf("\n----  - TEST 2: Test Values-  ----\n\n");
    z = 0;
    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        copyG.whoseTurn = 0;
        handCard(z, &copyG);
        z++;
        if (z > copyG.handCount[0]) {
            z = 0;
        }
    }
    x = G.handCount[0];
    for (i = 0; i < x; i++ ) {
        printf("Card Val: %d, Expected: %d\n\n", copyG.hand[0][i], G.hand[0][i]);
        if (copyG.hand[0][i]!= G.hand[0][i]) {
            pass = 0;
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