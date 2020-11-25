#ifndef __BTNODE_H__
#define __BTNODE_H__

#include <iostream>
using std::ostream;

template <typename T>
class BinaryTree;

template <typename ValType>
class BTNode
{
public:
    BTNode(const ValType &val);
    void InsertValue(const ValType &val);
    static void LChildLeaf(BTNode *leaf, BTNode *subtree);
    void RemoveValue(const ValType &val, BTNode *&prev);
    void PreOrder(BTNode *pt, ostream &os) const;
    void InOrder(BTNode *pt, ostream &os) const;
    void PostOrder(BTNode *pt, ostream &os) const;
    void DisplayVal(BTNode *pt, ostream &os) const;

private:
    ValType val_;
    int cnt_;
    BTNode *lchild_;
    BTNode *rchild_;

    friend class BinaryTree<ValType>;
};

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

template <typename ValType>
void BTNode<ValType>::RemoveValue(const ValType &val, BTNode *&prev)
{
    if (val < val_)
    {
        if (!lchild_)
        {
            // not in this three
            return;
        }
        else
        {
            lchild_->RemoveValue(val, lchild_);
        }
    }
    else if (val > val_)
    {
        if (!rchild_)
        {
            // not in this tree
            return;
        }
        else
        {
            rchild_->RemoveValue(val, rchild_);
        }
    }
    else
    {
        if (rchild_)
        {
            prev = rchild_;
            if (lchild_)
            {
                if (prev->lchild_)
                {
                    BTNode::LChildLeaf(lchild_, prev->lchild_);
                }
                else
                {
                    prev->lchild_ = lchild_;
                }
            }
        }
        else
        {
            prev = lchild_;
        }
        delete this;
    }
}

template <typename ValType>
void BTNode<ValType>::PreOrder(BTNode *pt, ostream &os) const
{
    if (pt)
    {
        DisplayVal(pt, os);
        if (pt->lchild_)
        {
            PreOrder(pt->lchild_, os);
        }
        if (pt->rchild_)
        {
            PreOrder(pt->rchild_, os);
        }
    }
}

template <typename ValType>
void BTNode<ValType>::InOrder(BTNode *pt, ostream &os) const
{
    if (pt)
    {
        if (pt->lchild_)
        {
            PreOrder(pt->lchild_, os);
        }
        DisplayVal(pt, os);
        if (pt->rchild_)
        {
            PreOrder(pt->rchild_, os);
        }
    }
}

template <typename ValType>
void BTNode<ValType>::PostOrder(BTNode *pt, ostream &os) const
{
    if (pt)
    {
        if (pt->lchild_)
        {
            PreOrder(pt->lchild_, os);
        }
        if (pt->rchild_)
        {
            PreOrder(pt->rchild_, os);
        }
        DisplayVal(pt, os);
    }
}

template <typename ValType>
void BTNode<ValType>::DisplayVal(BTNode *pt, ostream &os) const
{
    if (pt)
    {
        os << pt->val_ << " ";
    }
}

#endif // __BTNODE_H__