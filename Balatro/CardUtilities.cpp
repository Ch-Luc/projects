#include "Card.hpp"
#include <vector>
#include <algorithm>

using namespace std;

void moveToHand(const int& indexCard, vector<Card*>& stack, vector<Card*>& hand){
    hand.push_back(stack[indexCard]);
    stack.erase(stack.begin()+indexCard);
}

void fillHand(const int& handSize, vector<Card*>& stack, vector<Card*>& hand){
    while(!stack.empty() && hand.size()<handSize){
        int rndIndex = rand() % stack.size();
        moveToHand(rndIndex, stack, hand);
    }
}

void moveToDiscard(vector<int>& selection, vector<Card*>& hand, vector<Card*>& discard){
    sort(selection.rbegin(), selection.rend());
    for (int index : selection) {
        discard.push_back(hand[index]); 
        hand.erase(hand.begin() + index);
    }
}