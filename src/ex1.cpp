#include "ex1.hpp"

void pairwise_concatenate(std::list<std::list<int>>& list1, std::list<std::list<int>>& list2)
{
    for (int i = list1.size(); i < list2.size(); i++)
    {
        list1.emplace_back();
    }

    auto it1 = list1.begin();
    for (auto it2 = list2.begin(); it2 != list2.end();)
    {
        concatenate(*it1, *it2);
        it1++;
        it2++;
    }
}

void pairwise_concatenate(std::list<std::list<int>>& list1, std::list<std::list<int>>&& list2)
{
    for (int i = list1.size(); i < list2.size(); i++)
    {
        list1.emplace_back();
    }

    auto it1 = list1.begin();
    for (auto it2 = list2.begin(); it2 != list2.end();)
    {
        concatenate(*it1, std::move(*it2));
        it1++;
        it2++;
    }
}