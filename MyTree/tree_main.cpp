#include "Tree.h"


int main() {
    // Пример использования реализованного класса AVLTree
    AVLTree<int,int> tree;
    int result, result1;
    // Заполнение AVL-дерева
    for(int i = 0; i < 10; i++) {
        tree.insert(i, i-100);
    }
    for(AVLTree<int,int>::iterator i = tree.begin(); i != tree.end(); ++i) {
        cout<<"("<<*i<<")";
    }
    cout<<endl;
    try {
        if(tree.tree_depth() < 0) {
            throw("Дерево_пусто!\n");
        } else { 
            cout<<"Глубина дерева: "<<tree.tree_depth()<<endl;
        } 
        if(tree.depth(0) < 0) {
            throw Exception{"Звена с таким ключом не существует!\n"};
        } else {
            cout<<"Глубина 0-ого эл-та: "<<tree.depth(0)<<endl;
        }
        if(tree.depth(0) < 0) { 
            throw Exception{"Звена с таким ключом не существует!\n"};
        } else {
            cout<<" Глубина 15-ого эл-та: "<< tree.depth(15)<<endl;
        }
        if(tree.search(7,result)) {
            cout<<result<<endl; 
        } else {
            throw Exception{"Звена с таким ключом не существует!\n"};
        }
        tree.printTree();
        tree.remove(7);
        if(tree.search(7,result)) {
            cout<<result<<endl; 
        } else { 
            throw Exception{"Звена с таким ключом не существует!\n"};
        }
    } catch(const Exception& ex) {
        cout<<ex.getMessage()<<endl;
    }
    tree.inorderTraversal();
    cout << endl;
    tree.printTree();

    // AVLTree<int, string> Database;
    // int id;
    // string data;
    // ifstream input("DataBase.txt");
    // try {
    //     if(!input.is_open()) throw Exception("DataBase.txt");
    // } catch (const Exception& ex) {
    //     cout<<"Не существует такого файла, как "<<ex.getMessage()<<endl;
    //     return -1;
    // }
    
    // while(!input.eof()) {
    //     input>>id>>data;
    //     Database.insert(id,data);
    // }

    // cout << "База данных: " << endl;
    // Database.printTree();
    // Database.remove(3);
    // Database.printTree();
    // Database.remove(0);
    // Database.printTree();
    // cout<<endl<<Database.tree_depth()<<endl;

    return 0;
}