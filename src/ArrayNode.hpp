#pragma once
#include "Node.hpp"
#include <array>
#include <vector>

class ArrayNode : public Node {
    public:

    ArrayNode();
    NodeKind kind();
    std::string print() const override{
        std::string str = "[";
        std::string separator = "";
        for (auto& elem : _array){
            str.append(separator + elem->print());
            separator = ",";
        }

        str.append("]");
        return str;
    }

    static std::unique_ptr<ArrayNode> make_ptr();

    int child_count() const;

    void push_back(NodePtr ptr);

    private:
    std::vector<NodePtr> _array;
};