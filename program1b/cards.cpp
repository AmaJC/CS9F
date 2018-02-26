#include "cards.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void Card::ChangeCard(int n)
{
    if (n < 0 || n > DECKSIZE - 1)
    {
        cerr << "Bad card initialization: " << n << endl;
        abort();
    }
    myRank = n % 13;
    mySuit = n % 4;
}
    
int Card::Value() const
{
    if (myRank < 10 && myRank > 0)
    {
        return myRank + 1;
    }
    else if (myRank == 0)
    {
        return 11;
    }
    else
    {
        return 10;
    }
}

string Card::Name() const
{
    string s;
    switch (myRank)
    {
        case 0:        s = "ace"; break;
        case 1:        s = "2"; break;
        case 2:        s = "3"; break;
        case 3:        s = "4"; break;
        case 4:        s = "5"; break;
        case 5:        s = "6"; break;
        case 6:        s = "7"; break;
        case 7:        s = "8"; break;
        case 8:        s = "9"; break;
        case 9:        s = "10"; break;
        case 10:    s = "jack"; break;
        case 11:    s = "queen"; break;
        case 12:    s = "king"; break;
    }
    s += " of ";
    switch (mySuit)
    {
        case 0:    s += "clubs"; break;
        case 1:    s += "diamonds"; break;
        case 2:    s += "hearts"; break;
        case 3:    s += "spades"; break;
    }
    return s;
}

Deck::Deck(bool debug) : myCards(DECKSIZE), debugging(debug)
{
    for (int k = 0; k < DECKSIZE; k++)
    {
        myCards[k].ChangeCard(k);
    }
    Shuffle();
}

void Deck::Shuffle()
{
    for (int k = DECKSIZE - 1; k > 0; k--)
    {
        // find random index between 0 and k
        int j = rand(); // random integer
        if (j < 0)
        {
            j = -j;     // random nonnegative integer
        }
        j = j % k;      // random integer between 0 and k-1
        Card temp = myCards[j];
        myCards[j] = myCards[k];
        myCards[k] = temp;
    }
    myTop = 0;
    if (debugging)
    {
        Print(cerr);
    }
}

void Deck::Print(ostream& output) const
{
    for (int k = 0; k < DECKSIZE; k += 4)
    {
        output << "*** " << myCards[k].Name()     << "; "
                         << myCards[k + 1].Name() << "; "
                         << myCards[k + 2].Name() << "; "
                         << myCards[k + 3].Name() << endl;
    }
}

Card Deck::Deal()
{
    if (IsEmpty())  // deck is empty;
    {
        if (debugging)
        {
            cerr << "*** Shuffling deck." << endl;
        }
        Shuffle();
    }
    myTop++;
    if (debugging)
    {
        cerr << "*** Dealing " << myCards[myTop - 1].Name() << endl;
    }
    return myCards[myTop - 1];
}