#ifndef PRACTICE_00_TREE_SUM_ITERABLE_FUNCTOR_H_
#define PRACTICE_00_TREE_SUM_ITERABLE_FUNCTOR_H_

#include <memory>
#include "tree.h"

namespace practice_00
{
namespace tree
{
class SumIterableFunctor : public AbstractNodeIterableFunctor
{
public:
    SumIterableFunctor();
    virtual ~SumIterableFunctor() = default;
    virtual bool Do(Node *node);
    unsigned int GetSum();
private:
    unsigned int sum_;
};

template<typename T>
class SearchIterator : public AbstractNodeIterableFunctor
{
public:
    SearchIterator(const T& query):query_(query){}
    virtual ~SearchIterator() = default;
    virtual bool Do(Node *node){
        return query_ == *node;
private:
    T query_;
};


} // namespace tree
} // namespace practice_00
#endif // TREE_SUM_ITERABLE_FUNCTOR_H_
