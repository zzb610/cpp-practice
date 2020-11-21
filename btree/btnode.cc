#include "btnode.h"

template <typename ValType>
BTNode<ValType>::BTNode(const ValType &val) : val_(val), cnt_(1), lchild_(0), rchild_(0)
{
}

template <typename ValType>
void BTNode<ValType>::InsertValue(const ValType &val)
{
    if (val == val_)
    {
        ++cnt_;
        return;
    }

    if (val < val_)
    {
        if (!lchild_)
        {
            lchild_ = new BTNode(val);
        }
        else
        {
            lchild_->InsertValue(val);
        }
    }
    else if (val > val_)
    {
        if (!rchild_)
        {
            rchild_ = new BTNode(val);
        }
        else
        {
            rchild_->InsertValue(val);
        }
    }
}

template <typename ValType>
void BTNode<ValType>::LChildLeaf(BTNode *leaf, BTNode *subtree)
{
    while (subtree->lchild_)
    {
        subtree = subtree->lchild_;
    }
    subtree->lchild_ = leaf;
}
