#ifndef BINTREEITERATOR_H
#define BINTREEITERATOR_H
#include <stack>
#include "Node.h"
enum state{l=0, r=1, t=2, s=3};
using namespace std;
template<class T>
struct inorder{
    state operator ()(stack< pair<int,Node<T>*> >* it_stack){
        int t_val = it_stack->top().first;
        switch(t_val){
            case 0:
                return l;
            case 1:
                return s;
            case 2:
                return r;
            case 3:
                return t;
        }
    }
    void up(stack< pair<int,Node<T>*> >* it_stack){
        it_stack->pop();
        if(it_stack->empty()==true){
            return ;
        }
        if(it_stack->top().first==0){
            it_stack->top().first=1;
        }
        if(it_stack->top().first==2){
            it_stack->top().first=3;
        }
    }
};

template<class T>
struct preorder{
    state operator ()(stack< pair<int,Node<T>*> >* it_stack){
        int t_val = it_stack->top().first;
        switch(t_val){
            case 0:
                return s;
            case 1:
                return r;
            case 2:
                return l;
            case 3:
                return t;
        }
    }
    void up(stack< pair<int,Node<T>*> >* it_stack){
        it_stack->pop();
        if(it_stack->top().first==2){
            it_stack->top().first=1;
        }
        if(it_stack->top().first==1){
            it_stack->top().first=3;
        }
    }

};

template<class T>
struct posorder{
    state operator ()(stack< pair<int,Node<T>*> >* it_stack){
        int t_val = it_stack->top().first;
        switch(t_val){
            case 0:
                return l;
            case 1:
                return r;
            case 2:
                return t;
            case 3:
                return s;
        }
    }
};
template<class T,class O>
class BinTreeIterator
{
    typedef BinTreeIterator<T,O> self;
    typedef Node<T> p_Node;
    typedef pair<int,p_Node*> S_node;
    typedef stack<S_node> mystack;
    public:
        BinTreeIterator() {
        }
        BinTreeIterator(stack<pair<int,Node<T>*> > other ) {
            m_stack = other;
        }
        virtual ~BinTreeIterator() {

        }
        BinTreeIterator<T,O>& operator ++(int){
            state st = o(&m_stack);
            while (true){
                st = o(&m_stack);
                switch (st){
                    case l:
                        if(((m_stack.top()).second)->leaves[0]!=NULL){
                            S_node tmp(0,(m_stack.top()).second->leaves[0]);
                            m_stack.push(tmp);
                        }else{
                            m_stack.top().first = 1;
                        }
                        break;
                    case r:
                        if(m_stack.top().second->leaves[1]!=NULL){
                            S_node tmp(0,(m_stack.top()).second->leaves[1]);
                            m_stack.push(tmp);
                        }else{
                            m_stack.top().first = 3;
                        }
                        break;
                    case t:
                        o.up(&m_stack);
                        if(m_stack.empty()==true){
                            return *this;
                        }
                        break;
                    case s:
                        return *this;
                }
            }
        }
        BinTreeIterator<T,O>& operator = (self other ){
            m_stack = other.m_stack;
            return *this;
        }
        bool operator != (self other){
            return m_stack != other.m_stack;
        }
        T& operator *(){
            m_stack.top().first=2;
            return ((m_stack.top()).second)->data;
        }

        mystack m_stack;

    protected:
    private:
        O o;


};

#endif // BINTREEITERATOR_H
