#include "AVLTree.h"
#include <assert.h>
#ifndef AVLTESTS_H
#define AVLTESTS_H


struct AVLTests
{
    AVLTree<TraitAsc<char> > myavl;
    AVLTests(){
        myavl.insert('F');
        myavl.insert('B');
        myavl.insert('H');
        myavl.insert('G');
        myavl.insert('I');
        myavl.insert('A');
        myavl.insert('D');
        myavl.insert('C');
        myavl.insert('E');
    }
    void test_insertion(){
        assert(myavl.insert('J'));
    }
    void test_deletion(){
        assert(myavl.remove('B'));
    }
    void test_delete_root(){
        assert(myavl.remove(myavl.get_root()->data));
    }
    void run(){
        this->test_insertion();
        this->test_deletion();
        this->test_delete_root();
        myavl.show_levels();
    }
};

#endif // AVLTESTS_H
