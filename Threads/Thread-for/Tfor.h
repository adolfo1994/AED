#include <iostream>
#include <thread>

using namespace std;

template <class Cntr, class FO>
void t_manager1( typename Cntr::iterator init, typename Cntr::iterator end, Cntr& obj, FO f){
    for (;init!=end;init++)
    {
        f(*init);
    }
}

template <class Cntr, class FO>
class Dist1
{
public:
    Dist1(Cntr obj,FO f, int cores=0){
        if (cores==0)
        {
            cores = thread::hardware_concurrency();
        }
        thread th[cores];
        typename Cntr::iterator i=obj.begin();
        typename Cntr::iterator j=obj.begin();
        int s = obj.size();
        int pieces = s/cores;
        for (int x = 0; x < cores; ++i)
        {
            i=j;
            int t=0;
            while(t<pieces){
                j++;
            }
            th[x] = thread(t_manager1<Cntr,FO>,i,j,obj,f);
        }
        for (int x = 0; x < cores; ++x)
        {
            th[x].join();
        }


    }
    ~Dist1();

    /* data */
};


template<class Cntr, class Fo,class Dist,int CORES>
class Tfor
{
public:
    Tfor(){
        int cores = CORES;        
        Dist d()
    }
    ~Tfor(){

    }

private:
    
};