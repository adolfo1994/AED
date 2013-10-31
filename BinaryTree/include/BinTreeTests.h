#ifndef BINTREETESTS_H
#define BINTREETESTS_H
#include <assert.h>
#include "BinaryTree.h"

class BinTreeTests
{
    public:
        void test_default(){
            BinaryTree<TraitAsc<int> > t;
            assert(t.get_root()==NULL);
        }
        void test_insert(){
            BinaryTree<TraitAsc<int> > t;
            t.insert(10);
            assert(t.get_root()->data==10);

        }
        void test_remove1(){
            BinaryTree<TraitAsc<int> > t;
            t.insert(10);
            t.remove(10);
            assert(t.get_root()==NULL);
        }
        void test_remove2(){
            BinaryTree<TraitAsc<int> > t;
            t.insert(15);
            t.insert(10);
            t.insert(5);
            t.remove(10);
            assert(t.get_root()->leaves[0]->data==5);

        }
        void test_remove3(){
            BinaryTree<TraitAsc<int> > t;
            t.insert(10);
            t.insert(5);
            t.insert(2);
            t.insert(8);
            t.remove(5);
        }
        void run(){
        this->test_default();
        this->test_insert();
        this->test_remove1();
        this->test_remove2();
        this->test_remove3();
        }
};

#endif // BINTREETESTS_H
