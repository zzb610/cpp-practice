#include "btree.h"
#include <iostream>
#include <string>

using namespace std;

int main(int, char **)
{
    std::cout << "Hello, world!\n";
    BinaryTree<string> bt;
    bt.insert("Piglet");
    bt.insert("Eayore");
    bt.insert("Roo");
    bt.insert("Tigger");
    bt.insert("Chris");
    bt.insert("Pooh");
    bt.insert("Kanga");

    cout << "Preorder traversal: \n";
    bt.PreOrder();
    cout << "\n";
    cout << "Inorder traversal: \n";
    bt.InOrder();
    cout << "\n";
    cout << "Postorder traversal: \n";
    bt.PostOrder();
    cout << "\n";

    bt.remove("Piglet");
    cout << "Preorder traversal after Piglet removal: \n";
    bt.PreOrder();
    cout << "\n";

    bt.remove("Eayore");
    cout << "Preorder traversal after Eayore removal: \n";
    bt.PreOrder();
    cout << "\n";

    cout << bt << endl;
}
