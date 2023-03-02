#include "Pokeball.h"

bool Pokeball::empty() const
{
    return _pokemon == nullptr;
}

void Pokeball::store(PokemonPtr ptr)
{
    _pokemon = std::move(ptr);
}

const Pokemon &Pokeball::pokemon() const
{
    return *_pokemon;
}