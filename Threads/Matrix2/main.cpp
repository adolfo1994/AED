#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <thread>

using namespace std;

class Row{
public:
    char* content;
    int size;
    string letters;
    Row(int N){
        letters="abcdefghij";        
        size = (rand()%N)+1;
        content = new char[size];
        for (int i = 0; i < size; ++i)
        {
            content[i] = letters[rand()%letters.length()];
        }

    }
    ~Row(){
        //delete[] content;
    }
    void show(){
        for (int i = 0; i < size; ++i)
        {
            cout<<content[i]<<" ";
        }
        cout<<endl;
    }
};
class Matriz{
public:    
    vector<Row> content;
    int n;
    Matriz(int rows){
        n = rows;

        for(int i=0;i<n;++i){
            Row tmp (n);
            content.push_back(tmp);
        }
    }
    ~Matriz(){
        /*for(int i=0;i<n;++i){
            delete[] mat[i];
        }
        delete mat;*/
    }
    void show(){
        cout<<endl<<endl;
        for (int i = 0; i < n; ++i){   
            content[i].show();
        }
        cout<<endl<<endl;

    }
};


void sub_counter(vector<Row>& mat, int init, int fin, vector<int>* ans){
    for (int i = init; i < fin ; ++i)
    {
        for (int j = 0; j < mat[i].size; ++j)
        {
            switch(mat[i].content[j]){
                case 'a':
                    ans->at(0)+=1;
                    break;
                case 'b':
                    ans->at(1)+=1;
                    break;
                case 'c':
                    ans->at(2)+=1;
                    break;
                case 'd':
                    ans->at(3)+=1;
                    break;
                case 'e':
                    ans->at(4)+=1;
                    break;
                case 'f':
                    ans->at(5)+=1;
                    break;
                case 'g':
                    ans->at(6)+=1;
                    break;
                case 'h':
                    ans->at(7)+=1;
                    break;
                case 'i':
                    ans->at(8)+=1;
                    break;
                case 'j':
                    ans->at(9)+=1;
                    break;
            }
        }
    }

}

vector<int> matrix_counter(Matriz a){
    int cores = 4;
    int rows_per_core = a.n/cores;
    thread th[cores];
    vector<vector<int> > ans;
    for(int i=0;i<cores;++i){
        vector<int> tmp(10,0);
        ans.push_back(tmp);
    }
    for (int i = 0; i < cores; ++i)
    {
        th[i]= thread(sub_counter,a.content,i*rows_per_core, (i*rows_per_core)+rows_per_core, &ans[i]);
    }

    for (int i = 0; i < cores; ++i)
    {
        th[i].join();
    }
    vector<int> v(10,0);
    for (int i = 0; i < cores; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            v[j]+=ans[i][j];
        }
    }
    return v;
}

int main()
{   
    srand(time(0));
    Matriz a(10000);
    a.show();
    vector<int> v = matrix_counter(a);
    string letters = "abcdefghij";
    for (int i = 0; i < 10; ++i)
    {
        cout<<letters[i]<<":"<<v[i]<<endl;
    }
    
    
    
}
