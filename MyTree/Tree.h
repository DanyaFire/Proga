#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

template<class Key, class Value>
class AVLTree {
private:
    friend class iterator;
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;
        int depth;
        Node() : key(0), value(Value()), left(nullptr), right(nullptr), depth(0) {}
        
        Node(const Key& k, const Value& v, Node* l, Node* r, int& d) : key(k), value(v), left(l), right(r), depth(d) {}
        
        Node& operator=(const Node& other) {
            if (this == &other)
            return *this;

            key = other.key;
            value = other.value;
            left = other.left;
            right = other.right;
            depth = other.depth;

            return *this;
        }
    };
 
    Node* root;
    friend class iterator;

    // Функция для получения высоты узла дерева
    int depth(Node* node) const;

    int getNodeDepth(Node* node, const Key& key);

    // Функция для создания нового узла
    Node* newNode(const Key& key, const Value& value);

    // Функция для правого вращения поддерева с корнем y
    Node* rightRotate(Node* y);

    // Функция для левого вращения поддерева с корнем x
    Node* leftRotate(Node* x);

    // Функция для получения баланса узла N
    int getBalance(Node* N);

    // Функция для вставки по ключу в AVL-дерево
    Node* insert(Node* node, const Key& key, const Value& value);

    // Функция для удаления по ключу из AVL-дерева
    Node* remove(Node* root, const Key& key);

    // Функция поиска минимального элемента в AVL-дереве
    Node* minValueNode(Node* node);

    // Функция для обхода в порядке "inorder"
    void inorder(Node* root);

    // Функция для вывода дерева на экран
    void printTree(Node* root, string prefix = "", bool isLeft = true);

    // Удаление некоторой части дерева
    void destroyTree(Node* node);
public:
    AVLTree() {
        root = nullptr;
    }

    // Функция для вставки ключа в AVL-дерево
    void insert(const Key& key, const Value& value) {
        root = insert(root, key, value);
    }
    
    // Функция поиска по ключу в AVL-дереве
    bool search(const Key& key, Value& result) const;

    // Функция для удаления ключа в AVL-дерево
    void remove(const Key& key) {
        root = remove(root, key);
    }

    // Функция для вывода данных обходом в порядке "inorder"
    void inorderTraversal() {
        cout << "Узлы AVL-дерева в порядке обхода \"inorder\": ";
        inorder(root);
        cout << endl;
    }

    // Вывод дерева на экран
    void printTree() {
        cout << "Дерево AVL:" << endl;
        printTree(root,"",true);
    }

    //Глубина конкретного звена
    int depth(const Key& key) {
        return getNodeDepth(root, key);
    }

    //Глубина всего дерева
    int tree_depth() const {
        return depth(root);
    }

    struct stack_node {        
        Node* ptr;
        stack_node* prev;
        stack_node(Node* ptr): ptr(ptr), prev(nullptr) {}
    };    
    
    struct stack {
        stack_node* top;        
        stack(): top(nullptr) {}
        
        bool empty() const { 
            return top == nullptr; 
        }        
        
        void push(Node* ptr) {
            if (top == nullptr) {                
                top = new stack_node(ptr);
                return;            
            }
            stack_node* new_top = new stack_node(ptr);            
            new_top->prev = top;
            top = new_top;        
        }
        // -- peak
        Node* peek() const {            
            return top->ptr;
        }        
        
        Node* pop() {
            Node* ptr = top->ptr;
            stack_node* tmp = top;
            top = top->prev;
            delete tmp;
            return ptr;        
        }
        
        ~stack() {            
            while (top != nullptr) {
                stack_node* tmp = top;                
                top = top->prev;
                delete tmp;            
            }
        }        
        
        void print() {
            stack_node* tmp = top;            
            cout << "[ ";
            while (tmp != nullptr) {                
                if (tmp->ptr != nullptr) {
                    cout << tmp->ptr->key << " ";
                }
                tmp = tmp->prev;            
            }
            cout << "]\n";        
        }
    };

    class iterator {    
    private:
        friend class AVLTree;
        stack st;    
    public:
        iterator(Node* root) {            
            if (root == nullptr) return;
            st.push(root);            
            while (st.peek()->left) st.push(st.peek()->left);
        }        
        
        Key operator*() const {
            cout<<" "<<st.peek()->value<<",";
            return st.peek()->key;
        }

        iterator& operator++() {           
            if (st.peek()->right) {
                st.push(st.peek()->right);                
                
                while (st.peek()->left) st.push(st.peek()->left); 

                return *this;
            }
            Node* tmp = st.pop();
            
            if(st.empty()) return *this;
            
            while (st.peek()->right == tmp) {
                tmp = st.pop();
                
                if (st.empty()) return *this;
            }

            return *this;        
        }
        
        bool operator==(const iterator& other) const {            
            if (other.st.empty() && st.empty()) return true;
            
            if (other.st.empty() || st.empty()) return false;

            return st.peek() == other.st.peek();
        }        
        bool operator!=(const iterator& other) const {
            return !(other == *this);        
        }
    };

    iterator begin() const {
        return iterator(root);
    }
    
    iterator end() const {
        iterator iter(nullptr); // Создаем итератор с указателем nullptr в качестве корня
        return iter;
    } 

    ~AVLTree() {
        destroyTree(root);
    }
};

class Exception {
private:
  string msg;
public: 
  Exception(const string& message): msg{message} {}
  
  const char* getMessage() const {
    return msg.c_str();
  }
};

// template<class Key, class Value>
// ostream& operator<<(ostream& os, const pair<Key, Value>& pair) {
//     os << "(" << pair.first << ", " << pair.second << ")";
//     return os;
// }