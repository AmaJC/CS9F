#include "hands.h"

// Construct an empty hand for the dealer.
DealerHand::DealerHand() 
{
	myCardCount = 0;
	myAceAs11Count = 0;
	myTotal = 0;
}

void DealerHand::Reset() 
{
	myCardCount = 0;
	myAceAs11Count = 0;
	myTotal = 0;
}

int DealerHand::Total() const 
{
	return myTotal;
}

void DealerHand::AddCard(Card c)
{
	if (myTotal == 0) {
		myUpCard = c;
		cout << "heeee";
	}
	myTotal += c.Value();
}

bool DealerHand::CanDraw() const 
{
	if (myTotal <= 16) {
		return true;
	}
	return false;
}

CustomerHand::CustomerHand()
{
	myCardCount = 0;
	myAceAs11Count = 0;
	myTotal = 0;
}

int CustomerHand::Total() const
{
	return myTotal;
}

void CustomerHand::AddCard(Card c)
{
	myTotal += c.Value();
}

bool CustomerHand::CanDraw(Card dealerUpCard) const 
{
	if (dealerUpCard.Value() >= 7 and myTotal < 17) {
		return true;
	} else if (dealerUpCard.Value() < 7 and myTotal < 12) {
		return true;
	} else {
		return false;
	}
}