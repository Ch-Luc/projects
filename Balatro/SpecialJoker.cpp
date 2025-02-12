#include "Joker.hpp"
#include "Card.hpp"
#include "Hands.hpp"
#include <vector>
#include <stdexcept>

#include <iostream>

using namespace std;

// Special jokers definition

// Blueprint
vector<Joker*>::const_iterator blueprintCopy(const vector<Joker*>& jokerHand, const Joker* target) {
    auto it = find(jokerHand.begin(), jokerHand.end(), target);
    if (it != jokerHand.end()) {
        auto nextIt = next(it);
        if (nextIt != jokerHand.end() && *nextIt) {
            cout << "Blueprint it existe." << endl;
            return nextIt;
        }
        else {
            return jokerHand.end();
        }
    }
    else {
        return jokerHand.end();
    }
}

void Blueprint::operator()(vector<double>& score, const Card* ref, const vector<Card*>& playHand,
    const vector<Card*>& hand, const vector<Joker*>& jokerHand, const int& nbHand) const {
    cout << "operator blueprint" << endl;
    auto it = blueprintCopy(jokerHand, this);
    if (it == jokerHand.end()) {
        cout << "end atteint" << endl;
    }
    if (it != jokerHand.end()) {
        cout << "oui" << endl;
        (*it)->operator()(score, ref, playHand, hand, jokerHand, nbHand);
    }
}

int Blueprint::retriggerCount(const Card* card, const vector<Card*>& hand, const vector<Joker*>& jokerHand, const int& nbHand) const {
    auto it = blueprintCopy(jokerHand, this);
    if (it != jokerHand.end()) {
        return (*it)->retriggerCount(card, hand, jokerHand, nbHand);
    }
    else {
        return 0;
    }
}
string Blueprint::nameJoker() const {return "Blueprint";}    
string Blueprint::jokerFunction(vector<Joker*> jokerHand) const {
    auto it = blueprintCopy(jokerHand, this);
    if (it != jokerHand.end()) { 
        return (*it)->jokerFunction(jokerHand);
    }
    else {
        return "Special";
    }
}
string Blueprint::rarityJoker() const {return "Rare";}

// Brainstorm
vector<Joker*>::const_iterator brainstormCopy(const vector<Joker*>& jokerHand, const Joker* target) {
    auto it = find(jokerHand.begin(), jokerHand.end(), target);
    if (it != jokerHand.end()) {
        if (it != jokerHand.begin()) {
            return jokerHand.begin();
        }
        else{
            return jokerHand.end();
        }
    }
    else {
        return jokerHand.end();
    }
}

void Brainstorm::operator()(vector<double>& score, const Card* ref, const vector<Card*>& playHand,
    const vector<Card*>& hand, const vector<Joker*>& jokerHand, const int& nbHand) const {
    auto it = brainstormCopy(jokerHand, this);
    if (it != jokerHand.end()) {
        (*it)->operator()(score, ref, playHand, hand, jokerHand, nbHand);
    }
}
int Brainstorm::retriggerCount(const Card* card, const vector<Card*>& hand, const vector<Joker*>& jokerHand, const int& nbHand) const {
    auto it = brainstormCopy(jokerHand, this);
    if (it != jokerHand.end()) {
        return (*it)->retriggerCount(card, hand, jokerHand, nbHand);
    }
    else {
        return 0;
    }
}
string Brainstorm::nameJoker() const {return "Brainstorm";}    
string Brainstorm::jokerFunction(vector<Joker*> jokerHand) const {
    auto it = brainstormCopy(jokerHand, this);
    if (it != jokerHand.end()) {
        return (*it)->jokerFunction(jokerHand);
    }
    else{
        return "Special";
    }
}
string Brainstorm::rarityJoker() const {return "Rare";}

// BaseballCard
void BaseballCard::operator()(vector<double>& score, const Card* ref, const vector<Card*>& playHand,
    const vector<Card*>& hand, const vector<Joker*>& jokerHand, const int& nbHand) const {
}
int BaseballCard::retriggerCount(const Card* card, const vector<Card*>& hand, const vector<Joker*>& jokerHand, const int& nbHand) const {
    return 0;
}
string BaseballCard::nameJoker() const {return "BaseballCard";}    
string BaseballCard::jokerFunction(vector<Joker*> jokerHand) const {return "Special";}
string BaseballCard::rarityJoker() const {return "Rare";}

// Pareidolia
void Pareidolia::operator()(vector<double>& score, const Card* ref, const vector<Card*>& playHand,
    const vector<Card*>& hand, const vector<Joker*>& jokerHand, const int& nbHand) const {}
int Pareidolia::retriggerCount(const Card* card, const vector<Card*>& hand, const vector<Joker*>& jokerHand, const int& nbHand) const {
    return 0;
}
string Pareidolia::nameJoker() const {return "Pareidolia";}    
string Pareidolia::jokerFunction(vector<Joker*> jokerHand) const {return "Special";}
string Pareidolia::rarityJoker() const {return "Uncommon";}