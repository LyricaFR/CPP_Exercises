#include "Pokemon.h"

int Pokemon::_id_cmpt = 0;

Pokemon::Pokemon(const std::string &name)
    : _name{name}, _id{_id_cmpt++}
{
}

Pokemon::Pokemon(const Pokemon &other)
    : _name{other.name()}, _id{_id_cmpt++}
{
}

const std::string Pokemon::name() const
{
    return _name;
}

int Pokemon::id() const
{
    return _id;
}

// Pokemon::~Pokemon()
// {
//     _id_cmpt--;
// }

Pokemon &Pokemon::operator=(const Pokemon &other)
{
    if (this != &other)
    {
        _name = other.name();
    }
    return *this;
}
