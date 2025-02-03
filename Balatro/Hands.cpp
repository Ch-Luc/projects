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
        std::unordered_map<string, int> countCard;  // Container to assert the number of occurence of a card value in hand 
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
            sum+=std::pow(10, pair.second);
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
        std::unordered_map<std::string, int> cardValues = {
                {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6},
                {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}
        };

        // Get int values of cards (exception for Ace in case of royal straight or low straight)
        std::vector<int> values;
        bool hasAce = false;
        for(int i=0; i<hand.size(); i++){
            if(hand[i]->nameCard() == "1"){
                hasAce = true;
                values.push_back(14);
            }
            values.push_back(cardValues[hand[i]->nameCard()]);
        }

        // Sort the values
        std::sort(values.begin(), values.end());

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

pair<string, vector<Card*>> handPlayed(const vector<Card*>& hand){
    if (hand.size()==1){
        return {"HighCard", hand};
    }
    else{
        int count = 0;
        unordered_map<string, int> countCard;  // Container to assert the number of occurence of a card value in hand 
        for (int i=0; i<hand.size(); i++){
            string target=hand[i]->nameCard();
            if (countCard.find(target) == countCard.end()){     // Check if the card value is not already in the container
                count = 0;
                for (int j=0; j<hand.size(); j++){
                    if (i!=j & hand[i]->nameCard()==hand[j]->nameCard()){
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
        if (sum<=5){
            return {"HighCard", {maxOfHand(hand)}};
        }
        vector<Card*> countingCards = {};
        for(int i=0; i<hand.size(); i++){
                if (countCard[hand[i]->nameCard()] != 0){
                    countingCards.push_back(hand[i]);
                }
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
            if (isFlush(hand)){
                return {"FlushHouse", hand};
            }
            else{
                return {"FullHouse", hand};
            }
        }
        else if (sum<=1001){
            return {"FourOfAKind", countingCards};
        }
        else if (sum<=10000){
            if (isFlush(hand)){
                return {"FlushFive", hand};
            }
            else{
                return {"FiveOfAKind", hand};
            }
        }
        else{
            if (isStraight(hand)){
                if (isFlush(hand)){
                    return {"StraightFlush", hand};
                }
                else{
                    return {"Straight", hand};
                }
            }
            else if (isFlush(hand)){
                return {"Flush", hand};
            }
            else{
                return {"Error!", {}};
            }
        }
    }
}

array<int, 2> scoreHand(const string& nameHand, const int& nbUp){
    if (nameHand=="HighCard"){
        return {5+nbUp*10, 1+nbUp*1};
    }
    if (nameHand=="Pair"){
        return {10+nbUp*15, 2+nbUp*1};
    }
    if (nameHand=="TwoPair"){
        return {20+nbUp*20, 2+nbUp*1};
    }
    if (nameHand=="ThreeOfAKind"){
        return {30+nbUp*20, 3+nbUp*2};
    }
    if (nameHand=="Straight"){
        return {30+nbUp*30, 4+nbUp*3};
    }
    if (nameHand=="Flush"){
        return {35+nbUp*10, 4+nbUp*1};
    }
    if (nameHand=="FullHouse"){
        return {40+nbUp*25, 4+nbUp*2};
    }
    if (nameHand=="FourOfAKind"){
        return {60+nbUp*30, 7+nbUp*3};
    }
    if (nameHand=="StraightFlush"){
        return {100+nbUp*40, 8+nbUp*4};
    }
    if (nameHand=="FiveOfAKind"){
        return {120+nbUp*35, 12+nbUp*3};
    }
    if (nameHand=="FlushHouse"){
        return {140+nbUp*40, 14+nbUp*4};
    }
    if (nameHand=="FlushFive"){
        return {160+nbUp*50, 16+nbUp*3};
    }
    else{
        return {0, 0};
    }
}