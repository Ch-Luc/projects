#include "Hands.hpp"
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <array>
using namespace std;

void displayHand(const vector<Card*>& hand){
    for(int i=0; i<hand.size(); i++){
        cout << "#" << i << " ";
        hand[i]->displayCard();
        cout << "&" << endl;
    }
}

string classedHand(const vector<Card>& hand){
    if (hand.size()==1){
        return "HighCard";
    }
    else{
        int count = 0;
        unordered_map<string, int> countCard;  // Container to assert the number of occurence of a card value in hand 
        for (int i=0; i<hand.size(); i++){
            string target=hand[i].nameCard();
            if (countCard.find(target) == countCard.end()){     // Check if the card value is not already in the container
                count = 0;
                for (int j=0; j<hand.size(); j++){
                    if (i!=j & hand[i].nameCard()==hand[j].nameCard()){
                        count++;
                    }
                }
                countCard.insert({target, count});
            }
        }
        int sum = 0;
        for (const auto& pair : countCard){     // Check how much occurence of a card is in the container 
            sum+=pow(10, pair.second);
        }
        if (sum==5){
            return "HighCard";
        }
        else if (sum==13){
            return "Pair";
        }
        else if (sum==21){
            return "TwoPair";
        }
        else if (sum==102){
            return "ThreeOfAKind";
        }
        else if (sum==110){
            return "FullHouse";
        }
        else if (sum==1001){
            return "FourOfAKind";
        }
        else if (sum==10000){
            return "FiveOfAKind";
        }
        else{
            return "Error";
        }
    }
}

bool isFace(const Card* card, const vector<Joker*>& jokerHand){
    auto it = find_if(jokerHand.begin(), jokerHand.end(), [](const Joker* j) {return j->nameJoker() == "Pareidolia";});
    if (it != jokerHand.end()) {
        return true;
    }
    else {
        if (card->nameCard()=="J" || card->nameCard()=="Q" || card->nameCard()=="K"){
            return true;
        }
        else{
            return false;
        }
    }
}

bool isFlush(const vector<Card*>& hand){
    if (hand.size()<5){
        cout << "Hand does not contain 5 cards!" << endl;
        return false;
    }
    else{
        int i=1;
        int j=i-1;
        while(i<hand.size()){
            if (hand[i]->suitCard()==hand[j]->suitCard()){
                i++;
            }
            else if (hand[i]->appearenceCard()=="Wild"){
                i++;
            }
            else if (hand[j]->appearenceCard()=="Wild"){
                j++;
            }
            else{
                return false;
            }
        }
        return true;
    }
}

bool isStraight(const vector<Card*>& hand){
    if(hand.size()<5){
        cout << "Hand does not contain 5 cards!" << endl;
        return false;
    }
    else{
        unordered_map<string, int> cardValues = {
                {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6},
                {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}
        };

        // Get int values of cards (exception for Ace in case of royal straight or low straight)
        vector<int> values;
        bool hasAce = false;
        for(int i=0; i<hand.size(); i++){
            if(hand[i]->nameCard() == "1"){
                hasAce = true;
                values.push_back(14);
            }
            values.push_back(cardValues[hand[i]->nameCard()]);
        }

        // Sort the values
        sort(values.begin(), values.end());

        // Check if values behave as a straight
        for(int i = 0; i <= values.size()-5; i++){
            bool isOK = true;
            for(int j=1; j<5; j++){
                if(values[i+j] != values[i+j-1]+1){
                    isOK = false;
                    break;
                }
            }
            if(isOK){
                return true;
            }
        }
        return false;
    }
}

Card* maxOfHand(const vector<Card*>& hand){
    const vector<string> allCards={"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "1"};
    int indexTemp = -1;
    int indexMax = -1;
    for(int i=0; i<hand.size(); i++){
        for(int j=0; j<allCards.size(); j++){
            if (hand[i]->nameCard()==allCards[j]){
                if (indexTemp<j){
                    indexTemp = j;
                    indexMax = i;
                }
            }
        }
    }
    return hand[indexMax];
}

pair<string, vector<Card*>> handPlayed(const vector<Card*>& playHand){  // Return a pair containing the name of the poker hand, and the counting cards of this hand
    if (playHand.size()==1){
        return {"HighCard", playHand};
    }
    else{
        int count = 0;
        unordered_map<string, int> countCard;  // Container to assert the number of occurence of a card value in playHand 
        for (int i=0; i<playHand.size(); i++){
            string target=playHand[i]->nameCard();
            if (countCard.find(target) == countCard.end()){     // Check if the card value is not already in the container
                count = 0;
                for (int j=0; j<playHand.size(); j++){
                    if (i!=j & playHand[i]->nameCard()==playHand[j]->nameCard()){   // Increment for each same card in playHand
                        count++;
                    }
                }
                countCard.insert({target, count});
            }
        }
        int sum = 0;
        for (const auto& pair : countCard){     // Powered sum for identifying the poker playHand
            sum+=pow(10, pair.second);
        }
        vector<Card*> countingCards = {};   // Deliver the counting cards of playHand, i.e. cards with count > 0 (unless HighCard)
        for(int i=0; i<playHand.size(); i++){
                if (countCard[playHand[i]->nameCard()] != 0){
                    countingCards.push_back(playHand[i]);
                }
            }
        if (isFlush(playHand)){ // First check if playHand played is a Flush (Flush has priority over all playHands except FourOfAKind and FiveOfAKind)
            if (sum==110){
                return {"FlushHouse", playHand};
            }
            else if (sum==1001){
                return {"FourOfAKind", countingCards};
            }
            else if (sum==10000){
                return {"FlushFive", playHand};
            }
            else if (isStraight(playHand)){
                return {"StraightFlush", playHand};
            }
            else{
                return {"Flush", playHand};
            }
        }
        else if(isStraight(playHand)){  // Straight may be affected by jokers, but is not considered for now
            return {"Straight", playHand};
        }
        else{   // Get the poker playHand from the sum, in case of no Flush nor straight
            if (sum<=5){
                return {"HighCard", {maxOfHand(playHand)}};
            }
            if (sum<=13){
                return {"Pair", countingCards};
            }
            else if (sum<=21){
                return {"TwoPair", countingCards};
            }
            else if (sum<=102){
                return {"ThreeOfAKind", countingCards};
            }
            else if (sum<=110){
                return {"FullHouse", playHand};
            }
            else if (sum<=1001){
                return {"FourOfAKind", countingCards};
            }
            else if (sum<=10000){
                return {"FiveOfAKind", playHand};
            }
            else{   // Exception ?
                return {"Error", playHand};
            }
        }
    }
}

vector<double> scoreHand(const string& nameHand, const double& nbUp){
    if (nameHand=="HighCard"){
        return {5+nbUp*10, 1+nbUp*1};
    }
    else if (nameHand=="Pair"){
        return {10+nbUp*15, 2+nbUp*1};
    }
    else if (nameHand=="TwoPair"){
        return {20+nbUp*20, 2+nbUp*1};
    }
    else if (nameHand=="ThreeOfAKind"){
        return {30+nbUp*20, 3+nbUp*2};
    }
    else if (nameHand=="Straight"){
        return {30+nbUp*30, 4+nbUp*3};
    }
    else if (nameHand=="Flush"){
        return {35+nbUp*10, 4+nbUp*1};
    }
    else if (nameHand=="FullHouse"){
        return {40+nbUp*25, 4+nbUp*2};
    }
    else if (nameHand=="FourOfAKind"){
        return {60+nbUp*30, 7+nbUp*3};
    }
    else if (nameHand=="StraightFlush"){
        return {100+nbUp*40, 8+nbUp*4};
    }
    else if (nameHand=="FiveOfAKind"){
        return {120+nbUp*35, 12+nbUp*3};
    }
    else if (nameHand=="FlushHouse"){
        return {140+nbUp*40, 14+nbUp*4};
    }
    else if (nameHand=="FlushFive"){
        return {160+nbUp*50, 16+nbUp*3};
    }
    else{   // Exception ?
        return {0, 0};
    }
}

int retriggerCard(const bool& play, Card* card, const vector<Card*>& playHand, const vector<Card*> hand, const vector<Joker*>& jokerHand, const int& nbHand){
    int res(0);
    if (play) {
        if (card->sealCard() == "Red") {
            res++;
        }
        for (Joker* joker : jokerHand) {
            if (joker->jokerFunction(jokerHand) == "RetriggerPlayed") {
                res += joker->retriggerCount(card, playHand, jokerHand, nbHand);
            }
        }
    }
    else {
        if (card->sealCard() == "Red") {
            res++;
        }
        for (Joker* joker : jokerHand) {
            if (!play && joker->jokerFunction(jokerHand) == "RetriggerHeld") {
                res += joker->retriggerCount(card, hand, jokerHand, nbHand);
            }
        }
    }
    return res;
}

void addPlayedCards(vector<double>& score, const vector<Card*>& playHand,
    const vector<Card*>& hand, const vector<Joker*>& jokerHand, const int& nbHand){
    for (Card* card : playHand) {
        int nbRetrigg = retriggerCard(true, card, playHand, hand, jokerHand, nbHand);
        cout << "Carte : " << endl;
        card->displayCard();
        cout << "Nb retrigg : " << nbRetrigg << endl;
        for (int j=0; j<nbRetrigg+1; j++){
            card->addScore(score);
            for (Joker* joker : jokerHand) {
                if (joker->jokerFunction(jokerHand) == "OnScored") {
                    (*joker)(score, card, playHand, hand, jokerHand, nbHand);
                }
            }
        }
    }
}

void addHeld(vector<double>& score, const vector<Card*>& playHand,
    const vector<Card*>& hand, const vector<Joker*>& jokerHand, const int& nbHand){
    for (Card* card : hand) {
        int nbRetrigg = retriggerCard(false, card, playHand, hand, jokerHand, nbHand);
        cout << "On Held " << endl;
        card->displayCard();
        cout << "Retrigg : " << nbRetrigg << endl;
        for (int j=0; j<nbRetrigg+1; j++){
            if (card->appearenceCard() == "Steel") {
                score[1]*=1.5;
            }
            for (Joker* joker : jokerHand) {
                if (joker->jokerFunction(jokerHand) == "OnHeld") {
                    (*joker)(score, card, playHand, hand, jokerHand, nbHand);
                }
            }
        }
    }
}

void addJokerEdition(vector<double>& score, const Joker* joker) {
    if (joker->edition() == "Foil") {
        score[0]+=50;
    }
    else if (joker->edition() == "Holographic") {
        score[1]+=10;
    }
    else if (joker->edition() == "Polychrome") {
        score[1]*=1.5;
    }
}

vector<vector<Joker*>::const_iterator> findJokers(const vector<Joker*>& jokerHand, const string& targetName) {
    vector<vector<Joker*>::const_iterator> result;
    for (auto it = jokerHand.begin(); it != jokerHand.end(); ++it) {
        if ((*it)->nameJoker() == targetName) {
            result.push_back(it);
        }
    }
    return result;
}

vector<vector<Joker*>::const_iterator> itBaseball(const vector<Joker*>& jokerHand) {
    auto baseball = findJokers(jokerHand, "BaseballCard");
    auto brainstorm = findJokers(jokerHand, "Brainstorm"); 
    auto blueprint = findJokers(jokerHand, "Blueprint");
    vector<vector<Joker*>::const_iterator> result;
    if (!baseball.empty()) {
        if (!brainstorm.empty()) { 
            // Check if a BaseballCard joker is at first place in case of Brainstorm
            bool baseballAtBegin = any_of(baseball.begin(), baseball.end(), [&](auto it) { return it == jokerHand.begin(); });
            if (baseballAtBegin) {
                baseball.insert(baseball.end(), brainstorm.begin(), brainstorm.end());
            }
        }
        for (auto it : blueprint) {
            auto nextIt = it;
            ++nextIt;
            result = baseball;
            // Check if a Blueprint joker exist before a BaseballCard or a Brainstorm
            if (nextIt != jokerHand.end() && find(baseball.begin(), baseball.end(), nextIt) != baseball.end()) {
                result.push_back(it);
            } 
        }
    }
    return result;
}


void addHand(vector<double>& score, const vector<Card*>& playHand,
    const vector<Card*>& hand, const vector<Joker*>& jokerHand, const int& nbHand){
    auto allBaseballCard = itBaseball(jokerHand);
    for (Joker* joker : jokerHand) {
        addJokerEdition(score, joker);
        if (joker->jokerFunction(jokerHand) == "OnHand") {
            (*joker)(score, nullptr, playHand, hand, jokerHand, nbHand);
        }
        else if (!allBaseballCard.empty()) {
            for (auto itBaseball : allBaseballCard) {
                // Joker* baseball_temp = *itBaseball;
                // (*baseball_temp)(score, nullptr, playHand, hand, {joker}, nbHand);
                if (joker->rarityJoker() == "Uncommon") {
                    cout << "Un coup!" << endl;
                    score[1]*=1.5;
                }
            }
        }
    }
}