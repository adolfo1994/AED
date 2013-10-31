#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    public:
        T data;
        int height;
        Node<T>* leaves[2];
        Node(T x){
            data = x;
            leaves[0] = NULL;
            leaves[1] = NULL;
            height = 0;
        }

        virtual ~Node(){
        }


};

#endif // NODE_H
