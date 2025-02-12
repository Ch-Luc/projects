#include "Joker.hpp"
#include "Card.hpp"
#include "Hands.hpp"
#include <vector>
#include <stdexcept>

using namespace std;

// Joker defintion that impacts played cards

// Greedy Joker
void GreedyJoker::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (card->suitCard() == "Diamonds" || card->appearenceCard() == "Wild") {
        score[1] += 3; 
    }
}
int GreedyJoker::retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    return 0;
}
std::string GreedyJoker::nameJoker() const {return "Greedy";}
std::string GreedyJoker::jokerFunction(vector<Joker*> jokerHand) const {return "OnScored";}
std::string GreedyJoker::rarityJoker() const {return "Common";}

// Lusty Joker
void LustyJoker::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (card->suitCard() == "Hearts" || card->appearenceCard() == "Wild") {
        score[1] += 3; 
    }
}
int LustyJoker::retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    return 0;
}
std::string LustyJoker::nameJoker() const {return "Lusty";}
std::string LustyJoker::jokerFunction(vector<Joker*> jokerHand) const {return "OnScored";}
std::string LustyJoker::rarityJoker() const {return "Common";}

// Wrathful Joker
void WrathfulJoker::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (card->suitCard() == "Spades" || card->appearenceCard() == "Wild") {
        score[1] += 3; 
    }
}
int WrathfulJoker::retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    return 0;
}
std::string WrathfulJoker::nameJoker() const {return "Wrathful";}
std::string WrathfulJoker::jokerFunction(vector<Joker*> jokerHand) const {return "OnScored";}
std::string WrathfulJoker::rarityJoker() const {return "Common";}

// Gluttonous Joker
void GluttonousJoker::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (card->suitCard() == "Club" || card->appearenceCard() == "Wild") {
        score[1] += 3; 
    }
}
int GluttonousJoker::retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    return 0;
}
std::string GluttonousJoker::nameJoker() const {return "Glutonous";}
std::string GluttonousJoker::jokerFunction(vector<Joker*> jokerHand) const {return "OnScored";}
std::string GluttonousJoker::rarityJoker() const {return "Common";}