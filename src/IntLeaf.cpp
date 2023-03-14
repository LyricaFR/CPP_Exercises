#include "IntLeaf.hpp"

IntLeaf::IntLeaf(int data):
    Leaf{NodeKind::INT},
    _data {data}
    {}

NodeKind IntLeaf::kind(){
    return NodeKind::INT;
}

int IntLeaf::data() const { return _data;}

std::unique_ptr<IntLeaf> IntLeaf::make_ptr(int val){
    return std::make_unique<IntLeaf>(val);
}