#ifndef DEF_HANDS
#define DEF_HANDS

#include "Card.hpp"
#include <vector>
#include <array>

void displayHand(const std::vector<Card*>& hand);

bool isFlush(const std::vector<Card*>& hand);

bool isStraight(const std::vector<Card*>& hand);

Card* maxOfHand(const std::vector<Card*>& hand);

std::pair<std::string, std::vector<Card*>> handPlayed(const std::vector<Card*>& hand);

std::array<int, 2> scoreHand(const std::string& nameHand, const int& nbUp);

#endif