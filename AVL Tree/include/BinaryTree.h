#include "Traits.h"
#include <iostream>
using namespace std;
#ifndef BINARYTREE_H
#define BINARYTREE_H


template <class Tr>
class BinaryTree{
    public:
    typedef typename Tr::data_type type;
    typedef typename Tr::cmp_type cmp;
    typedef BinTreeIterator<type,inorder<type> > it_inorder;
    typedef BinTreeIterator<type,preorder<type> > it_preorder;
    typedef BinTreeIterator<type,posorder<type> > it_posorder;
    //typedef BinTreeIterator<type,revorder<type> > it_rev;
        BinaryTree(){
            root = NULL;
        }
        void mass_murder(Node<type>* ptr){
            if(ptr==NULL)return;
            mass_murder(ptr->leaves[0]);
            mass_murder(ptr->leaves[1]);
            delete ptr;
        }
        virtual ~BinaryTree(){
           mass_murder(root);
        }
        Node<type>** repl(Node<type>** p){
            Node<type>** q;
            q=&((*p)->leaves[1]);
            while((*q)->leaves[0]!=NULL){
                q=&((*p)->leaves[0]);
            }
            return q;
        }
        bool find (type n, Node<type>** &p){
            p=&root;
            while(*p){
                if((*p)->data == n){
                    return true;
                }
                else{
                    p=&((*p)->leaves[comp((*p)->data,n)]);
                }
            }
            return false;
        }
        bool insert(type n){
            Node<type>** p;
            if(find(n,p))return 0;
            *p = new Node<type>(n);
            return true;

        }
        bool remove(type n){
            Node<type>** p;
            Node<type>** q;
            if(!find(n,p))return 0;
            bool l= (*p)->leaves[0];
            bool r= (*p)->leaves[1];
            if( l&r ){
                q=repl(p);
                (*p)->data = (*q)->data;
                p=q;
                l= (*p)->leaves[0];
                r= (*p)->leaves[1];
            }
            if(!l&!r){
                delete *p;
                *p = NULL;
                return 1;
            }
            Node<type>* t=*p;
            *p=(*p)->leaves[r];
            delete t;
            return 1;
        }
        void inorder_rec(Node<type>* t){
            if(t==0){
                return;
            }
            inorder_rec(t->leaves[0]);
            cout<<t->data<<endl;
            inorder_rec(t->leaves[1]);
        }
        void show (){
            inorder_rec(root);
        }
        Node<type>* get_root(){
            return root;
        }
        BinTreeIterator<type,inorder<type> > inorderbegin(){
            BinTreeIterator<type,inorder<type> > begin;
            Node<type>* tmp = root;
            while(tmp!=NULL){
                pair<int,Node<type>* > s_node;
                s_node.first=0;
                s_node.second=tmp;
                begin.m_stack.push(s_node);
                tmp = tmp->leaves[0];
            }
            return begin;

        }
        BinTreeIterator<type,preorder<type> > preorderbegin(){
            BinTreeIterator<type,preorder<type> > begin;
            Node<type>* tmp = root;
            pair<int,Node<type>* > s_node;
            s_node.first=0;
            s_node.second=tmp;
            begin.m_stack.push(s_node);
            return begin;
        }
        BinTreeIterator<type,inorder<type> > inend(){
            stack<pair<int,Node<type>*> > empty_stack;
            BinTreeIterator<type,inorder<type> > itend(empty_stack);
            return itend;
        }
        BinTreeIterator<type,preorder<type> > preend(){
            BinTreeIterator<type,preorder<type> > itend;
            return itend;
        }
    protected:
    private:
        Node<type>* root;
        cmp comp;
};

#endif // BINARYTREE_H
