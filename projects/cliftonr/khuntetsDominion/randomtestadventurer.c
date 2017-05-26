//
// Created by Robert Clifton on 4/18/17.
//cardtest2  unit test for the adventurer card function.
//
//to make and test: make randomtestadventurer.out
//
//gcc dominion.c rngs.c randomtestadventurer.c -o randomtestadventurer

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

    int pass = 1;
    char testCard[] = "adventurer";
    struct gameState G, copyG;
    //int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    int x = 1000;
    int i, n, r, retVal;
    int handPos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int bonus = 0;
    int currentPlayer;
    int addedCards = 2;
    int money, copyMoney;
    int totalCards, copytotalCards;

    //initialize game state
    //initializeGame(numbPlayers, k, randSeed, &G);


    //initialize random
    srand(time(NULL));


    printf("\n->->->    - TESTING CARD: %s -    <-<-<-\n", testCard);

    printf ("----  -RANDOM TESTS- ----\n");
    for (i = 0; i < x; i++){
        for (n = 0; n < sizeof(struct gameState)/ sizeof(int); n++) {
            ((int*)&G)[n] = rand() % 128;
        }

        G.numPlayers = (rand() % 3)+2;
        G.whoseTurn = rand() % G.numPlayers;
        currentPlayer = whoseTurn(&G);
        G.handCount[currentPlayer] = (rand() % (MAX_HAND/2))+1;
        G.deckCount[currentPlayer] = (rand() % (MAX_DECK/2))+1;
        G.discardCount[currentPlayer] = (rand() % (MAX_DECK/2))+1;
        handPos = (rand() % G.handCount[currentPlayer]);
        for (n = 0; n < G.handCount[currentPlayer]; n++) {
            r = (rand() % 2);
            if (r == 0) {
                G.hand[currentPlayer][n] = copper;
            } else {
                G.hand[currentPlayer][n] = estate;
            }
        }
        for (n = 0; n < G.deckCount[currentPlayer]; n++) {
            r = (rand() % 2);
            if (r == 0) {
                G.deck[currentPlayer][n] = copper;
            } else {
                G.deck[currentPlayer][n] = estate;
            }
        }


        memcpy(&copyG, &G, sizeof(struct gameState));

        retVal = cardEffect(adventurer, choice1, choice2, choice3, &copyG, handPos, &bonus);
        if (retVal != 0) {
            printf("Return Fail");
            pass = 0;
        };


        if (copyG.handCount[currentPlayer] != G.handCount[currentPlayer]+addedCards){
            pass = 0;
			//printf("NP:%d, WT:%d, HC:%d, DC:%d, %d, HP:%d\n", G.numPlayers, G.whoseTurn, G.handCount[currentPlayer], G.deckCount[currentPlayer], G.discardCount[currentPlayer], handPos);
			//printf("NP:%d, WT:%d, HC:%d, DC:%d, %d, HP:%d\n", copyG.numPlayers, copyG.whoseTurn, copyG.handCount[currentPlayer], copyG.deckCount[currentPlayer], copyG.discardCount[currentPlayer], handPos);
            printf("Hand Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer], G.handCount[currentPlayer]+addedCards);
        }

        totalCards = G.deckCount[currentPlayer] + G.discardCount[currentPlayer];
        copytotalCards = copyG.deckCount[currentPlayer] + copyG.discardCount[currentPlayer];
        if (copytotalCards != totalCards - addedCards) {
            pass = 0;
            printf("Total Cards: %d, Expected: %d \n\n", copytotalCards, totalCards-addedCards);
        };

        money = 0;
        n = 0;
        while (n < numHandCards(&G)) {
            if (handCard(n, &G) == copper) {
                money++;
            } else if (handCard(n, &G) == silver) {
                money += 2;
            } else if (handCard(n, &G) == gold) {
                money += 3;
            }
            n++;
        }

        copyMoney = 0;
        n = 0;
        while (n < numHandCards(&copyG)) {
            if (handCard(n, &copyG) == copper) {
                copyMoney++;
            } else if (handCard(n, &copyG) == silver) {
                copyMoney += 2;
            } else if (handCard(n, &copyG) == gold) {
                copyMoney += 3;
            }
            n++;
        };
        if (copyMoney < money+2) {
            pass = 0;
            printf("Money Count: %d, Expected Money Count: >= %d \n\n", copyMoney, money+2);
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