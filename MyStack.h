#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <iomanip>

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <typename T>
class Stack
{
public:
  class Iterator
  {
  public:
    //Give access to list to access _ptr
    friend class Stack;

    //Default CTOR
    Iterator()
    { 
        _ptr = nullptr;
    }
    //Point Iterator to where p is pointing to
    Iterator(node<T>* p)
    { 
        _ptr = p;
    }

    //Casting operator: true if _ptr not NULL
    //This turned out to be a pain!
    operator bool() 
    { 
        if(_ptr == nullptr)
            return false;
        else
            return true;
    }
    
    //dereference operator
    T& operator *()
    { 
        return _ptr->_item;
    }               
    //member access operator
    T* operator ->()
    { 
        return &_ptr->_item;
    }
    //true if _ptr is NULL
    bool is_null()
    { 
        if(_ptr == nullptr)
            return true;
        else
            return false;
    }   

    //true if left != right
    friend bool operator !=(const Iterator &left, const Iterator &right)
    { 
        return (left._ptr != right._ptr);
    }
    //true if left == right
    friend bool operator ==(const Iterator &left, const Iterator &right)
    { 
        return (left._ptr == right._ptr);
    }

    //member operator:  ++it; or ++it = new_value
    Iterator& operator ++()
    { 
        _ptr = _ptr->_next;
        return *this;
    }
    //friend operator: it++
    friend Iterator operator ++(Iterator &it, int unused)
    { 
        node<T>* temp = it._ptr;
        it._ptr = it._ptr->_next;
        return Iterator(it);
    }
    
  private:
    node<T>* _ptr; //pointer being encapsulated
  };

  //constructor: CTOR
  Stack();

  //BIG 3:
  Stack(const Stack<T>& copyMe);
  ~Stack();
  Stack<T>& operator =(const Stack<T>& RHS);

  //Operations:
  void push(T item);
  void pop();

  //Accessors:
  Iterator begin() const;            //Iterator to the head node
  Iterator end() const;              //Iterator to NULL

  //Checkers:
  int size() const;
  bool empty();
  T top();

  template<typename U>
  friend ostream& operator <<(ostream& outs, const Stack<U>& printMe);

private:
  node<T>* _top;
  int _size;
};

//Definition
template <typename T>
Stack<T>::Stack()
{
    _size = 0;
    _top = nullptr;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& copyMe)
{
    _size = copyMe._size;
    _top = _copy_list(copyMe._top);
}

template <typename T>
Stack<T>::~Stack()
{
    _clear_list(_top);
    _top = nullptr;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& RHS)
{
    if(this == &RHS)
        return *this;
    _size = RHS._size;
    _top = _copy_list(RHS._top);
    return *this;
}

template <typename T>
void Stack<T>::push(T item)
{
    _top = _insert_head(_top, item);
    _size++;
}

template <typename T>
void Stack<T>::pop()
{
    _size--;
    _delete_node(_top, _top);
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin() const
{
    return Iterator(_top);
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::end() const
{
    return Iterator(nullptr);
}

template <typename T>
int Stack<T>::size() const
{
    return _size;
}

template <typename T>
bool Stack<T>::empty()
{
    return (_top == nullptr);
}

template <typename T>
T Stack<T>::top()
{
    return _top->_item;
}

template <typename U>
ostream& operator <<(ostream& outs, const Stack<U>& printMe)
{
    node<U>* temp = printMe._top;
    while(temp != nullptr)
    {
        outs << temp->_item;
        temp = temp->_next;
    }
    outs << endl;
    return outs;
}

//TODO

#endif // MYSTACK_H