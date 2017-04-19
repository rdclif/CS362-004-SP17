//
// Created by Robert Clifton on 4/18/17.
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

    char testFunction[] = "";
    struct gameState G, copyG;

    printf("\n->->->    - TESTING CARD: %s -    <-<-<-\n\n", testFunction);
    printf("\n----  - TEST 1: -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    

    printf("Return Value: %d, Expected: %d \n\n", retVal, 0);
    assert(retVal == 0);

    printf("\n----  - TEST 2: Hand Count  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));


    printf("Hand Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer], G.handCount[currentPlayer]+addedCards-discard);
    assert(copyG.handCount[currentPlayer] == G.handCount[currentPlayer]+addedCards-discard);

    printf("->->  - TEST SUCCESSFULLY COMPLETED -  <-<-\n");

    return 0;
};