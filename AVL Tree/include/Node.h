#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    public:
        T data;
        Node<T>* leaves[2];
        Node(T x){
            data = x;
            leaves[0] = NULL;
            leaves[1] = NULL;
        }
        virtual ~Node(){

        }

};

#endif // NODE_H
