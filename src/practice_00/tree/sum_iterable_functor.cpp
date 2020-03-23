#include "practice_00/tree/sum_iterable_functor.h"

namespace practice_00
{
namespace tree
{
SumIterableFunctor::SumIterableFunctor()
    : sum_(0){};
unsigned int SumIterableFunctor::GetSum()
{
    return sum_;
}
bool SumIterableFunctor::Do(Node *node)
{
    sum_ += node->GetID();
    return true;
}


}
}