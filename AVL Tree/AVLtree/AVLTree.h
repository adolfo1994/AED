#include "Node.h"
#include "Traits.h"
#include <iostream>
#include <queue>
using namespace std;
#ifndef AVLTREE_H
#define AVLTREE_H


template <class Tr>
class AVLTree{
    public:
    typedef typename Tr::data_type type;
    typedef typename Tr::cmp_type cmp;

        AVLTree(){
            root = NULL;
        }
        void mass_murder(Node<type>* ptr){
            if(ptr==NULL)return;
            mass_murder(ptr->leaves[0]);
            mass_murder(ptr->leaves[1]);
            delete ptr;
        }
        virtual ~AVLTree(){
           mass_murder(root);
        }
        bool insert(type n){
            return insert1(&root,n);
        }
        bool insert1(Node<type>** t, type n){
            if((*t)==NULL){
                *t=new Node<type>(n);
                return true;
            }
            if(n<(*t)->data){
                insert1(&(*t)->leaves[0],n);
            }else{
                insert1(&(*t)->leaves[1],n);
            }
            balance(t);
            update_height(*t);
        }
        bool remove(type n){
            return remove1(&root,n);
        }
        bool remove1(Node<type>** t ,type n){
            Node<type>* tmp;
            bool l = (*t)->leaves[0];
            bool r = (*t)->leaves[1];
            if (n < (*t)->data){
                remove1(&(*t)->leaves[0], n);
            }else if (n > (*t)->data){
                remove1 (&(*t)->leaves[1], n);
            }else {
                if ( !l&!r){
                    delete(*t);
                    (*t) = NULL;
                }else if (!l){
                    tmp = (*t);
                    (*t) = (*t)->leaves[!l];
                    delete tmp;
                }else{
                    (*t)->data = remove_min(&(*t)->leaves[1]);
                }
            }
            balance (t);
            update_height(*t);
            }
        int remove_min(Node<type>** t){
            if(*t!=NULL){
                if ((*t)->leaves[0]!=NULL){
                    int x = remove_min(&(*t)->leaves[0]);
                    balance(t);
                    update_height(*t);
                    return x;
                }else{
                    Node<type> *tmp = (*t);
                    int x = tmp->data;
                    *t = (*t)->leaves[1];
                    delete tmp;
                    balance(t);
                    update_height(*t);
                    return x;
                }
            }
        }
        void inorder_rec(Node<type>* t){
            if(t==0){
                return;
            }
            inorder_rec(t->leaves[0]);
            cout<<t->data<<" Nivel:"<<t->height<<endl;
            inorder_rec(t->leaves[1]);
        }
        void show (){
            inorder_rec(root);
        }
        void show_levels(){
            queue<Node<type>* > route;
            route.push(root);
            int currlevel = 1;
            int nextlevel = 0;
            while(!route.empty()){
                if(route.front()!=NULL){
                    route.push(route.front()->leaves[0]);
                    route.push(route.front()->leaves[1]);
                    cout<<route.front()->data<<"-";
                    nextlevel += 2;
                    currlevel--;
                }
                if (currlevel == 0){
                    cout<<endl;
                    currlevel = nextlevel;
                    nextlevel = 0;
                }
                route.pop();
            }
        }
        Node<type>* get_root(){
            return root;
        }
        int height(Node<type>* t){
            if(t==NULL) return -1;
            return t->height;
        }
        void update_height(Node<type>* t){
            if(t==NULL)return;
            t->height = max(height(t->leaves[0]),height(t->leaves[1]))+1;
        }
        void rotate(Node<type>** t, bool left){
            Node<type>* tmp= (*t)->leaves[!left];
            (*t)->leaves[!left] = tmp->leaves[left];
            tmp->leaves[left] = *t;
            update_height(*t);
            update_height(tmp);
            *t = tmp;
        }
        void double_rotate(Node<type>** t,bool left ){
            rotate(&((*t)->leaves[!left]), !left);
            rotate(t, left);
        }
        void balance (Node<type> ** t){
            if((*t)!=NULL){
                int diff = height ((*t)->leaves[0]) - height ((*t)->leaves[1]);
                if (diff == 2){
                    if (height((*t)->leaves[0]->leaves[0]) >= height ((*t)->leaves[0]->leaves[1])){
                        rotate (t, true);
                    }else
                        double_rotate(t, true);
                }else if (diff == -2){
                    if (height ((*t)->leaves[1]->leaves[1]) >= height((*t)->leaves[1]->leaves[0])){
                        rotate(t, false);
                    }else{
                        double_rotate(t, false);
                    }
                }
            }
        }


    protected:
    private:
        Node<type>* root;
        cmp comp;
};

#endif // BINARYTREE_H
