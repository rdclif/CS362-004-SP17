//
// Created by Robert Clifton on 4/18/17.
//cardtest1  unit test for the smity card function.
//
//to make and test: make unittestresults.out
//
//gcc dominion.c rngs.c cardtest1.c -o cardtest1

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

    int pass = 1;
    char testCard[] = "smithy";
    struct gameState G, copyG;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};
    int x = 1000;
    int i, n, r, p, deckCount, discardCount, handCount;
    int numbPlayers = 2;
    int randSeed = 2;
    int handPos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int bonus = 0;


    //initialize game state
    initializeGame(numbPlayers, k, randSeed, &G);


    printf("\n->->->    - TESTING CARD: %s -    <-<-<-\n\n", testCard);

    //basic test of return value
    printf("\n----  - TEST 1: Function Return  -  ----\n\n");


    for (n = 0; n < x; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        checkDrawCard(p, &G);
    }



    //Final bool check to see if testing passed or failed,  prints result to standard out
    if (pass) {
        printf("->->  - TEST SUCCESSFULLY COMPLETED -  <-<-\n");
    } else{
        printf("->->  - TEST FAILED -  <-<-\n");
    }

    return 0;
};