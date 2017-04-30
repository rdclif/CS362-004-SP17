//
// Created by Robert Clifton on 4/18/17.
//cardtest2  unit test for the adventurer card function.
//
//to make and test: make unittestresults.out
//
//gcc dominion.c rngs.c cardtest2.c -o cardtest2

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

    int pass = 1;
    char testCard[] = "adventurer";
    struct gameState G, copyG;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    int x = 1000;
    int i, retVal, j;
    int numbPlayers = 2;
    int randSeed = 1000000;
    int handPos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int bonus = 0;


    //initialize game state
    initializeGame(numbPlayers, k, randSeed, &G);


    printf("\n->->->    - TESTING CARD: %s -    <-<-<-\n\n", testCard);

    //basic test of return value
    printf("\n----  - TEST 1: Function Return  -  ----\n\n");
    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        retVal = cardEffect(adventurer, choice1, choice2, choice3, &copyG, handPos, &bonus);
        if (retVal != 0) {
            pass = 0;
            break;
        };
    };
    printf("Return Value: %d, Expected: %d \n\n", retVal, 0);

    //test and compare hand count in copied struct
    printf("\n----  - TEST 2: Hand Count  -  ----\n\n");

    int addedCards = 2;
    int currentPlayer = whoseTurn(&G);
    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        cardEffect(adventurer, choice1, choice2, choice3, &copyG, handPos, &bonus);
        if (copyG.handCount[currentPlayer] != G.handCount[currentPlayer] + addedCards) {
            pass = 0;
            break;
        };
    }
    printf("Hand Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer], G.handCount[currentPlayer] + addedCards);

    //test and compare the coin count
    printf("\n----  - TEST 3: Money Count  -  ----\n\n");

    int money, copyMoney;
    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        cardEffect(adventurer, choice1, choice2, choice3, &copyG, handPos, &bonus);

        money = 0;
        j = 0;
        while (j < numHandCards(&G)) {
            if (handCard(j, &G) == copper) {
                money++;
            } else if (handCard(j, &G) == silver) {
                money += 2;
            } else if (handCard(j, &G) == gold) {
                money += 3;
            }
            j++;
        }

        copyMoney = 0;
        j = 0;
        while (j < numHandCards(&copyG)) {
            if (handCard(j, &copyG) == copper) {
                copyMoney++;
            } else if (handCard(j, &copyG) == silver) {
                copyMoney += 2;
            } else if (handCard(j, &copyG) == gold) {
                copyMoney += 3;
            }
            j++;
        };
        if (copyMoney < money+2) {
            pass = 0;
            break;
        }
    };

    printf("Money Count: %d, Expected Money Count: >= %d \n\n", copyMoney, money+2);

    //test and compare Deck and discard count on copied struct
    printf("\n----  - TEST 4: Deck/Discard Count  -  ----\n\n");

    int cardsMovedtoHand = 2;
    int totalCards, copytotalCards;
    currentPlayer = whoseTurn(&G);

    for (i = 0; i < x; i++) {
        memcpy(&copyG, &G, sizeof(struct gameState));
        cardEffect(adventurer, choice1, choice2, choice3, &copyG, handPos, &bonus);

        totalCards = G.deckCount[currentPlayer] + G.discardCount[currentPlayer];
        copytotalCards = copyG.deckCount[currentPlayer] + copyG.discardCount[currentPlayer];
        if (copytotalCards != totalCards - cardsMovedtoHand) {
            pass = 0;
            break;
        };
    };

    printf("Total Cards: %d, Expected: %d \n\n", copytotalCards, totalCards-cardsMovedtoHand);

    //Final bool check to see if testing passed or failed,  prints result to standard out
    if (pass) {
        printf("->->  - TEST SUCCESSFULLY COMPLETED -  <-<-\n");
    } else{
        printf("->->  - TEST FAILED -  <-<-\n");
    }

    return 0;
};