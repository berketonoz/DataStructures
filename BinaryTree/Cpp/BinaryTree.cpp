#include <iostream>
#include "BinaryTree.h"

int main(){
    BinaryTree<int> *tree = new BinaryTree<int>();
    tree->insert(13);
    tree->insert(31);
    tree->insert(72);
    tree->insert(54);
    tree->insert(66);
    tree->insert(91);

    tree->inorder(tree->getRoot());
    return 0;
}