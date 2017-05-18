/* -----------------------------------------------------------------------
 * Assignment 4
 * randomtest1.c
 * Shreyans Khunteta
 
We are testing the Smithy card here. Let's hope it works!
 
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

   struct gameState g;

   int seed = 1000;
   int numTestsPassed = 0;
	int passedAllTestsFlag = 0;
   int numPlayers = 2; 
   int currentPlayer = 0;
   int deckSize;
   int handSize;
   int startDeck;
   int currentDeck;
   int startHand;
   int currentHand;
   int startDiscard;
   int currentDiscard;
   int failedDeckCount = 0;
   int failedHandCount = 0;
   int failedDiscardCount = 0;
   int i = 0;
   int choice1 = 0; 
   int choice2 = 0;
   int choice3 = 0;
   int handPos = 0;
   int bonus = 0;

   int allowedCards[10] = {adventurer, embargo, village, minion, mine, 
   cutpurse, sea_hag, tribute, smithy, council_room};

   srand(time(NULL));


   for (i = 0; i < 123456; i++) {

      //Randomly intialize the game state. Then make sure the needed variables are sane.
      initializeGame(numPlayers, allowedCards, seed, &g);

      deckSize = rand() % (MAX_DECK + 1);
      handSize = rand() % (deckSize + 1);

      g.deckCount[0] = deckSize - handSize;
      g.handCount[0] = handSize;
      handPos = g.hand[currentPlayer][g.handCount[currentPlayer]-1];


      //Note the currentent state before playing the card
      startDeck = g.deckCount[0];
      startHand = g.handCount[0];
      startDiscard = g.playedCardCount;


      //Play the card
      cardEffect(smithy, choice1, choice2, choice3, &g, handPos, &bonus);


      //Note the state after playing the card
      currentDeck = g.deckCount[0];
      currentHand = g.handCount[0];
      currentDiscard = g.playedCardCount;


      //NOW... the moment of reckoning... the tests
      passedAllTestsFlag = 1;

      //printf("Testing Smithy card...\n");

      if (currentDeck != (startDeck - 3)) {
	 failedDeckCount++;
	 passedAllTestsFlag = 0;
      }

      if (currentHand != (startHand + 2)) {
	 failedHandCount++;
	 passedAllTestsFlag = 0;
      }

      if (currentDiscard != (startDiscard + 1)) {
	 failedDiscardCount++;
	 passedAllTestsFlag = 0;
      }

      if (passedAllTestsFlag == 1) {
	 numTestsPassed++;
      }

   }

      
   printf("Smithy tests summary:\n");
   printf("\tPASSED: %d\n", numTestsPassed);
   printf("\tFAILED (deck): %d\n", failedDeckCount);
   printf("\tFAILED (hand): %d\n", failedHandCount);
   printf("\tFAILED (discard): %d\n\n", failedDiscardCount);

   

   return 0;

}
