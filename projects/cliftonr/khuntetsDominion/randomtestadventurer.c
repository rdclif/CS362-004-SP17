/* -----------------------------------------------------------------------
 * Assignment 4
 * randomtestadventurer.c
 * Shreyans Khunteta
 
 
 I tried testing the adventurer card here but kept running into bugs that just messed up
 what I tried to do.
 
 So I leave this here in honour of what I attempted.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


int main () {
/*
   struct gameState g;

   int seed = 1000;
   int numTestsPassed = 0, passedAllTestsFlag = 0, testDraw = 0, failedDiscard = 0;
   int numPlayers = 2, currPlayer = 0, deckSize, handSize, randCard, randAllowedCard;
   int trCopper, trSilver, trGold;
   int beforeCoins = 0, afterCoins = 0;
   int i, j, k;
   int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 0, bonus = 0;

   int allowedCards[10] = {adventurer, embargo, village, minion, mine, 
   cutpurse, sea_hag, tribute, smithy, council_room};

   srand(time(NULL));


   for (i = 0; i < 123456; i++) {

      //Randomly intialize the game state. Then make sure the needed variables are sane.
      initializeGame(numPlayers, allowedCards, seed, &g);
      beforeCoins = 0;
      afterCoins = 0;

      deckSize = rand() % (MAX_DECK + 1);
      handSize = rand() % (deckSize + 1);

      g.deckCount[0] = deckSize - handSize;
      g.handCount[0] = handSize;



      //Fill up each player's deck with random cards
      for (j = 0; j < numPlayers; j++) {

	 for (k = 0; k < g.deckCount[j]; k++) {

	    randCard = rand() % 51;	//# of diff cards possible + 1

	    if (randCard == 1) {
	       g.deck[j][k] = copper;
	    }
	    else if (randCard == 2) {
	       g.deck[j][k] = silver;
	    }
	    else if (randCard == 3) {
	       g.deck[j][k] = gold;
	    }
	    else {
	       randAllowedCard = rand() % 10;
	       g.deck[j][k] = allowedCards[randAllowedCard];
	    }

	 }

      }


      //Note the current state of the player's treasure
      for (j = 0; j < g.handCount[currPlayer]; j++) {
	 if (g.hand[currPlayer][j] == copper || g.hand[currPlayer][j] == silver || g.hand[currPlayer][j] == gold) {
	    beforeCoins += 1;
	 }
      }


      //Play the card
      cardEffect(adventurer, choice1, choice2, choice3, &g, handPos, &bonus);


      //Note the state of the player's treasure now
      for (j = 0; j < g.handCount[currPlayer]; j++) {
	 if (g.hand[currPlayer][j] == copper || g.hand[currPlayer][j] == silver || g.hand[currPlayer][j] == gold) {
	    afterCoins += 1;
	 }
      }


      trCopper = 0;
      trSilver = 0;
      trGold = 0;


      //Note the discard pile state
      for (j = 0; j < g.discardCount[currPlayer]; j++) {

	 if (g.discard[currPlayer][j] == copper) {
	    trCopper += 1;
	 }
	 else if (g.discard[currPlayer][j] == silver) {
	    trSilver += 1;
	 }
	 else if (g.discard[currPlayer][j] == gold) {
	    trGold += 1;
	 }

      }


      //NOW... the moment of reckoning... the tests
      passedAllTestsFlag = 1;

      if (afterCoins != (beforeCoins + 2)) {
	 testDraw++;
	 passedAllTestsFlag = 0;
      }
      
      if (afterCoins < beforeCoins) {
	 testDraw++;
	 passedAllTestsFlag = 0;
      }


      if (trGold != 0) {
	 failedDiscard++;
	 passedAllTestsFlag = 0;
      }

      if (trSilver != 0) {
	 failedDiscard++;
	 passedAllTestsFlag = 0;
      }

      if (trCopper != 0) {
	 failedDiscard++;
	 passedAllTestsFlag = 0;
      }


      if (passedAllTestsFlag == 1) {
	 numTestsPassed++;
      }

   }

   printf("Adventurer tests summary:\n");
   printf("\tPASSED: %d\n", numTestsPassed);
   printf("\tFAILED (draw): %d\n", testDraw);
   printf("\tFAILED (discard): %d\n\n", failedDiscard);

   
*/
   return 0;

}