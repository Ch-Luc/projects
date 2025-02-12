#ifndef DEF_HANDS
#define DEF_HANDS

#include "Card.hpp"
#include "Joker.hpp"
#include <vector>
#include <array>

void displayHand(const std::vector<Card*>& hand);

bool isFace(const Card*, const std::vector<Joker*>& jokerHand);

bool isFlush(const std::vector<Card*>& hand);

bool isStraight(const std::vector<Card*>& hand);

Card* maxOfHand(const std::vector<Card*>& hand);

std::pair<std::string, std::vector<Card*>> handPlayed(const std::vector<Card*>& playHand);

std::vector<double> scoreHand(const std::string& nameHand, const double& nbUp);

int retriggerCard(const bool& play, Card* card, const std::vector<Card*>& playHand, const std::vector<Card*> hand, const std::vector<Joker*>& jokerHand, const int& nbHand);

void addPlayedCards(std::vector<double>& score, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand);

void addHeld(std::vector<double>& score, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand);

void addHand(std::vector<double>& score, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand);

#endif