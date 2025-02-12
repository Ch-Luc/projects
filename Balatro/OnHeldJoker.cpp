#include "Joker.hpp"
#include "Card.hpp"
#include "Hands.hpp"
#include <vector>
#include <stdexcept>
#include <unordered_map>

using namespace std;

// Joker defintion that impacts cards held in hand

// Baron
void Baron::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (card->nameCard() == "K") {
        score[1]*=1.5;
    }
}
int Baron::retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    return 0;
}
std::string Baron::nameJoker() const {return "Baron";}
std::string Baron::jokerFunction(vector<Joker*> jokerHand) const {return "OnHeld";}
std::string Baron::rarityJoker() const {return "Rare";}

// ShootTheMoon
void ShootTheMoon::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (card->nameCard() == "Q") {
        score[1]+=13;
    }
}
int ShootTheMoon::retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    return 0;
}
std::string ShootTheMoon::nameJoker() const {return "ShootTheMoon";}
std::string ShootTheMoon::jokerFunction(vector<Joker*> jokerHand) const {return "OnHeld";}
std::string ShootTheMoon::rarityJoker() const {return "Common";}

// RaisedFist
int minOfHand(const std::vector<Card*>& hand){
    std::unordered_map<std::string, int> cardValues = {
        {"1", 14}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6},
        {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}
    };
    Card* minCard = hand[0];
    int temp = cardValues[minCard->nameCard()];
    for (Card* card : hand) {
        if (cardValues[card->nameCard()]<temp) {
            minCard = card;
        }
    }
    return cardValues[minCard->nameCard()];
}

void RaisedFist::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    score[1]+=minOfHand(hand);
}
int RaisedFist::retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    return 0;
}
std::string RaisedFist::nameJoker() const {return "RaisedFist";}
std::string RaisedFist::jokerFunction(vector<Joker*> jokerHand) const {return "OnHeld";}
std::string RaisedFist::rarityJoker() const {return "Common";}