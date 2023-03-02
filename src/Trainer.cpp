#include "Trainer.h"

Trainer::Trainer(const std::string &name, PC &pc)
    : _name{name}, _pc{pc}
{
}

const std::string Trainer::name() const
{
    return _name;
}

const std::array<Pokeball, 6> &Trainer::pokeballs() const
{
    return _pokeballs;
}

void Trainer::capture(PokemonPtr ptr)
{
    for (auto &pokeball : _pokeballs)
    {
        if (pokeball.empty())
        {
            pokeball.store(std::move(ptr));
            return;
        }
    }
    _pc.transfer(std::move(ptr));
}