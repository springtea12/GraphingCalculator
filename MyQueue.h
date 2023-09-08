#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <iomanip>

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <typename T>
class Queue
{
public:
  class Iterator
  {
  public:
    //Give access to list to access _ptr
    friend class Queue;

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
        return (_ptr != nullptr);
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
        return (_ptr == nullptr);
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
        return Iterator(temp);
    }

  private:
    node<T>* _ptr; //pointer being encapsulated
  };

  //constructor: CTOR
  Queue();

  //BIG 3:
  Queue(const Queue<T>& copyMe);
  ~Queue();
  Queue<T>& operator =(const Queue<T>& RHS);

  //Operations:
  void push(T item);                  //Enqueue
  void pop();                         //Dequeue

  //Accessors:
  Iterator begin() const;             //Iterator to the head node
  Iterator end() const;               //Iterator to NULL

  //Checkers:
  int size() const;
  bool empty();
  T front();
  T back();

  template<typename U>
  friend ostream& operator <<(ostream& outs, const Queue<U>& printMe);
  
private:
  node<T>* _front;
  node<T>* _rear;
  int _size;
};


//Definition

template <typename T>
Queue<T>::Queue()
{
    _front = nullptr;
    _rear = _front;
    _size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& copyMe)
{
    _size == copyMe._size;
    _front = _copy_list(copyMe._front);
    if(_size == 0)
        _rear = nullptr;
    else
        _rear = _front + _size - 1;
}

template <typename T>
Queue<T>::~Queue()
{
    _clear_list(_front);
    _front = nullptr;
    _rear = nullptr;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& RHS)
{
    if(this == &RHS)
        return *this;
    _size = RHS._size;
    _front = _copy_list(RHS._front);
    if(_size == 0)
        _rear = nullptr;
    else
        _rear = _front + _size -1;
    return *this;
}

template <typename T>
void Queue<T>::push(T item)
{
    _size++;
    if(_size == 1)
    {
        _front = _insert_head(_front, item);
        _rear = _front;
    }
    else
    {
        _rear = _insert_after(_front, _rear, item);
    }
}

template <typename T>
void Queue<T>::pop()
{
    _size--;
    _delete_node(_front, _front);
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin() const
{
    return Iterator(_front);
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::end() const
{
    return Iterator(nullptr);
}

template <typename T>
int Queue<T>::size() const
{
    return _size;
}

template <typename T>
bool Queue<T>::empty()
{
    return (_front == nullptr);
}

template <typename T>
T Queue<T>::front()
{
    return _front->_item;
}

template <typename T>
T Queue<T>::back()
{
    return _rear->_item;
}

template <typename U>
ostream& operator <<(ostream& outs, const Queue<U>& printMe)
{
    node<U>* temp = printMe._front;
    while(temp != nullptr)
    {
        outs << temp->_item;
        temp = temp->_next;
    }
    outs << endl;
    return outs;
}

//TODO

#endif //MYQUEUE_H