//
// Created by Robert Clifton on 4/18/17.
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

    char testCard[] = "adventurer";
    struct gameState G, copyG;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    int i;
    int numbPlayers = 2;
    int randSeed = 1000000;
    int handPos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int bonus = 0;


    //initialize game state
    initializeGame(numbPlayers, k, randSeed, &G);


    printf("\n->->->    - TESTING CARD: %s -    <-<-<-\n\n", testCard);
    printf("\n----  - TEST 1: Function Return  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));
    int retVal = cardEffect(adventurer, choice1, choice2, choice3, &copyG, handPos, &bonus);

    printf("Return Value: %d, Expected: %d \n\n", retVal, 0);
    assert(retVal == 0);

    printf("\n----  - TEST 2: Hand Count  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    int addedCards = 2;
    int currentPlayer = whoseTurn(&G);
    cardEffect(adventurer, choice1, choice2, choice3, &copyG, handPos, &bonus);

    printf("Hand Count: %d, Expected: %d \n\n", copyG.handCount[currentPlayer], G.handCount[currentPlayer]+addedCards);
    assert(copyG.handCount[currentPlayer] == G.handCount[currentPlayer]+addedCards);

    printf("\n----  - TEST 3: Money Count  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    cardEffect(adventurer, choice1, choice2, choice3, &copyG, handPos, &bonus);

    int money, copyMoney;
    money = 0;
    i=0;
    while(i<numHandCards(&G)){
        if (handCard(i, &G) == copper){
            money++;
        }
        else if (handCard(i, &G) == silver){
            money += 2;
        }
        else if (handCard(i, &G) == gold){
            money += 3;
        }
        i++;
    }

    copyMoney = 0;
    i=0;
    while(i<numHandCards(&copyG)){
        if (handCard(i, &copyG) == copper){
            copyMoney++;
        }
        else if (handCard(i, &copyG) == silver){
            copyMoney += 2;
        }
        else if (handCard(i, &copyG) == gold){
            copyMoney += 3;
        }
        i++;
    }

    printf("Money Count: %d, Expected Money Count: >= %d \n\n", copyMoney, money+2);
    assert(copyMoney >= money+2);

    printf("\n----  - TEST 4: Deck/Discard Count  -  ----\n\n");
    memcpy(&copyG, &G, sizeof(struct gameState));

    int cardsMovedtoHand = 2;
    int totalCards, copytotalCards;
    currentPlayer = whoseTurn(&G);
    cardEffect(adventurer, choice1, choice2, choice3, &copyG, handPos, &bonus);

    totalCards = G.deckCount[currentPlayer] + G.discardCount[currentPlayer];
    copytotalCards = copyG.deckCount[currentPlayer] + copyG.discardCount[currentPlayer];

    printf("Total Cards: %d, Expected: %d \n\n", copytotalCards, totalCards-cardsMovedtoHand);
    assert(copytotalCards == totalCards-cardsMovedtoHand);

    printf("->->  - TEST SUCCESSFULLY COMPLETED -  <-<-\n");

    return 0;
};