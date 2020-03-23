#include "practice_00/tree/tree.h"
#include <list>
#include <stack>
#include <queue>
#include <atomic>
#include <iostream>

namespace practice_00
{
namespace tree
{

struct Node::impl
{
    unsigned int id_;
    std::list<std::shared_ptr<Node>> children_;
    std::weak_ptr<Node> parent_;
};

Node::Node() : data_(new impl)
{
}
Node::~Node()
{
}
unsigned int Node::GetID()
{
}
void Node::SetParent(std::shared_ptr<Node> &parent)
{
}
void Node::AppendChild(std::shared_ptr<Node> &child)
{
}
void Node::RemoveChild(unsigned int id)
{
}
bool Node::ForEachBFS(AbstractNodeIterableFunctor *func)
{
    
    /// \todo queue 를 사용해 완성할 것.
}
bool Node::ForEachDFS(AbstractNodeIterableFunctor *func)
{
    ///\todo stack을 이용한 것으로 바꿀 것
    if (!func->Do(this))
    {
        return true;
    }
    for (auto &child : data_->children_)
    {
        if (!ForEachBFS(func))
        {
            return true;
        }
    };
    return false;
}
bool Node::ForEachIDS(AbstractNodeIterableFunctor *func)
{
    ///\todo iterative deepening search 공부할 것.
}

void Node::Print()
{
    std::cout << "WARN: No Print() method implemneted!" << std::endl;
}
}
}