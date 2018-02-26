#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int DECKSIZE = 52;

class Card
{
public:
	Card() : myRank(0), mySuit(0) { /* Do nothing */ };
	  // Construct a card initialized to the ace of clubs.

	void ChangeCard(int n);
      // Change the card to the nth card in the sequence ace of clubs, 2 of
      // diamonds, 3 of hearts, 4 of spades, 5 of clubs, ..., queen of spades,
      // king of clubs, ace of diamonds, 2 of hearts, 3 of spades, 4 of clubs,
      // ..., jack of spades, queen of clubs, king of diamonds, ace of hearts,
      // 2 of spades, etc.

	int Value() const;
      // Return the card's value in blackjack: 11 if it's an ace, 10 if it's a
      // face card (king, queen, or jack), and the card's face value (2, 3,
      // ..., or 10) otherwise.

	string Name() const;
	  // Return the name of the card.

	bool IsAce() const { return myRank == 0; }
      // Return true if the card is an ace, and return false otherwise.

	bool IsFaceCard() const { return myRank >= 10; }
      // Return true if the card is a face card (king, queen, or jack), and
      // return false otherwise.

	bool Outranks(Card other) const { return myRank > other.myRank; }
      // Return true if the card outranks the argument card. One card outranks
      // another if it has a higher value. Any face card outranks a 10; a king
      // outranks a queen or jack; and a queen outranks a jack.

	bool EqualsInRank(Card other) const { return myRank == other.myRank; }
      // Return true if the card and the argument card are equal in value.

	bool IsSameSuit(Card other) const { return mySuit == other.mySuit; }
      // Return true if the card and the argument card are the same suit.

private:
	int myRank;

	int mySuit;
};

class Deck
{
public:
	Deck(bool debug=false);
      // Construct a deck of 52 cards. If a true argument is given, it causes
      // debugging output to be printed to cerr every time a card is dealt or
      // the deck shuffled.

	void Shuffle();
	  // Shuffle the deck, i.e. randomly permute its cards.
 
	void Print(ostream& output) const;
	  // Print the contents of the deck.

	Card Deal();
      // Return the top card of the deck, and remove that card from the deck.
      // If the deck is empty, first shuffle the already-dealt cards and deal
      // from them.

	bool IsEmpty() const { return myTop == DECKSIZE; }
	  // Return true if the deck is empty and false otherwise.

private:
	vector<Card> myCards;

	int myTop;

	bool debugging;
};

#endif