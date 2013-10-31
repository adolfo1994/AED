#include <iostream>
#include "include/BinaryTree.h"
#include "include/BinTreeTests.h"

using namespace std;
int main()
{
    //BinTreeTests test;
    //test.run();
    BinaryTree<TraitAsc<char> > t;
    t.insert('F');
    t.insert('B');
    t.insert('G');
    t.insert('I');
    t.insert('H');
    t.insert('A');
    t.insert('D');
    t.insert('C');
    t.insert('E');
    BinaryTree<TraitAsc<char> >::it_preorder it;
    BinaryTree<TraitAsc<char> >::it_inorder it2;
    for(it=t.preorderbegin();it!=t.preend();it++){
        cout<<*it<<endl;
    }
    /*for(it2=t.inorderbegin();it2!=t.inend();it2++){
        cout<<*it2<<endl;
    }*/

    return 0;
}

