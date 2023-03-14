#pragma once
#include "Node.hpp"
#include <map>

class ObjectNode: public Node {
    public:
    ObjectNode();
    NodeKind kind();
    std::string print() const override;
    static std::unique_ptr<ObjectNode> make_ptr();
    int child_count();
    void insert(const std::string& key, NodePtr value);

    private:
    std::map<std::string, NodePtr> _array;
};