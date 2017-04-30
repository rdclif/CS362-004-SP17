//
// Created by Robert Clifton on 4/18/17.
//unittest3  unit test for the updateCoins function.
//
//to make and test: make unittestresults.out
//
//gcc dominion.c rngs.c unittest3.c -o unittest3

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

    char testFunction[] = "updateCoins()";
    struct gameState G, copyG;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    int pass = 1;
    int i, retVal;
    int x = 1000;
    int randSeed = 2;
    int numbPlayers = 2;
    int bonus = 0;
    int player = 0;

    //initialize game state
    initializeGame(numbPlayers, k, randSeed, &G);

    printf("\n->->->    - TESTING CARD: %s -    <-<-<-\n\n", testFunction);

    //basic test of return value
    printf("\n----  - TEST 1: Return Value -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    for (i = 0; i < x; i++) {
        retVal = updateCoins(player, &copyG, bonus);
        if (retVal != 0) {
            printf("test 1 fail Return != 0\n");
            pass = 0;
        };
    }

    printf("Return Value: %d, Expected: %d \n\n", retVal, 0);

    //test and compare hand count in copied struct
    printf("\n----  - TEST 2: Hand Count  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    for (i = 0; i < x; i++) {
        updateCoins(player, &copyG, bonus);
        if (copyG.handCount[player] != G.handCount[player]) {
            printf("test 2 hand count fail, Got: %d, Expected: %d\n", copyG.handCount[player], G.handCount[player]);
            pass = 0;
        };
    }

    printf("Hand Count: %d, Expected: %d \n\n", copyG.handCount[player], G.handCount[player]);

    //test count with copper coin cards
    printf("\n----  - TEST 3:Copper Coin Count -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    int z = copyG.handCount[player];
    int j;
    int coinValue = 1;
    int expectedCoinCount = z *coinValue;



    for (i = 0; i < x; i++) {
        //fill hand with copper coins
        for (j = 0; j < z; j++) {
            copyG.hand[player][j] = copper;
        }
        updateCoins(player, &copyG, bonus);
        if (copyG.coins != expectedCoinCount) {
            printf("test 3 coin count fail, Got: %d, Expected: %d\n", copyG.coins, expectedCoinCount);
            pass = 0;
        }
    }
    printf("Coins: %d, Expected: %d \n\n", copyG.coins, expectedCoinCount);

    //test count with silver coin cards
    printf("\n----  - TEST 4:Silver Coin Count -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    z = copyG.handCount[player];
    coinValue = 2;
    expectedCoinCount = z *coinValue;



    for (i = 0; i < x; i++) {
        //fill hand with silver coins
        for (j = 0; j < z; j++) {
            copyG.hand[player][j] = silver;
        }
        updateCoins(player, &copyG, bonus);
        if (copyG.coins != expectedCoinCount) {
            printf("test 4 coin count fail, Got: %d, Expected: %d\n", copyG.coins, expectedCoinCount);
            pass = 0;
        }
    }
    printf("Coins: %d, Expected: %d \n\n", copyG.coins, expectedCoinCount);

    //test count with gold coin cards
    printf("\n----  - TEST 5:Gold Coin Count -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    z = copyG.handCount[player];
    coinValue = 3;
    expectedCoinCount = z *coinValue;



    for (i = 0; i < x; i++) {
        //fill hand with gold coins
        for (j = 0; j < z; j++) {
            copyG.hand[player][j] = gold;
        }
        updateCoins(player, &copyG, bonus);
        if (copyG.coins != expectedCoinCount) {
            printf("test 5 coin count fail, Got: %d, Expected: %d\n", copyG.coins, expectedCoinCount);
            pass = 0;
        }
    }
    printf("Coins: %d, Expected: %d \n\n", copyG.coins, expectedCoinCount);

    //test count with mixed cards
    printf("\n----  - TEST 6:Mixed Coin Count -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    copyG.handCount[player] = 5;
    expectedCoinCount = 9;



    for (i = 0; i < x; i++) {
        //fill hand with coin cards
        copyG.hand[player][0] = copper;
        copyG.hand[player][1] = copper;
        copyG.hand[player][2] = silver;
        copyG.hand[player][3] = silver;
        copyG.hand[player][4] = gold;

        updateCoins(player, &copyG, bonus);
        if (copyG.coins != expectedCoinCount) {
            printf("test 6 coin count fail, Got: %d, Expected: %d\n", copyG.coins, expectedCoinCount);
            pass = 0;
        }
    }
    printf("Coins: %d, Expected: %d \n\n", copyG.coins, expectedCoinCount);

    //test addition of bonus
    printf("\n----  - TEST 7: Bonus -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    copyG.handCount[player] = 0;
    bonus = 1;
    expectedCoinCount = 1;


    for (i = 0; i < x; i++) {
        //fill hand with coins

        updateCoins(player, &copyG, bonus);
        if (copyG.coins != expectedCoinCount) {
            printf("test 7 coin count fail, Got: %d, Expected: %d\n", copyG.coins, expectedCoinCount);
            pass = 0;
        }
    }
    printf("Coins: %d, Expected: %d \n\n", copyG.coins, expectedCoinCount);

    //Final bool check to see if testing passed or failed,  prints result to standard out
    if (pass) {
        printf("->->  - TEST SUCCESSFULLY COMPLETED -  <-<-\n");
    } else{
        printf("->->  - TEST FAILED -  <-<-\n");
    }
    return 0;
};