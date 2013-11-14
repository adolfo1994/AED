#include "Tfor.h"
#include <string>

using namespace std;

class FOO
{
public:
    FOO(){
    }
    ~FOO(){}
    void operator ()(char& a){
        a = ((a+3)%122);
    }
};

int main()
{
    string a = "hola";
    FOO f;
    Tfor<string,FOO,Dist1,4> t(a,f);
    return 0;
}
