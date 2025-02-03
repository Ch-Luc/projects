#ifndef DEF_CU
#define DEF_CU

#include "Card.hpp"
#include <vector>

void moveToHand(const int& indexCard, std::vector<Card*>& stack, std::vector<Card*>& hand);

void fillHand(const int& handSize, std::vector<Card*>& stack, std::vector<Card*>& hand);

void moveToDiscard(std::vector<int>& selection, std::vector<Card*>& hand, std::vector<Card*>& discard);

#endif