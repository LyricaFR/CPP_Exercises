#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>

class Node : public InstanceCounter
{
public:
    NodeKind            kind();
    virtual std::string print() const = 0;

    virtual ~Node() = 0;

private:
    NodeKind _kind;

protected:
    Node(NodeKind kind);
};

using NodePtr = std::unique_ptr<Node>;