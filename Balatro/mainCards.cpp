#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>                                                   
#include <ctime>   

#include "Card.hpp"
#include "Hands.hpp"
#include "Joker.hpp"
#include "Deck.hpp"
#include "UserChat.hpp"
#include "CardUtilities.hpp"

using namespace std;

int main() {
    // vector<Card> deck = standardDeck();
    // vector<Card*> stack;
    // for (Card& card : deck){
    //     stack.push_back(&card);
    // }
    // vector<Card*> hand;
    // vector<Card*> discard;
    
    // srand(time(0));
    // int handSize(8);
    // fillHand(handSize, stack, hand);

    // cout << "Hand contains : " << hand.size() << " cards." << endl;
    // cout << "Theses cards are: " << endl;
    // displayHand(hand);

    // cout << "Do you want to discard cards ? (Up to 5 at a time)." << endl;
    // bool assertDiscard = getYesOrNo();
    // int nbDiscard(4);

    // while(nbDiscard!=0 && assertDiscard){
    //     vector<int> toDiscard = getCards(hand);
    //     if (toDiscard.empty()){
    //         break;
    //     }
    //     else{
    //         moveToDiscard(toDiscard, hand, discard);
    //         nbDiscard--;
    //         fillHand(handSize, stack, hand);
    //         cout << "New hand contains: " << endl;
    //         displayHand(hand);
    //         if (nbDiscard==0){
    //             break;
    //         }
    //         else{
    //             cout << "Do you want to discard cards ? You have: " << nbDiscard << " discards left." << endl;
    //             assertDiscard = getYesOrNo();
    //         }
    //     }    
    // }

    // vector<int> indexCards = playedCards(hand);
    // vector<Card*> userHand;
    // for (int i=0; i<indexCards.size(); i++){
    //     userHand.push_back(hand[i]);
    // }

    Card card1={"1", "Spades"};
    Card card2={"1", "Spades"};
    Card card3={"4", "Spades"};
    Card card4={"10", "Spades"};
    Card card5={"Q", "Spades", "None", "None", "Red"};
    Card card6={"Q", "Diamonds"};
    Card card7={"K", "Clubs"};
    Card card8={"7", "Clubs"};
    vector<Card*> hand = {&card6, &card7, &card8};
    vector<Card*> playHand = {&card1, &card2, &card3, &card4, &card5};

    Mime J1("None");
    DeviousJoker J2("Foil");
    WrathfulJoker J3("None");
    Blueprint J4("None");
    SockAndBuskin J5("None");
    Hangingchad J6("None");
    Baron J7("None");
    DrollJoker J8("Foil");
    Brainstorm J9("Holographic");
    Blueprint J10("None");
    BaseballCard J11("None");
    vector<Joker*> jokerHand = {&J1, &J2, &J3, &J4, &J5, &J6, &J7, &J8, &J9, &J10, &J11};
    
    int nbHand(3);
    
    pair<string, vector<Card*>> resultHand = handPlayed(playHand);
    cout << "Played hand is: " << resultHand.first << endl;
    cout << "With: " << endl;
    displayHand(resultHand.second);

    vector<double> score = scoreHand(resultHand.first, 0);
    cout << "Base score: " << score[0] << " x " << score[1] << endl;
    addPlayedCards(score, playHand, hand, jokerHand, nbHand);
    cout << "Score with OnScore Jokers: " << score[0] << " x " << score[1] << endl;
    addHeld(score, playHand, hand, jokerHand, nbHand);
    cout << "Score with OnHeld Jokers: " << score[0] << " x " << score[1] << endl;
    addHand(score, playHand, hand, jokerHand, nbHand);
    cout << "Score with OnHand Jokers: " << score[0] << " x " << score[1] << endl;
    
    return 0;
}