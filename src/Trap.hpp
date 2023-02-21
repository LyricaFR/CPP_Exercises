#pragma once
#include <string>
#include "Card.hpp"
using namespace std;

enum TrapType{
    Normal, Continuous, Counter
};

string to_string(TrapType type){
    switch (type){
        case Normal: return "Normal";
        case Continuous: return "Continuous";
        case Counter: return "Counter";
        default: return "invalid trap type";
    }
}

class Trap : public Card {
public:
    Trap(string id, string name, TrapType type)
    : Card {id, CardType::Trap}
    , _trapType {type}
    {set_name(name);}

    TrapType get_trap_type(){
        return _trapType;
    }

private:
    TrapType _trapType;
};