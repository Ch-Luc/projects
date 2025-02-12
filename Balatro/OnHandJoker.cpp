#include "Joker.hpp"
#include "Card.hpp"
#include "Hands.hpp"
#include <vector>
#include <stdexcept>

using namespace std;

// Joker defintion that depends on the hand played

// Droll Joker
void DrollJoker::operator()(std::vector<double>& score, const Card* ref, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (ref == nullptr && isFlush(playHand)){
        score[1]+=10;
    }
}
int DrollJoker::retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    return 0;
}
std::string DrollJoker::nameJoker() const {return "Droll";}    
std::string DrollJoker::jokerFunction(vector<Joker*> jokerHand) const {return "OnHand";}
std::string DrollJoker::rarityJoker() const {return "Common";}

// Devious Joker
void DeviousJoker::operator()(std::vector<double>& score, const Card* ref, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (ref == nullptr && isStraight(playHand)){
        score[0]+=100;
    }
}
int DeviousJoker::retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    return 0;
}
std::string DeviousJoker::nameJoker() const {return "Devious";}    
std::string DeviousJoker::jokerFunction(vector<Joker*> jokerHand) const {return "OnHand";}
std::string DeviousJoker::rarityJoker() const {return "Common";}
