#include "hands.h"
#include "cards.h"
#include "cards.cpp"
#include "hands.cpp"
#include <iostream>
using namespace std;

/**
 * You complete this function, which takes two hands and a deck as arguments. 
 * It returns the result of dealing two cards each to the dealer hand and 
 * the customer hand arguments.  The first card in the deck argument goes 
 * to the customer, the second to the dealer, the third to the customer,
 * and the fourth to the dealer. DealFirstFourCards should also print
 * appropriate debugging output.
 */
void DealFirstFourCards(DealerHand dealer, CustomerHand cust, Deck d)
{
    // TODO: You fill this in
    d.Shuffle();
    Card first = d.Deal();
    cust.AddCard(first);
    Card second = d.Deal();
    dealer.AddCard(second);
    Card third = d.Deal();
    cust.AddCard(third);
    Card fourth = d.Deal();
    dealer.AddCard(fourth);
    // cout << "After dealing, customer has " << cust.Total();
    // cout << " and dealer has " << dealer.Total() << endl;
}

/**
 * You complete this function, which takes two hands and a deck as arguments. 
 * On entry, each hand has already been dealt two cards, and neither hand has 
 * a blackjack (a total of 21). ResultOfPlay returns the result of playing
 * the hand. 
 * First, the customer draws cards until he/she either goes past 21 (a "bust") 
 * or reaches a suitable total less than or equal to 21. If the customer has 
 * not bust, then the dealer draws cards until reaching a total of 17 or more. 
 * ResultOfPlay returns 0 if the customer busts or if the customer's total is 
 * less than or equal to the dealer's and the dealer hasn't bust. 
 * ResultOfPlay returns 1 if the dealer busts or if the customer's total 
 * exceeds the dealer's and the customer has not bust.
 * ResultOfPlay should also print appropriate debugging output.
 */
int ResultOfPlay(DealerHand dealer, CustomerHand cust, Deck d)
{
    // TODO: You fill this in
    //cout << "Customer has total: " << cust.Total() << endl;
    //cout << "Dealer's up card: " << dealer.UpCard().Value() << endl;
    while (cust.CanDraw(dealer.UpCard())) {
        Card newCard = d.Deal();
        cust.AddCard(newCard);
        cout << "Customer draws a " << newCard.Value() << endl;
    } 
    while (dealer.CanDraw()) {
        Card newCard = d.Deal();
        dealer.AddCard(newCard);
        cout << "Dealer draws a " << newCard.Value() << endl;
    }
    if (dealer.Total() == 21) { //dealer blackjack or cust bust
        cout << "Dealer got a blackjack. Dealer wins. :(";
        return 0;
    } else if (cust.Total() > 21) {
        cout << "Customer bust. Dealer wins.";
        return 0;
    } else if (cust.Total() == 21) { //cust blackjack or dealer bust
        cout << "Customer got a blackjack. You win! :D";
        return 1;
    } else if (dealer.Total() > 21) {
        cout << "Dealer bust. You win!";
        return 1;
    } else if (cust.Total() > dealer.Total()) {
        cout << "Customer value is " << cust.Total() << " and Dealer value is " << dealer.Total() << endl;
        cout << "You win!" << endl;
        return 1;
    }
    cout << "Customer value is " << cust.Total() << " and Dealer value is " << dealer.Total() << endl;
    cout << "Dealer wins." << endl;
    return 0;
}

int main()
{
    Deck d(true);
    int numGames, numWins;
    DealerHand dealerHand;
    CustomerHand ourHand;
    cout << "How many games? ";
    cin >> numGames;
    numWins = 0;
    for (int k = 1; k <= numGames; k++)
    {
        DealFirstFourCards(dealerHand, ourHand, d);
        if (dealerHand.Total() == 21)
        {
            cout << "LOSS: Dealer has blackjack" << endl;
        }
        else if (ourHand.Total() == 21)
        {
            numWins += 2;
            cout << "WIN:  We have blackjack" << endl;
        }
        else
        {
            numWins += ResultOfPlay(dealerHand, ourHand, d);
        }
    }
    cout << "We won " << numWins << " out of " << numGames << endl;

    return 0;
}