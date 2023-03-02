#pragma once

#include <string>
#include <memory>

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(const std::string &name);

    const std::string name() const;

    static int _id_cmpt;

    int id() const;

    // ~Pokemon();

    Pokemon &operator=(const Pokemon &other);

    Pokemon(const Pokemon &other);

private:
    std::string _name;
    int _id = 0;
};

using PokemonPtr = std::unique_ptr<Pokemon>;