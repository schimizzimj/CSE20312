/*  LinkedList.cpp 
 *  Creates a linked list to be used to store large numbers and add them together
 *
 * Marcus Schimizzi
 * 2/6/17
 */

#include <iostream>
#include<string>
using namespace std;

template<typename T>
struct Node{
  T val;
  Node* next;
  Node(T);
};

template<typename T>
Node<T>::Node(T value)
{
  val = value; next = nullptr;
}

template<typename T>
struct List{
  Node<T>* head;
  List();
  ~List();
  Node<T>* getHead();
  void pushFront(T newNumber);
  void print(Node<T> *head);
  List<T> addNumberLists(List<T> &l1, List<T> &l2);
};

template<typename T>
List<T>::List()
{ head = nullptr; }

template<typename T>
List<T>::~List()
{
  Node<T>* current;
  while (head != nullptr) {
    current = head;
    head = current->next;
    delete current;
  }
}

template<typename T>
Node<T>* List<T>::getHead()
{ return head; }

template<typename T>
void List<T>::pushFront(T newNumber) {
  Node<T> *node = new Node<T>(newNumber);
  node->next = head;
  head = node;
}

template<typename T>
void List<T>::print(Node<T> *head)
{
  if (head == nullptr) return;

  print(head->next);

  cout << head->val;

  return;

}

template<typename T>
List<T> List<T>::addNumberLists(List<T> &l1, List<T> &l2)
{
  List<T> sum;
  Node<T> *ptr1; Node<T> *ptr2;
  ptr1 = l1.head; ptr2 = l2.head;
  int carry = 0, x;
  string sum_val;
  while ((ptr1 != nullptr) || (ptr2 != nullptr) || (carry != 0) ) {
    if ( (ptr1 == nullptr) && (ptr2 == nullptr) && (carry == 1)) {
      x = carry;
    }else if ((ptr1 ==  nullptr) || (ptr2 == nullptr)) {
      if (ptr1 == nullptr) x = ptr2->val;
      else x = ptr1->val;
      x += carry;
    }else {
      x = ptr1->val + ptr2->val + carry;
    }
    carry = 0;
    if (x > 9){
      carry = 1;
      x = x % 10;
    }
    sum_val.push_back(x + '0');
    if (ptr1 != nullptr) ptr1 = ptr1->next; 
    if (ptr2 != nullptr) ptr2 = ptr2->next;
  }
  for (int i = sum_val.size() - 1; i >= 0;  i--) sum.pushFront((int)sum_val[i] - 48);
  return sum;
}

int main() {
  string numString1, numString2;
  while(cin >> numString1 >> numString2){
    List<int> mylist1, mylist2;
    for (int i = 0; (unsigned)i < numString1.size(); i++) {
     mylist1.pushFront((int)numString1[i] - 48); 
    }
    for (int  j = 0; (unsigned)j < numString2.size(); j++) {
      mylist2.pushFront((int)numString2[j] - 48);
    }
    List<int> sumList = sumList.addNumberLists(mylist1, mylist2);
    sumList.print(sumList.head);
    cout << endl;
  } 
}
