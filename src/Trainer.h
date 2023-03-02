#pragma once
#include "PC.h"
#include <string>
#include <array>

// A person that captures Pokemons and makes them fight.
class Trainer
{
public:
    Trainer(const std::string &name, PC &pc);
    const std::string name() const;
    const std::array<Pokeball, 6> &pokeballs() const;
    void capture(PokemonPtr ptr);

private:
    const std::string _name;
    PC &_pc;
    int _nb_captured = 0;
    std::array<Pokeball, 6> _pokeballs;
};
