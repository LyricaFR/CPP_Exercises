#include "ObjectNode.hpp"

ObjectNode::ObjectNode():
    Node{NodeKind::OBJECT}
    {}

NodeKind ObjectNode::kind(){
    return NodeKind::OBJECT;
}

std::string ObjectNode::print() const{
    return "{}";
}

std::unique_ptr<ObjectNode> ObjectNode::make_ptr(){
    return std::make_unique<ObjectNode>();
}

int ObjectNode::child_count(){
    return _array.size();
}

void ObjectNode::insert(const std::string& key, NodePtr value){
    _array.insert_or_assign(key, std::move(value));
}