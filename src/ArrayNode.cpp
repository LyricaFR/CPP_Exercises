#include "ArrayNode.hpp"

ArrayNode::ArrayNode():
    Node{NodeKind::ARRAY}
    {}

NodeKind ArrayNode::kind(){
    return NodeKind::ARRAY;
}

std::unique_ptr<ArrayNode> ArrayNode::make_ptr(){
    return std::make_unique<ArrayNode>();
}

int ArrayNode::child_count() const{
    return _array.size();
}

void ArrayNode::push_back(NodePtr ptr){
    _array.push_back(std::move(ptr));
}