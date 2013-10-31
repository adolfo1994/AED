#include "Dijkstra.h"
struct Tests
{
    void test_insertion(){
        Graph<char, int> g;
        g.insert_node('a');
        g.insert_node('b');
        g.insert_node('c');
        g.insert_node('d');
        g.insert_node('e');
        g.show();
        cout<<"--------End of node insertion test--------------"<<endl;
    }
    void test_edge_insertion(){
        Graph<char, int> g;
        g.insert_node('a');
        g.insert_node('b');
        g.insert_node('c');
        g.insert_node('d');
        g.insert_node('e');
        g.insert_edge(g.find('a'),g.find('b'),3,0);
        g.insert_edge(g.find('a'),g.find('c'),5,0);
        g.insert_edge(g.find('a'),g.find('d'),7,0);
        g.insert_edge(g.find('b'),g.find('c'),1,0);
        g.insert_edge(g.find('c'),g.find('e'),3,0);
        g.insert_edge(g.find('d'),g.find('e'),1,0);
        g.show();
        cout<<"--------End of edge insertion test--------------"<<endl;
    }

    void run(){
        this->test_insertion();
        this->test_edge_insertion();

    }
};