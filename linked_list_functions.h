#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include <cassert>
#include "../node/node.h"

using namespace std;

// Declaration
//Linked List General Functions:
template <typename T>
void _print_list(node<T>* head);

//recursive fun! :)
template <typename T>
void _print_list_backwards(node<T>* head);

//return ptr to key or NULL
template <typename T>
node<T>* _search_list(node<T>* head, T key);

template <typename T>
node<T>* _insert_head(node<T>* &head, T insert_this);

//insert after ptr
template <typename T>
node<T>* _insert_after(node<T>* &head, node<T>* after_this, T insert_this);

//insert before ptr
template <typename T>
node<T>* _insert_before(node<T>* &head, node<T>* before_this, T insert_this);

//ptr to previous node
template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prev_to_this);

//delete, return item
template <typename T>
T _delete_node(node<T>* &head, node<T>* delete_this);

//duplicate the list 
template <typename T>
node<T>* _copy_list(node<T>* head);

//duplicate list and return the last node of the copy || CLEAR DESTINATION FIRST BEFORE PUTTING VALUES IN
template <typename T>
node<T>* _copy_list(node<T>* &dest, node<T>* src);

//delete all the nodes
template <typename T>
void _clear_list(node<T>* &head);

//_item at this position
template <typename T>
T& _at(node<T>* head, int pos);

//Last node in the list, never use this function.
template <typename T>
node<T>* _last_node(node<T>* head);

// Definition

template <typename T>
void _print_list(node<T>* head)
{
    node<T>* temp = head;
    while(temp != nullptr)
    {
        cout << "[" << temp->_item << "]->";
        temp = temp->_next;
    }
    cout << "|||" << endl;
}


template <typename T>
void _print_list_backwards(node<T>* head)
{
    node<T>* temp = head;
    if(temp != nullptr)
    {
        _print_list_backwards(temp->_next);
    }
    cout << "[" << temp->_item << "]->";
}

template <typename T>
node<T>* _search_list(node<T>* head, T key)
{
    node<T>* temp = head;
    while(temp != nullptr)
    {
        if(temp->_item == key)
            return temp; 
        temp = temp->_next;
    }
    return nullptr;
}

template <typename T>
node<T>* _insert_head(node<T>* &head, T insert_this)
{
    node<T>* temp = new node<T>();
    temp->_item = insert_this;
    temp->_next = head;
    head = temp;
    return head;
}

template <typename T>
node<T>* _insert_after(node<T>* &head, node<T>* after_this, T insert_this)
{
    if(head == nullptr)
    {
        node<T>* temp = new node<T>(insert_this);
        temp->_next = head;
        head = temp;
        after_this = temp;
        return temp;
    }
    if(after_this == nullptr)
    {
        node<T>* temp = new node<T>();
        temp->_item = insert_this;
        temp->_next = nullptr;
        node<T>* a = head;
        while(a->_next != nullptr)
            a = a->_next;
        a->_next = temp;
    }
    assert(_search_list(after_this, after_this->_item) != nullptr);
    node<T>* temp = new node<T>();
    temp->_item = insert_this;
    temp->_next = after_this->_next;
    after_this->_next = temp;
    return temp;
}

template <typename T>
node<T>* _insert_before(node<T>* &head, node<T>* before_this, T insert_this)
{
    node<T>* temp = head;
    node<T>* a = new node<T>(insert_this);
    if(before_this == head)
    {
        a->_next = before_this;
        head = a;
    }
    else
    {
        while(temp != nullptr)
        {
            if(temp->_next == before_this)
            {
                a->_next = before_this;
                temp->_next = a;
                return a;
            }
            temp = temp->_next;
        }
    }
    return a;
}

template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prev_to_this)
{
    node<T>* temp = head;
    if(prev_to_this == head)
        return nullptr;
    else
    {
        while(temp != nullptr)
        {
            if(temp->_next == prev_to_this)
                return temp;
            else
                temp = temp->_next;
        }
    }
    return nullptr;
}

template <typename T>
T _delete_node(node<T>* &head, node<T>* delete_this)
{
    node<T>* temp = head;
    if(temp == delete_this)
    {
        head = temp->_next;
        T value = temp->_item;
        delete delete_this;
        return value;
    }
    else
    {
        while(temp->_next != delete_this)
            temp = temp->_next;
        temp->_next = delete_this->_next;
        T value = delete_this->_item;
        delete delete_this;
        return value;
    }
}

template <typename T>
node<T>* _copy_list(node<T>* head)
{
    node<T>* temp = nullptr;
    temp = _copy_list(temp, head);
    return temp;
}

template <typename T>
node<T>* _copy_list(node<T>* &dest, node<T>* src)
{
    if(dest != nullptr)
        dest = nullptr;
    if(src == nullptr)
    {
        dest = nullptr;
        return dest;
    }
    dest = _insert_head(dest, src->_item);
    node<T>* a = src->_next;
    node<T>* temp = dest;
    while(a != nullptr)
    {
        temp = _insert_after(dest, temp, a->_item);
        a = a->_next;
    }
    return dest;
}

template <typename T>
void _clear_list(node<T>* &head)
{
    node<T>* temp = head;
    while(temp != nullptr)
    {
        node<T>* a = temp->_next;
        _delete_node(head, temp);
        temp = a;
    }
}

template <typename T>
T& _at(node<T>* head, int pos)
{
    node<T>* temp = head;
    int count = 0;
    while(count != pos)
    {
        count++;
        temp = temp->_next;
    }
    return temp->_item;
}

template <typename T>
node<T>* _last_node(node<T>* head)
{
    node<T>* temp = head;
    while(temp->_next != nullptr)
        temp = temp->_next;
    return temp;
}

// TODO

#endif // LINKED_LIST_FUNCTIONS_H