#include "Joker.hpp"
#include "Card.hpp"
#include "Hands.hpp"
#include <vector>
#include <stdexcept>

using namespace std;

// Joker defintion that impacts the retrigger count of card

// Hanging Chad
void Hangingchad::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    throw runtime_error("Hangingchad does not support this operation!");
}
int Hangingchad::retriggerCount(const Card* card, const std::vector<Card*>& playHand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (card == *playHand.begin()){
        return 2;
    }
    else {
        return 0;
    }
}
std::string Hangingchad::nameJoker() const {return "Hangingchad";}
std::string Hangingchad::jokerFunction(vector<Joker*> jokerHand) const {return "RetriggerPlayed";}
std::string Hangingchad::rarityJoker() const {return "Common";}

// Hack
void Hack::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    throw runtime_error("Hack does not support this operation!");
}
int Hack::retriggerCount(const Card* card, const std::vector<Card*>& playHand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (card->nameCard()=="2" || card->nameCard()=="3" ||card->nameCard()=="4" || card->nameCard()=="5"){
        return 1;
    }
    else {
        return 0;
    }
}
std::string Hack::nameJoker() const {return "Hack";}
std::string Hack::jokerFunction(vector<Joker*> jokerHand) const {return "RetriggerPlayed";}
std::string Hack::rarityJoker() const {return "Uncommon";}

// Seltzer
void Seltzer::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    throw runtime_error("Seltzer does not support this operation!");
}
int Seltzer::retriggerCount(const Card* card, const std::vector<Card*>& playHand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    return 1;
}
std::string Seltzer::nameJoker() const {return "Seltzer";}
std::string Seltzer::jokerFunction(vector<Joker*> jokerHand) const {return "RetriggerPlayed";}
std::string Seltzer::rarityJoker() const {return "Uncommon";}

// SockAndBuskin
void SockAndBuskin::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    throw runtime_error("SockAndBuskin does not support this operation!");
}
int SockAndBuskin::retriggerCount(const Card* card, const std::vector<Card*>& playHand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (isFace(card, jokerHand)) {
        return 1;
    }
    else{
        return 0;
    }
}
std::string SockAndBuskin::nameJoker() const {return "SockAndBuskin";}
std::string SockAndBuskin::jokerFunction(vector<Joker*> jokerHand) const {return "RetriggerPlayed";}
std::string SockAndBuskin::rarityJoker() const {return "Uncommon";}

// Dusk
void Dusk::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    throw runtime_error("Dusk does not support this operation!");
}
int Dusk::retriggerCount(const Card* card, const std::vector<Card*>& playHand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    if (nbHand==1) {
        return 1;
    }
    else {
        return 0;
    }
}
std::string Dusk::nameJoker() const {return "Dusk";}
std::string Dusk::jokerFunction(vector<Joker*> jokerHand) const {return "RetriggerPlayed";}
std::string Dusk::rarityJoker() const {return "Uncommon";}

// Mime
void Mime::operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
    const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
}
int Mime::retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const {
    return 1;
}
std::string Mime::nameJoker() const {return "Mime";}
std::string Mime::jokerFunction(vector<Joker*> jokerHand) const {return "RetriggerHeld";}
std::string Mime::rarityJoker() const {return "Uncommon";}