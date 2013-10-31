#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    public:
        T m_data;
        Node<T>* m_next;
        Node(T x){
            m_data = x;
            m_next = NULL;
        }
        virtual ~Node(){

        }
    protected:
    private:
};

#endif // NODE_H
