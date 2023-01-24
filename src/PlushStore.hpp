#pragma once

#include <string>
#include <vector>

class PlushStore{
    public:

    PlushStore(std::string name)
    : _name {name}
    {}

    std::string get_name() const {
        return _name;
    }

    unsigned int get_wealth_amount() const {
        return _wealth;
    }

    unsigned int get_stock_size() const {
        return _stock;
    }

    void loan(int value) {
        _wealth += value;
        _debt += value * 1.1;
    }

    int get_debt_amount() const {
        return _debt;
    }

    int get_experience() const {
        return _experience;
    }

    int make_plush(unsigned int cost){
        if (_wealth == 0) {
            return 0;
        }
        if (cost <= _wealth){
            _wealth -= cost;
            _stock++;
        }
        else {
            _wealth = 0;
            _stock++;
        }
        _experience++;
        plushies.emplace_back(Plush(cost + _experience));
        return cost + _experience;
    }

    std::optional<Plush> buy(int price){
        for (int i = 0; i < plushies.size(); i++){
            if (price > plushies.at(1).get_cost())
                return
        }
    }

    private:
    std::string _name;
    unsigned int _wealth = 0;
    unsigned int _stock = 0;
    int _debt = 0;
    int _experience = 0;
    std::vector<Plush> plushies;
};