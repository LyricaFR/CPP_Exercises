#pragma once
#include "Leaf.hpp"

class StringLeaf: public Leaf {
    public:
    StringLeaf(std::string string);

    std::string print() const override { return "\"" + _data + "\"";}

    NodeKind kind();

    std::string data() const;

    static NodePtr make_ptr(const std::string& str);

    private:
    std::string _data;
};