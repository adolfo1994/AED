#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <string>

using namespace std;

class Caesar
{
public:
    Caesar(int k){
        alf = "abcdefghijklmnopqrstuvwxyz";
        key = k;
    }
    ~Caesar(){

    }
    char operator ()(char a){
        int pos = alf.find(a);
        return alf[(pos+key)%alf.size()];

    }
    string alf;
    int key;
};

char myfoo(char a, int k){
    Caesar c(k);
    cout<<c(a)<<endl;
    return c(a);
}

int main(int argc, char const *argv[])
{
    thread array[4];
    string alf = "abcdefghijklmnopqrstuvwxyz";   
    for (int i = 0; i < 4; ++i)
    {
        array[i]= thread(myfoo,alf[i],2);
    }
    string ans ;
    for (int i = 0; i < 4; ++i)
    {
        ans.append(array[i].join());
    }
    cout<< ans<<endl;
    return 0;
}