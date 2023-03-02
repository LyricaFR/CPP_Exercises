#pragma once
#include "Pokemon.h"

// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    bool empty() const;

    void store(PokemonPtr ptr);

    const Pokemon &pokemon() const;

private:
    PokemonPtr _pokemon;
};
