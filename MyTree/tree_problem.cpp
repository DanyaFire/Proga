#include "Tree.h"

int main(void) {
    AVLTree<int,std::string> Database;
    Database.insert(0,"Рост");
    Database.printTree();
    return 0;
}