#ifndef __BTREE_H__
#define __BTREE_H__

#include "btnode.h"

template <typename ElemType>
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(const BinaryTree &rhs);
    ~BinaryTree();
    BinaryTree &operator=(const BinaryTree &rhs);

    bool empty() const { return root_ == 0; }
    void clear();
    void insert(const ElemType &elem);

    void RemoveRoot();

private:
    BTNode<ElemType> *root_;
};
#endif // __BTREE_H__