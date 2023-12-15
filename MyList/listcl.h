#include <iostream>
#include <cmath>
#include <chrono>
#include <list>
#include <string>

using namespace std;

template<typename T>
struct Node {
  T x;
  Node<T> *next;
  Node(T value) : x(value), next(nullptr) {}
};

template<typename T>
class Slist {
private:
  Node<T> *Head;
  friend class iterator;
public:
  Slist();
  Slist(const Slist& s);
  bool is_empty() const;
  void Add(const T& x);
  void remove_head();
  void remove(const T& x);
  void remove(const Node<T>* bye);
  void clear();
  void Show();
  int quantity() const;
  ~Slist();
  Node<T>* operator[] (const int i);
  bool operator==(const Slist<T>& obj);
  bool operator!=(const Slist<T>& obj);
  Slist<T>& operator=(const Slist& g);
  class iterator {
  private:
    friend class Slist<T>;
    Node<T> *cur;
  public:
    iterator () : cur (nullptr) {}
    iterator (Node<T> *ptr) : cur (ptr) {}
    bool operator==(const iterator& it) const {
      return cur==it.cur;
    }
    T operator*() const {
      if (cur != nullptr) {
        return cur->x;
      } else {
        cout<<"cur is empty!";
        return T();
      }
    }
    bool operator!=(const iterator& it) const {
      return !(cur==it.cur);
    }
    iterator& operator++(int) {
      cur = cur->next; 
      return *this;        
    }
  };
  void remlolove(iterator& pos);
  iterator begin() const;
  iterator end() const;
  Node<T>* golova() const {
    return Head;
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