#ifndef DEF_UC
#define DEF_UC

#include <vector>
#include <iostream>
#include <algorithm>

#include "Card.hpp"
#include "UserChat.hpp"
#include "Hands.hpp"

bool getYesOrNo();

std::vector<int> getCards(const std::vector<Card*>& hand);

std::vector<int> playedCards(const std::vector<Card*>& hand);

#endif