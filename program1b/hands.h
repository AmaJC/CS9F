#ifndef _HANDS
#define _HANDS
#include "cards.h"

class DealerHand
{
public:
	DealerHand();
	  // Construct an empty hand for the dealer.

	void Reset();
	  // Reinitialize the hand to contain no cards.

	void AddCard(Card c);
	  // Add the given card to the hand.

	bool CanDraw() const;
      // Return true if, according to the dealer's strategy, another card
      // should be drawn.  (The dealer's strategy is to draw a card when
      // his/her total is less than or equal to 16.)

	Card UpCard();
      // Return the dealer's "up card" (the first card dealt to the dealer at
      // the start of each game).

	int Total() const;
	  // Return the dealer's total hand value.

	void Print() const;
	  // Print available information about the hand.

private:
	Card myUpCard;

	int myCardCount;

	int myAceAs11Count;

	int myTotal;
};

class CustomerHand
{
public:
	CustomerHand();
	  // Construct an empty hand for the customer.

	void Reset();
	  // Reinitialize the hand to contain no cards.

	void AddCard(Card c);
	  // Add the given card to the hand.

	bool CanDraw(Card dealerUpCard) const;
      // Return true if, according to the player's strategy, another card
      // should be drawn.

	int Total() const;
	  // Return the total hand value.

	void Print() const;
	  // Print available information about the hand.

private:
	int myCardCount;

	int myAceAs11Count;

	int myTotal;
};

#endif