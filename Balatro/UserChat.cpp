#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>

#include "Card.hpp"
#include "UserChat.hpp"
#include "Hands.hpp"

using namespace std;

bool getYesOrNo() {
    string choice;
    while (true) {
        getline(cin, choice);
        if (choice == "yes") {
            return true;
        }
        else if (choice == "no") {
            return false;
        }
        else {
            cout << "Invalid input. Please input 'yes' or 'no'." << endl;
        }
    }
}

vector<int> extractInts(const string& input){
    vector<int> result;
    regex delimiter("[,; ]+"); // Manage different delimiters: , ; and space
    sregex_token_iterator it(input.begin(), input.end(), delimiter, -1);
    sregex_token_iterator end;

    for (; it != end; ++it) {
        string token = *it;
        if (!token.empty()) { // Avoid consecutive delimiter
            try {
                result.push_back(stoi(token)); // Convert to int
            } catch (const exception& e) {
                cerr << "Error: '" << token << "' is not a valid integer." << endl;
                return {}; // Empty vector return if erorr
            }
        }
    }
    return result;
}

void displayCardsFromInt(const vector<Card*>& hand, const vector<int>& selection){
    vector<Card*> temp;
    for (auto it = selection.begin(); it != selection.end(); it++){
        temp.push_back(hand[*it]);
    }
    displayHand(temp);
}

vector<int> getCards(const vector<Card*>& hand){
    vector<int> res;
    string choice;
    bool userChoice = true;
    while(userChoice) {
        cout << "Cards in Hand:" << endl;
        displayHand(hand);
        cout << "Which cards do you want to discard?" << endl << "Input the position of the card, starting at 0 with a delimiter , ; or space" << endl;
        getline(cin, choice);
        res = extractInts(choice);
        if (res.size() > min(static_cast<int>(hand.size()), 5)){
            cout << "Error. Discarded cards cannot exceed 5 or the number of cards in hand (if <5)." << endl;
        }
        else if (res.size()==0){
            cout << "No cards were selected. Do you still want to discard ?" << endl;
            userChoice = getYesOrNo();
        }
        else{
            displayCardsFromInt(hand, res);
            cout << "Do you want to continue with the selection ?" << endl;
            userChoice = !getYesOrNo();
        }
    }
    return res;
}

vector<int> playedCards(const vector<Card*>& hand){
    vector<int> res;
    string choice;
    bool userChoice = true;
    while(userChoice) {
        cout << "What cards do you want to play?" << endl;
        getline(cin, choice);
        res = extractInts(choice);
        if (res.empty()){
            cout << "Please select cards to play." << endl;
        }
        else if (res.size() >= 5){
            cout << "Please select a maximum of 5 cards." << endl;
        }
        else{
            displayCardsFromInt(hand, res);
            cout << "Do you want to continue with the selection ?" << endl;
            userChoice = !getYesOrNo();
        }
    }
    return res;
}