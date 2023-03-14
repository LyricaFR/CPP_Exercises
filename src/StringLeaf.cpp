#include "StringLeaf.hpp"

StringLeaf::StringLeaf(std::string string):
    Leaf{NodeKind::STRING},
    _data { string }
    {}

NodeKind StringLeaf::kind(){
    return NodeKind::STRING;
}

std::string StringLeaf::data() const{
    return _data;
}

NodePtr StringLeaf::make_ptr(const std::string& str){
    return std::make_unique<StringLeaf>(str);
}