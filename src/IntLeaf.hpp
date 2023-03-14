#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

class IntLeaf : public Leaf{
    public: 
    IntLeaf(int value);
    std::string print() const override { return std::to_string(_data); }
    NodeKind kind();
    int data() const;
    static std::unique_ptr<IntLeaf> make_ptr(int val);
    
    private:
    int _data = 0;
};