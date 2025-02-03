#ifndef DEF_CARD
#define DEF_CARD

#include <string>

class Card
{
    public:

    // Constructor
    Card(const std::string& name, const std::string& suit, const std::string& appearance = "None", 
         const std::string& edition = "None", const std::string& seal = "None", int chip = 0, int mult = 0);

    int chipBase() const;
    void addChip(const int& chip);
    void addMult(const int& mult);
    void addScore(float score[2]) const;
    std::string suitCard() const;
    std::string nameCard() const;
    std::string appearenceCard() const;
    void displayCard() const;

    private:

    void validateName(const std::string& name);
    void validateSuit(const std::string& suit);
    void validateAppearence(const std::string& appearence);
    void validateEdition(const std::string& edition);
    void validateSeal(const std::string& seal);

    std::string m_name;
    std::string m_suit;
    int m_chip;
    int m_mult;
    std::string m_appearance;
    std::string m_edition;
    std::string m_seal;
};

#endif