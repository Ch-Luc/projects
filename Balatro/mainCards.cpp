#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>                                                   
#include <ctime>   

#include "Card.hpp"
#include "Hands.hpp"
#include "Deck.hpp"
#include "UserChat.hpp"
#include "CardUtilities.hpp"

using namespace std;

int main() {
    vector<Card> deck = standardDeck();
    vector<Card*> stack;
    for (Card& card : deck){
        stack.push_back(&card);
    }
    vector<Card*> hand;
    vector<Card*> discard;
    
    srand(time(0));
    int handSize(8);
    fillHand(handSize, stack, hand);

    cout << "Hand contains : " << hand.size() << " cards." << endl;
    cout << "Theses cards are: " << endl;
    displayHand(hand);

    cout << "Do you want to discard cards ? (Up to 5 at a time)." << endl;
    bool assertDiscard = getYesOrNo();
    int nbDiscard(4);

    while(nbDiscard!=0 && assertDiscard){
        vector<int> toDiscard = getCards(hand);
        if (toDiscard.empty()){
            break;
        }
        else{
            moveToDiscard(toDiscard, hand, discard);
            nbDiscard--;
            fillHand(handSize, stack, hand);
            cout << "New hand contains: " << endl;
            displayHand(hand);
            if (nbDiscard==0){
                break;
            }
            else{
                cout << "Do you want to discard cards ? You have: " << nbDiscard << " discards left." << endl;
                assertDiscard = getYesOrNo();
            }
        }    
    }
    vector<int> indexCards = playedCards(hand);
    vector<Card*> userHand;
    for (int i=0; i<indexCards.size(); i++){
        userHand.push_back(hand[i]);
    }
    pair<string, vector<Card*>> resultHand = handPlayed(userHand);
    cout << "Played hand is: " << resultHand.first << endl;
    cout << "With: " << endl;
    displayHand(resultHand.second);

    // vector<Card> countingCards = handPlayed(hand).second;
    // cout << "Counting cards of the played hand: " << endl;
    // displayHand(countingCards);
    // cout << pokerHand << endl;
    // cout << "BaseChip : " << scoreHand(pokerHand, 0)[0] << endl;
    // cout << "BaseMult : " << scoreHand(pokerHand, 0)[1] << endl;

    return 0;
}