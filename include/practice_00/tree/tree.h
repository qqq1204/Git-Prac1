#ifndef PRACTICE_00_TREE_TREE_H_
#define PRACTICE_00_TREE_TREE_H_

#include <memory>

namespace practice_00
{
namespace tree
{
class Node;

class Tree
{
public:
    /// \brief Constructor of the Tree
    ///
    Tree();
    /// \brief Destructor of the Tree
    ///
    virtual ~Tree();
private:
    struct impl;
    std::unique_ptr<impl> data_;
};
/// \brief 
/// 
class AbstractNodeIterableFunctor
{
public:
    /// \brief Constructor of the Abstract Node Iterable Functor
    /// 
    AbstractNodeIterableFunctor()=default;
    /// \brief Destructor of the Abstract Node Iterable Functor
    /// 
    virtual ~AbstractNodeIterableFunctor()=default;
    /// \brief 
    /// 
    /// \param[] node 
    /// \return true 
    /// \return false 
    virtual bool Do(Node* node) = 0;
};
/// \brief 
/// 
class Node
{
public:
    /// \brief Constructor of the Node
    ///
    Node();
    /// \brief Destructor of the Node
    ///
    virtual ~Node();
    /// \brief
    ///
    /// \return unsigned int
    unsigned int GetID();
    
    virtual bool operator==(Node& other)const;
    /// \brief
    ///
    void SetParent(std::shared_ptr<Node> &parent);
    /// \brief
    ///
    void AppendChild(std::shared_ptr<Node> &child);
    /// \brief
    ///
    /// \param[] id
    void RemoveChild(unsigned int id);
    /// \brief 
    /// 
    /// \param[] func 
    /// \return true 
    /// \return false 
    bool ForEachBFS(AbstractNodeIterableFunctor* func);
    /// \brief 
    /// 
    /// \param[] func 
    /// \return true 
    /// \return false 
    bool ForEachDFS(AbstractNodeIterableFunctor* func);
    /// \brief 
    /// 
    /// \param[] func 
    /// \return true 
    /// \return false 
    bool ForEachIDS(AbstractNodeIterableFunctor* func);
    /// \brief 
    /// 
    virtual void Print();
private:
    struct impl;
    std::unique_ptr<impl> data_;
};

} // namespace tree
} // namespace practice_00
#endif // TREE_TREE_H_
