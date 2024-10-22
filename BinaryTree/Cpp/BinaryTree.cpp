#include <iostream>
#include "BinaryTree.h"

int main(){
    BinaryTree<int> *tree = new BinaryTree<int>();
    tree->insert(31);
    tree->insert(13);
    tree->insert(23);
    tree->insert(54);
    tree->insert(72);
    tree->insert(91);

    tree->inorder();
    tree->deleteNode(14);
    tree->inorder();
    tree->deleteNode(15);
    tree->inorder();
    tree->deleteNode(13);
    tree->inorder();
    tree->deleteNode(31);
    tree->inorder();
    tree->deleteNode(54);
    tree->inorder();
    tree->deleteNode(13);
    tree->inorder();
    tree->~BinaryTree();
    std::cout << "Tree destroyed" << std::endl;

    return 0;
}