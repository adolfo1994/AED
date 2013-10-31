#include <vector>

using namespace std;

//!Class that cointains a graph's edge 
/*!
This knaknlanca
asvjnaksvj sljanvasa
vasvk asv
*/
template <class G>
class Edge
{
    public:
        typedef typename G::e_type E;
        typedef typename G::node node;
        Edge(node* a, node* b, E weight, bool d){
            data = weight;
            nodes[0] = a;
            nodes[1] = b;
            dir = d;
        }
        virtual ~Edge(){
        }
    template <class X,class Y> friend class Graph;
    template <class W> friend class Dijkstra;
    protected:
    private:
        E data;
        node* nodes[2];
        bool dir;  //0 <->
                   //1 nodes[0]-->nodes[1]
};

template <class G>
class Node
{
    public:
        typedef typename G::n_type N;
        typedef typename G::edge edge;
        Node(N d){
            data = d;
        }
        virtual ~Node(){}
        N get_data(){
            return this->data;
        }
        bool find_edge(edge* e, typename vector<edge*>::iterator & i){
            for(i = edges.begin(); i!= edges.end; ++i) {
                if((*i)==e){
                    return true;
                }
            }
            return false;
        }
        template <class X,class Y> friend class Graph;
        template <class W> friend class Dijkstra;
    protected:
    private:
        N data;
        vector<edge*> edges;

};

template <class N,class E>
class Graph
{
    public:
        typedef Graph<N,E> self;
        typedef N n_type;
        typedef E e_type;
        typedef Node<self> node;
        typedef Edge<self> edge;
        typedef vector< node* > NodeCtnr;
        typedef vector< edge* > EdgeCtnr;

        Graph(){

        }
        virtual ~Graph(){

        }
        bool find_node(N n, typename NodeCtnr::iterator &i){
            for ( i = nodes.begin(); i != nodes.end(); ++i)
            {
                if ( (*i)->get_data() == n)
                {
                    return true;
                }
            }
            return false;
        }
        bool find_node(N n){
            typename NodeCtnr::iterator i;
            for ( i = nodes.begin(); i != nodes.end(); ++i)
            {
                if ( (*i)->get_data() == n)
                {
                    return true;
                }
            }
            return false;
        }
        node* find(N n){
            typename NodeCtnr::iterator i;
            for ( i = nodes.begin(); i != nodes.end(); ++i)
            {
                if ( (*i)->get_data() == n)
                {
                    return *i;
                }
            }
        }
        bool insert_node(N data){
            typename NodeCtnr::iterator i;
            if (!find_node(data,i))
            {
                node* tmp = new node(data);
                nodes.push_back(tmp);
            }
        }
        bool remove_node(N data){
            typename NodeCtnr::iterator i;
            if (find_node(data,i))
            {
                nodes.erase(i);
            }
        }
        bool insert_edge(node* a, node*b , E e, bool d){
            edge* tmp = new edge(a,b,e,d);
            a->edges.push_back(tmp);
            b->edges.push_back(tmp);
            edges.push_back(tmp);

        }
        bool find_edge(edge* e, typename vector<edge*>::iterator & i){
            for(i = edges.begin(); i!= edges.end; ++i) {
                if((*i)==e){
                    return true;
                }
            }
            return false;
        }

        bool remove_edge(edge* e){
            typename vector<edge*>::iterator i;
            e.nodes[0].find_edge(e,i);
            e.nodes[0].edges.erase(i);
            e.nodes[1].find_edge(e,i);
            e.nodes[1].edges.erase(i);
            this->find_edge(e,i);
            edges.erase(i);
        }

        void show(){
            for (typename NodeCtnr::iterator i = nodes.begin(); i != nodes.end(); ++i)
            {
                cout<<"---"<<(*i)->get_data()<<"---"<<endl;
                typename vector<edge*>::iterator j ;
                for ( j = ((*i)->edges).begin(); j != ((*i)->edges).end(); ++j)
                {
                    cout<<(*j)->nodes[0]->data<<"-"<<(*j)->data<<"->"<<(*j)->nodes[1]->data<<endl;
                }
                
            }

        }
    protected:
    private:
        NodeCtnr nodes;
        EdgeCtnr edges;
};
