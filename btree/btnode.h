template <typename T>
class BinaryTree;

template <typename ValType>
class BTNode
{
public:
    BTNode(const ValType &val);
    void InsertValue(const ValType &val);
    static void LChildLeaf(BTNode *leaf, BTNode *subtree);

private:
    ValType val_;
    int cnt_;
    BTNode *lchild_;
    BTNode *rchild_;

    friend class BinaryTree<ValType>;
};