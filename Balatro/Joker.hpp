#ifndef DEF_JOKER
#define DEF_JOKER

#include <vector>
#include <stdexcept>
#include "Card.hpp"

class Joker{
    protected:
    std::string m_edition;
    public:
    Joker(const std::string& edition) {
        if (edition != "None" && edition != "Foil" && edition != "Holographic" && edition != "Polychrome" && edition != "Negative") {
            throw std::invalid_argument("Invalid edition.");
        }
        m_edition = edition;
    }
    std::string edition() const {return m_edition;}
    virtual void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const = 0;
    virtual int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const = 0;
    virtual std::string nameJoker() const = 0;
    virtual std::string jokerFunction(const std::vector<Joker*> jokerHand) const = 0;
    virtual std::string rarityJoker() const = 0;
};

// On scored card impact
class GreedyJoker : public Joker{
    public:
    GreedyJoker(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class LustyJoker : public Joker{
    public:
    LustyJoker(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class WrathfulJoker : public Joker{
    public:
    WrathfulJoker(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class GluttonousJoker : public Joker{
    public:
    GluttonousJoker(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

// Retrigger jokers
class Hangingchad : public Joker{
    public:
    Hangingchad(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class Hack : public Joker{
    public:
    Hack(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class Seltzer : public Joker{
    public:
    Seltzer(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class SockAndBuskin : public Joker{
    public:
    SockAndBuskin(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class Dusk : public Joker{
    public:
    Dusk(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
}; 

// On hand impact
class DrollJoker : public Joker{
    public:
    DrollJoker(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class DeviousJoker : public Joker{
    public:
    DeviousJoker(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

// On Held 
class Baron : public Joker{
    public:
    Baron(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class ShootTheMoon : public Joker{
    public:
    ShootTheMoon(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class RaisedFist : public Joker{
    public:
    RaisedFist(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class Mime : public Joker{
    public:
    Mime(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

// Special
class Blueprint : public Joker{
    public:
    Blueprint(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class Brainstorm : public Joker{
    public:
    Brainstorm(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class BaseballCard : public Joker{
    public:
    BaseballCard(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

class Pareidolia : public Joker{
    public:
    Pareidolia(const std::string& edition) : Joker(edition) {}
    void operator()(std::vector<double>& score, const Card* card, const std::vector<Card*>& playHand,
        const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    int retriggerCount(const Card* card, const std::vector<Card*>& hand, const std::vector<Joker*>& jokerHand, const int& nbHand) const override;
    std::string nameJoker() const override;
    std::string jokerFunction(const std::vector<Joker*> jokerHand) const override;
    std::string rarityJoker() const override;
};

#endif