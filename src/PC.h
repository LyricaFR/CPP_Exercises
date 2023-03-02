#pragma once
#include <vector>
#include <Pokeball.h>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    std::vector<PokemonPtr> &pokemons();
    void transfer(PokemonPtr ptr);

private:
    std::vector<PokemonPtr> _pokemons;
};
