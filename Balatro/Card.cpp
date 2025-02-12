#include "Card.hpp"
#include <random>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;


// Constructor
Card::Card(const std::string& name, const std::string& suit, const std::string& appearance, 
           const std::string& edition, const std::string& seal, int chip, int mult)
    : m_name(name), m_suit(suit), m_appearance(appearance), m_edition(edition), m_seal(seal), 
      m_chip(chip), m_mult(mult) {
    validateName(name);
    validateSuit(suit);
    validateAppearence(appearance);
    validateEdition(edition);
    validateSeal(seal);
    }

int luckyShot() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 5);
    return dist(gen);
}

int Card::chipBase() const{
    if(m_name == "1"){
        return 11;
    }
    else if(m_name == "2"){
        return 2;
    }
    else if(m_name == "3"){
        return 3;
    }
    else if(m_name == "4"){
        return 4;
    }
    else if(m_name == "5"){
        return 5;
    }
    else if(m_name == "6"){
        return 7;
    }
    else if(m_name == "8"){
        return 8;
    }
    else if(m_name == "9"){
        return 9;
    }
    else if(m_name == "10"){
        return 10;
    }
    else if(m_name == "J"){
        return 10;
    }
    else if(m_name == "Q"){
        return 10;
    }
    else if(m_name == "K"){
        return 10;
    }
    // If no name
    return -1;
}

void Card::addChip(const int& chip){
    m_chip+=chip;
}

void Card::addMult(const int& mult){
    m_mult+=mult;
}

void Card::addScore(vector<double>& score) const{
    // Specific case of Stone cards
    if (m_appearance=="Stone"){
        score[0]+=50;
        if (m_edition=="Foil"){
            score[0]+=50;
        }
        else if (m_edition=="Holographic"){
            score[1]+=10;
        }
        else if (m_edition=="Polychrome"){
            score[1]*=1.5;
        }
    }
    else{
        // Compute the modification of the chips
        score[0]+=m_chip + chipBase();
        if (m_appearance=="Bonus"){
            score[0]+=30;
        }
        else if (m_edition=="Foil"){
            score[0]+=50;
        }
        // Compute the modification of the mult
        score[1]+=m_mult;
        if (m_appearance=="Mult"){
            score[1]+=+4;
        }
        else if (m_appearance=="Glass"){
            score[1]*=2;
        }
        else if (m_appearance=="Lucky"){
            if (luckyShot()==1){
                score[1]+=20;
            }
        }
        else if (m_edition=="Holographic"){
            score[1]+=10;
        }
        else if (m_edition=="Polychrome"){
            score[1]*=1.5;
        }
    } 
}

string Card::suitCard() const{
    return m_suit;
}

string Card::nameCard() const{
    return m_name;
}

string Card::appearenceCard() const{
    return m_appearance;
}

string Card::sealCard() const{
    return m_seal;
}

void Card::displayCard() const{
    cout << "< " << m_name << " | ";
    cout << m_suit << " | ";
    cout << m_appearance << " | ";
    cout << m_edition << " | ";
    cout << m_seal << " >" << endl;
}

// Validation functions for constructor
bool isInVector(const std::string& test, const std::vector<std::string>& list){
    for(int i=0; i<list.size(); i++){
        if(test==list[i]){
            return true;
        }
    }
    return false;
}

void Card::validateName(const std::string& name){
    const std::vector<std::string> validName = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    if(!isInVector(name, validName)) {
        throw std::invalid_argument("Invalid name!");
    }
}

void Card::validateSuit(const std::string& suit){
    const std::vector<std::string> validSuit = {"Spades", "Clubs", "Hearts", "Diamonds"};
    if(!isInVector(suit, validSuit)) {
        throw std::invalid_argument("Invalid suit!");
    }
}

void Card::validateAppearence(const std::string& appearence){
    const std::vector<std::string> validAppearence = {"None", "Bonus", "Mult", "Wild", "Glass", "Steel", "Stone", "Gold", "Lucky"};
    if(!isInVector(appearence, validAppearence)) {
        throw std::invalid_argument("Invalid appearence!");
    }
}

void Card::validateEdition(const std::string& edition){
    const std::vector<std::string> validEdition = {"None", "Foil", "Holographic", "Poychrome", "Negative"};
    if(!isInVector(edition, validEdition)) {
        throw std::invalid_argument("Invalid edition!");
    }
}

void Card::validateSeal(const std::string& seal){
    const std::vector<std::string> validSeal = {"None", "Gold", "Red", "Blue", "Purple"};
    if(!isInVector(seal, validSeal)) {
        throw std::invalid_argument("Invalid seal!");
    }
}