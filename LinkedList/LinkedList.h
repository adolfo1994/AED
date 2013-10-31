#include <iostream>
#include "Node.h"

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template <class T>
struct Ascendant{
    inline bool operator ()(T a, T b){
        return (a<b);
    }
};
struct Descendant{
    inline bool operator ()(T a, T b){
        return (a>b);
    }
};


template <class T, class C>
class LinkedList
{
    public:
        Node<T>* m_head;
        C m_c;
        LinkedList(){
            m_head = NULL;
        }
        virtual ~LinkedList(){
            Node<T>* t;
            while(m_head){
                t=m_head->m_next;
                delete m_head;
                m_head = t;
            }
        }
        bool find (T x, Node<T>**& p){
            for( p = &m_head ; *p && (*p)->m_data<x ; p = &(*p)->m_next);
            return *p && (*p)->m_data == x;
        }
        bool insert(T x){
            Node<T>** p;
            if(find(x,p)){
                cout<<x<<" is already on the list"<<endl;
                return 0;
            }else{
                Node<T>* nnode = new Node<T>(x);
                Node<T>* temp = *p;
                *p = nnode;
                nnode->m_next = temp;
                return 1;
            }
        }
        bool remove(T x){
            Node<T>** p;
            if(!find(x,p)){
                cout<<x<<" is not on the list"<<endl;
                return 0;
            }else{
                Node<T>* tmp = *p;
                *p = ((*p)->m_next);
                delete tmp;
                return 1;
        }
        }
        void show(){
            Node<T>* it = m_head;
            while(it){
                cout<<"("<<(it->m_data)<<")";
                it=it->m_next;
            }
            cout<<endl;
        }
    protected:
    private:
};

#endif // LINKEDLIST_H
