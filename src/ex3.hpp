#pragma once
#include <cstddef>
#include <list>
#include <set>
#include <type_traits>
#include <vector>
template <unsigned val>
constexpr unsigned fibonacci()
{
    if constexpr (val < 2)
        return 1;
    else
        return fibonacci<val - 1>() + fibonacci<val - 2>();
}

template <typename T1, typename T2>
constexpr bool content_of_same_type()
{
    return std::is_same<typename T1::value_type, typename T2::value_type>::value;
}

template <typename T1, typename T2>
void add_all(T1& t1, const T2& t2)
{
    if constexpr (std::is_same<typename T1::value_type, typename T2::value_type>::value)
    {
        for (auto i : t2)
        {
            t1.emplace_back(i);
        }
    }
}

template <typename T>
constexpr bool has_random_access()
{
    return std::is_same<typename std::random_access_iterator_tag,
                        typename std::iterator_traits<typename T::iterator>::iterator_category>::value;
}

template <typename T>
int access(T const& container, unsigned i)
{
    if constexpr (has_random_access<T>())
    {
        return container[i];
    }
    else
    {
        auto it = container.begin();
        for (auto j = 0; j < i; j++)
        {
            it++;
        }
        return *it;
    }
}
