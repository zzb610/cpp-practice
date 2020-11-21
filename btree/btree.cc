#include "btree.h"

template <typename ElemType>
BinaryTree<ElemType>::BinaryTree() : root_(0)
{
}

template <typename ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree &rhs)
{
    copy(root_, rhs.root_);
}

template <typename ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
    clear();
}

template <typename ElemType>
BinaryTree<ElemType> &BinaryTree<ElemType>::operator=(const BinaryTree &rhs)
{
    if (this != &rhs)
    {
        clear();
        copy(root_, rhs.root_);
    }
    return *this;
}

template <typename ElemType>
void BinaryTree<ElemType>::insert(const ElemType &elem)
{
    if (!root_)
    {
        root_ = new BTNode<ElemType>(elem);
    }
    else
    {
        root_->InsertValue(elem);
    }
}

template <typename ElemType>
void BinaryTree<ElemType>::RemoveRoot()
{
    if (!root_)
    {
        return;
    }

    BTNode<ElemType> *tmp = root_;
    if (root_->rchild_)
    {
        root_ = root_->rchild_;

        if (tmp->lchild_)
        {
            BTNode<ElemType> *lc = tmp->lchild_;
            BinaryTree<ElemType> *newlc = root_->lchild_;

            if (!newlc)
            {
                root_->lchild_ = lc;
            }
            else
            {
                BTNode<ElemType>::LChildLeaf(lc, newlc);
            }
        }
    }
    else
    {
        root_ = root_->lchild_;
    }
    delete tmp;
}
