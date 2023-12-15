#include "listcl.h"

template<typename T>
struct Node;
template<typename T>
class Slist;

template <typename T>
Slist<T>::Slist() {
    Head = nullptr;
}

template <typename T>
Slist<T>::Slist(const Slist& s) {
    Head = nullptr;
    Add(s.Head->x);
    for (Node<T>* cur = s.Head->next; cur != s.Head; cur = cur->next) {
        Add(cur->x);
    }
}

template <typename T>
Slist<T>::~Slist() {
  if (!is_empty()) {
    Node<T>* current = Head;
    Node<T>* next;
    do {
      next = current->next;
      delete current;
      current = next;
    } while (current != Head);
    Head = nullptr;
  }
}

template<typename T>
bool Slist<T>::is_empty() const {
  return (Head == NULL);
}

template <class T>
bool Slist<T>::operator==(const Slist<T>& obj) {
  if (quantity() != obj.quantity()) return false;
  if (Head->x != obj.Head->x) return false;
  Node<T>* t1 = Head->next;
  Node<T>* t2 = obj.Head->next;
  while (t1 != Head) {
    if (t1->x != t2->x) return false;
    t1 = t1->next;
    t2 = t2->next;
  }
  return true;
}

template <class T>
bool Slist<T>::operator!=(const Slist<T>& obj) {
  return !(*this == obj);
}

template<class T> void Slist<T>::Add(const T& x) {
  Node<T>* temp = new Node<T>(x);
  if (Head == NULL) {
    temp->next = temp;
    Head = temp;
  } else {
    Node<T>* last = Head;
    while (last->next != Head) last = last->next;
    last->next = temp;
    temp->next = Head;
  }
}

template<typename T>
void Slist<T>::remove_head() {
  if(is_empty()) return;
  Node<T>* cur = Head;
  Node<T>* last = Head;
  while(last->next != Head) last = last->next;
  last->next = cur->next;
  Head = cur->next;
  delete cur;
}

template<typename T> void Slist<T>::remove(const T& x) {
  if(is_empty()) return;
  if(Head->x == x) {
    remove_head();
    return;
  } else {
    Node<T>* slow = Head;
    Node<T>* fast = Head->next;
    while((fast != Head) && (fast->x != x)) {
      fast = fast->next;
      slow = slow->next;
    }
    if(fast == NULL) {
      cout<<"Такого элемента не существует!"<<endl;
      return;
    }
    slow->next = fast->next;
    delete fast;
  }
}

template<typename T> void Slist<T>::remove(const Node<T>* bye) {
  if(is_empty()) return;
  if(bye == Head) {
    remove_head();
    return;
  }
  Node<T>* temp = Head;
  while(temp->next != bye) temp = temp->next;
    temp->next = bye->next;
    delete bye;
}

template <typename T>
void Slist<T>::remlolove(iterator& pos) {
  if(pos == begin()) {
    remove_head();
  } else {
    iterator temp = begin();
    while(temp.cur->next != pos.cur) temp.cur = temp.cur->next;
    temp.cur->next = pos.cur->next;
    delete pos.cur;
  }
}

template<typename T>
void Slist<T>::Show() {
  cout<<Head->x;
  Node<T>* current = Head->next;
  while (current != Head) {
    cout<<" -> "<<current->x;
    current = current->next;
  }
  cout<<endl;
}

template<typename T>
Node<T>* Slist<T>::operator[] (const int i) {
  if(is_empty()) return NULL;
  Node<T>* p = Head;
  for(int j = 0; j < i; j++) {
    p = p->next;
    if(p == NULL) return NULL;
  }
  return p;
}

template <typename T>
void Slist<T>::clear() {
  Node<T> *current = Head;
  while (current != NULL) {
    Node<T> *next = current->next;
    delete current;
    current = next;
  }
  Head = NULL;
}

template<typename T>
Slist<T>& Slist<T>::operator=(const Slist& g) {
  if (this != &g) {
    while(Head != nullptr) {
      Node<T>* temp = Head;
      Head = Head->next;
      delete temp;
    }
    for (Node<T>* current = g.Head; current != nullptr; current = current->next) {
      Add(current->x);
    }
  }
  return *this;
}

template<typename T>
int Slist<T>::quantity() const {
  if(is_empty()) return 0;
  Node<T>* tmp = Head;
  int size = 1;
  if(tmp->next == tmp) return size;
  do {
    tmp = tmp->next;
    size++;
  } while(tmp->next != Head); 
  return size;
}

template <typename T>
typename Slist<T>::iterator Slist<T>::begin() const {
  return iterator(Head);
}

template <typename T>
typename Slist<T>::iterator Slist<T>::end() const {
  Node<T>* last = Head;
  while(last->next != Head) last = last->next;
  return iterator(last);
}


template class Slist<int>;
template class Slist<int*>;
template class Slist<double>;
template class Slist<char>;

// template<typename T>
// Node<T>* Slist<T>::find_x(const T& x) {
//   if(is_empty()) return nullptr;
//   Node<T>* temp = Head;
//   while((temp != Head) && (temp->x != x)) {
//     if((temp != nullptr) && temp->x == x) return temp;
//     temp = temp->next;
//   }
//   cout<<"Такого элемента нет в списке! => ";
//   return NULL;
// }

// std::ostream & operator<<( std::ostream &O, Slist<int> &L) {
//   if (L.lst.golova() != nullptr) {
//     Node<int>* tmp = L.lst.golova();
//     O << '<';
//     while (tmp->next != L.lst.golova()) {
//       O << tmp->x << ", ";
//       tmp = tmp->next;
//     }
//     O << tmp->x << '>';
//   } else O << "<none>";
//   return O;
// }