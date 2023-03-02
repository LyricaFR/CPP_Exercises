#include "PC.h"

std::vector<PokemonPtr> &PC::pokemons()
{
    return _pokemons;
}

void PC::transfer(PokemonPtr ptr)
{
    _pokemons.emplace_back(std::move(ptr));
}