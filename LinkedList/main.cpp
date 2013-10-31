#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> l;
    l.insert(2);
    l.insert(4);
    l.show();
    l.insert(6);
    l.insert(3);
    l.insert(3);
    l.show();
    l.remove(3);
    l.show();
    return 0;
}
