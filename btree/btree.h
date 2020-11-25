#ifndef __BTREE_H__
#define __BTREE_H__

#include "btnode.h"

#include <iostream>

using std::cout;
using std::ostream;

template <typename ElemType>
ostream &operator<<(ostream &os, const BinaryTree<ElemType> &bt);

template <typename ElemType>
class BinaryTree
{

    friend ostream &operator<<<ElemType>(ostream &os, const BinaryTree<ElemType> &bt);

public:
    BinaryTree();
    BinaryTree(const BinaryTree &rhs);
    ~BinaryTree();
    BinaryTree &operator=(const BinaryTree &rhs);

    bool empty() const { return root_ == 0; }
    void clear()
    {
        if (root_)
        {
            clear(root_);
            root_ = 0;
        }
    };

    void insert(const ElemType &elem);
    void remove(const ElemType &elem);
    void RemoveRoot();

    void PreOrder(ostream &os = cout) const
    {
        if (root_)
        {
            root_->PreOrder(root_, os);
        }
    };

    void InOrder(ostream &os = cout) const
    {
        if (root_)
        {
            root_->InOrder(root_, os);
        }
    }
    void PostOrder(ostream &os = cout) const
    {
        if (root_)
        {
            root_->PostOrder(root_, os);
        }
    }

    static ostream *os();
    static void current_os(ostream *os);

    ostream &print(ostream &os = *current_os_, void (BinaryTree<ElemType>::*traversal)(ostream &os) const = &BinaryTree<ElemType>::PreOrder) const;

private:
    void clear(BTNode<ElemType> *pt);
    BTNode<ElemType> *root_;
    static ostream *current_os_;
};

template <typename ElemType>
ostream *BinaryTree<ElemType>::current_os_ = 0;

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
void BinaryTree<ElemType>::remove(const ElemType &elem)
{
    if (root_)
    {
        if (root_->val_ == elem)
        {
            RemoveRoot();
        }
        else
        {
            root_->RemoveValue(elem, root_);
        }
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
            BTNode<ElemType> *newlc = root_->lchild_;

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

template <typename ElemType>
ostream *BinaryTree<ElemType>::os()
{
    return current_os_;
}

template <typename ElemType>
void BinaryTree<ElemType>::current_os(ostream *os)
{
    if (os)
    {
        current_os_ = os;
    }
}

template <typename ElemType>
ostream &BinaryTree<ElemType>::print(ostream &os, void (BinaryTree<ElemType>::*traversal)(ostream &os) const) const
{
    (this->*traversal)(os);
    return os;
}

template <typename ElemType>
void BinaryTree<ElemType>::clear(BTNode<ElemType> *pt)
{
    if (pt)
    {
        clear(pt->lchild_);
        clear(pt->rchild_);
        delete pt;
    }
}

template <typename ElemType>
ostream &operator<<(ostream &os, const BinaryTree<ElemType> &bt)
{
    os << "ALL Tree: ";
    bt.print(os);
    return os;
}

#endif // __BTREE_H__