#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;

template < typename T >
struct stack {
    T id;
    stack *next;
  };

template < typename T >
void push(stack<T>* &ptr, T x)
{
    stack<T> *tmp = new(stack<T>);
    tmp->id=x;
    tmp->next=ptr;
    ptr = tmp;
}

template < typename T >
void print(stack<T>* ptr)
{
    while(ptr){
        cout<<ptr->id<<" ";
        ptr=ptr->next;
    }
}

template < typename T >
T pop(stack<T>* &ptr){
    stack<T> *tmp = ptr;
    ptr = ptr->next;
    T x = tmp->id;
    delete(tmp);
    return(x);
}
template < typename T >
T top(stack<T>*ptr){
    return ptr->id;
}
template < typename T >
int stack_is_empty(stack<T>*ptr){
    return !ptr;
}
template < typename T >
void stack_init(stack<T>*&ptr){
    ptr = NULL;
}
#endif // STACK_H_INCLUDED
