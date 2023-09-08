#ifndef NODE_H 
#define NODE_H 

#include <iostream> 
#include <iomanip>

using namespace std;
 
template <typename T>
struct node
{
public:
    node(const T& item = T(), node* next = nullptr);

    template <typename U>
    friend ostream& operator <<(ostream& outs, const node<U> &printMe);

    T _item;
    node* _next;
};

// Definition 

template <typename T>
node<T>::node(const T& item, node* next):_item(item), _next(next)
{
}

template <typename U>
ostream& operator <<(ostream& outs, const node<U> &printMe)
{
    outs << "[" << printMe._item << "]";
    return outs;
}

// TODO 

#endif // NODE_H 