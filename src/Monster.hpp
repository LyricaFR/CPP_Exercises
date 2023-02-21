#pragma once
#include <string>
#include "Card.hpp"

using namespace std;

enum Attribute {
    Dark, Divine, Earth, Fire, Light, Water, Wind
};

string to_symbol(Attribute attribute){
    switch(attribute){
        case Dark: return u8"闇";
        case Divine: return u8"神";
        case Earth: return u8"地";
        case Fire: return u8"炎";
        case Light: return u8"光";
        case Water: return u8"水";
        case Wind: return u8"風";
        default: return "Invalid attribute";
    }
}

class Monster : public Card
{
public:
    Monster(string id, string name, Attribute attribute, string property, int atk, int def)
    : Card {id, CardType::Monster}
    , _attribute {attribute}
    , _property {property}
    , _atk {atk}
    , _def {def}
    {set_name(name);}

    Attribute get_attribute() const {
        return _attribute;
    }

    int get_atk() const {
        return _atk;
    }

    int get_def() const {
        return _def;
    }

    string get_description() const{
        return "[" + _property + "]\n" + Card::get_description() + "\nATK/" + std::to_string(_atk) + " DEF/" + std::to_string(_def);
    }

private:
    Attribute _attribute;
    string _property;
    int _atk = 0;
    int _def = 0;
};