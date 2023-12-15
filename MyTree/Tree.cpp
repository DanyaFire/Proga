#include "Tree.h"

// Функция для получения максимального значения из двух чисел
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    
    template<class Key, class Value>
    int AVLTree<Key, Value>::depth(Node* node) const {
        if (node == nullptr) return -1;
        return node->depth;
    }

    template<class Key, class Value>
    int AVLTree<Key, Value>::getNodeDepth(Node* node, const Key& key) {
        if (node == nullptr) return -1; // Узел не найден, возвращаем -1

        if (key == node->key) return node->depth; // Найден узел, возвращаем его глубину

        if (key < node->key) return getNodeDepth(node->left, key); // Рекурсивно ищем в левом поддереве

        return getNodeDepth(node->right, key); // Рекурсивно ищем в правом поддереве
    }

    template<class Key, class Value>
    typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::newNode(const Key& key, const Value& value) {
        Node* node = new Node();
        node->key = key;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        node->depth = 0;
        return (node);
    }

    template<class Key, class Value> 
    typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->depth = max(depth(y->left), depth(y->right)) + 1;
        x->depth = max(depth(x->left), depth(x->right)) + 1;

        return x;
    }

    template<class Key, class Value>
    typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->depth = max(depth(x->left), depth(x->right)) + 1;
        y->depth = max(depth(y->left), depth(y->right)) + 1;

        return y;
    }

    template<class Key, class Value>
    int AVLTree<Key, Value>::getBalance(Node* N) {

        if (N == nullptr) return -1;

        return depth(N->left) - depth(N->right);
    }
    
    template<class Key, class Value>
    typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::insert(Node* node, const Key& key, const Value& value) {
        // 1. Выполнение обычной вставки узла BST
        if (node == nullptr) return (newNode(key, value));

        if (key < node->key) node->left = insert(node->left, key, value);

        else if (key > node->key) node->right = insert(node->right, key, value);
        
        else return node; // Узел с данным ключом уже существует в дереве

        // 2. Обновление высоты текущего узла
        node->depth = 1 + max(depth(node->left), depth(node->right));

        // 3. Получение коэффициента сбалансированности этого узла,
        // чтобы проверить, не нарушилось ли свойство AVL
        int balance = getBalance(node);

        // Если узел не сбалансирован, нужно проверить нарушение свойства AVL и выполнить соответствующие вращения
        // Для этого рассматриваем следующие 4 случая:

        // Левая часть левого поддерева
        if (balance > 1 && key < node->left->key) return rightRotate(node);

        // Правая часть правого поддерева
        if (balance < -1 && key > node->right->key) return leftRotate(node);

        // Левая часть правого поддерева
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Правая часть левого поддерева
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        // Возвращаем неизмененный указатель на узел
        return node;
    }
    
    template<class Key, class Value>
    typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::remove(Node* root, const Key& key) {
    if (root == nullptr) return root;

    if (key < root->key) root->left = remove(root->left, key);

    else if (key > root->key) root->right = remove(root->right, key);

    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);

            root->key = temp->key;
            root->value = temp->value;
            root->right = remove(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;

    root->depth = 1 + max(depth(root->left), depth(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
    }

    template<class Key, class Value>
    typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::minValueNode(Node* node) {
        Node* current = node;

        while (current->left != nullptr) current = current->left;
        
        return current;
    }
    
    template<class Key, class Value>
    void AVLTree<Key, Value>::inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }
    
    template<class Key, class Value>
    bool AVLTree<Key, Value>::search(const Key& key, Value& result) const {
        Node* current = root;

        while (current != nullptr) {

            if (key == current->key) {
                result = current->value;
                return true;
            } else if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }

        }
        return false;  
    }

    template<class Key, class Value>
    void AVLTree<Key, Value>::printTree(Node* root, std::string prefix, bool isLeft) {
        if (root != nullptr) {
            cout << prefix;
        cout << (isLeft ? "├──" : "└──");
        cout << "(" << root->key << "," << root->value << ")" << endl;

        printTree(root->left, prefix + (isLeft ? "│   " : "    "), true);
        printTree(root->right, prefix + (isLeft ? "│   " : "    "), false);
        }
    }

    template<class Key, class Value>
    void AVLTree<Key, Value>::destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    template class AVLTree<int,int>;
    template class AVLTree<double,double>;
    template class AVLTree<char,char>;
    
    template class AVLTree<int,double>;
    template class AVLTree<double,int>;
    template class AVLTree<char,double>;

    template class AVLTree<int, string>;
    template class AVLTree<int,char>;
    template class AVLTree<double,char>;
    template class AVLTree<char,int>;