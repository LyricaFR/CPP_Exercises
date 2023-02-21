#pragma once
#include <string>
#include "Card.hpp"
using namespace std;

enum SpellType{
    Normal, Equip, Continuous, QuickPlay, Field
};

string to_string(SpellType spell){
    switch (spell){
        case Normal: return "Normal";
        case Equip: return "Equip";
        case Continuous: return "Continuous";
        case QuickPlay: return "Quick-Play";
        case Field: return "Field";
        default: return "invalid spell type";
    }
}

class Spell : public Card
{
public:
    Spell(string id, string name, SpellType type) 
        : Card {id, CardType::Spell}
        , _spellType {type}
    {set_name(name);}

    SpellType get_spell_type(){
        return _spellType;
    }

private:
    SpellType _spellType;

};