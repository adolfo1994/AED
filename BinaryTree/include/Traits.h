#ifndef TRAITS_H_INCLUDED
#define TRAITS_H_INCLUDED
#include "BinTreeIterator.h"
using namespace std;
template <typename T>
struct Ascendant{
    inline bool operator ()(T a, T b){
        return (a<b);
    }
};
template <class T>
struct Descendant{
    inline bool operator ()(T a, T b){
        return (a>b);
    }
};

template <typename t>
struct TraitAsc{
    typedef t data_type;
    typedef Ascendant<data_type> cmp_type;
};
template <typename t>
struct TraitDesc{
    typedef t data_type;
    typedef Descendant<data_type> cmp_type;
};

#endif // TRAITS_H_INCLUDED
