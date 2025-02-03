#ifndef DEF_DECK
#define DEF_DECK

#include <vector>
#include "Card.hpp"
#include <cstdlib>                                                   
#include <ctime>                                                  
using namespace std;

class CardUtils {
public:
    static const vector<string>& getValues();

    static const vector<string>& getSuits();
};

vector<Card> standardDeck();

vector<Card> abandonnedDeck();

vector<Card> checkeredDeck();

vector<Card> erraticDeck();

#endif