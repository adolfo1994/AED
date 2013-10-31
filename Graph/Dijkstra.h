#include <iostream>
#include <queue>
#include "Graph.h"
using namespace std;


template<class G>
struct Route{
    typedef typename G::n_type N;
    typedef typename G::edge edge;
    typedef typename G::e_type E;
    typedef typename G::node node;

    Route(node* s, int d, vector<node*> w){
        start = s;
        current_distance = d;
        way = w;
    }
    node* start;
    int current_distance;
    vector<node*> way;
};

template <class G>
class Dijkstra
{
public:
    typedef typename G::n_type N;
    typedef typename G::edge edge;
    typedef typename G::e_type E;
    typedef typename G::node node;

    Dijkstra(node* a, node* b){
        init = a;
        end = b;

    }
    ~Dijkstra(){
    }
    bool is_visited(vector<node*>& visited, node* n ){
        for (typename vector<node*>::iterator i = visited.begin(); i != visited.end(); ++i)
        {
            if ((*i)==n)
            {
                return true;
            }            
        }
        return false;

    }
    bool route_exists(vector<Route<G> > routes,node* n,Route<G>*& r){
        for (typename vector<Route<G> >::iterator i = routes.begin(); i != routes.end(); ++i)
        {
            if ((*i).start == n)
            {   
                r = &(*i);
                return true;

            }
            
        }
        return false;

    }
    Route<G>* find_route(vector<Route<G> > routes,node* n){
        for (typename vector<Route<G> >::iterator i = routes.begin(); i != routes.end(); ++i)
        {
            if((*i).start == n){
                return &(*i);
            }
        }

    }
    string shortest_route(){
        string ans;
        vector<Route<G> > routes;
        queue <node*> to_visit;
        vector <node*> visited;
        typename vector<edge>::iterator i;
        to_visit.push(init);
    
        while(!to_visit.empty()){
            typename vector<edge* >::iterator i;
                for (i=to_visit.front()->edges.begin();i!=to_visit.front()->edges.end();i++)
                {
                    if(!is_visited(visited ,(*i)->nodes[1])){
                        to_visit.push((*i)->nodes[1]);
                    }
                    Route<G>* tmp;
                    if(route_exists(routes,(*i)->nodes[1],tmp)){
                        Route<G>* r = find_route(routes,(*i)->nodes[0]);
                        if(tmp->current_distance >  r->current_distance+(*i)->data){
                            tmp->current_distance = r->current_distance+(*i)->data;
                            tmp->way.push_back((*i)->nodes[0]);
                        }
                         
                    }else{
                        Route<G>* w = find_route(routes,(*i)->nodes[0]);
                        vector<node*>  r = w->way;
                        Route<G> x((*i)->nodes[1],w->current_distance+(*i)->data,r);
                        routes.push_back(x);

                    }

                }
            visited.push_back(to_visit.front());
            to_visit.pop();
        }
        Route<G>* lowest_route = &(routes[0]);
        for (typename vector<Route<G> >::iterator i = routes.begin(); i != routes.end(); ++i)
        {
            if((*i).start == end and lowest_route->current_distance > (*i).current_distance){
                lowest_route = &(*i);
            }
            
        }
        for (typename vector<node*>::iterator i = lowest_route->way.begin(); i != lowest_route->way.end(); ++i)
        {
            ans+=(*i)->data;   
        }
        return ans;
    }

    node* init;
    node* end;


};
