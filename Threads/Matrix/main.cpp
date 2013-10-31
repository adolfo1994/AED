#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <thread>

using namespace std;
class Matriz{
public:    
    char** mat;
    int n;
    int m;
    string letters;
    Matriz(int rows,int columns){
        n=rows;
        m=columns;
        letters="abcdefghij";        
        mat=new char*[n];
        for(int i=0;i<n;++i){
            mat[i]=new char[m];
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                mat[i][j]=letters[rand()%letters.length()];
            }
    
        }
    }
    ~Matriz(){
        for(int i=0;i<n;++i){
            delete[] mat[i];
        }
        delete mat;
    }
    void show(){
        cout<<endl<<endl;
        for (int i = 0; i < n; ++i){   
            for (int j = 0; j < m; ++j){
                cout<<mat[i][j];
            }
            cout<<endl;
        }
        cout<<endl<<endl;

    }
};

void sub_counter(char** mat, int init, int fin, int M,vector<int>* ans){
    for (int i = init; i < fin ; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            switch(mat[i][j]){
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
        th[i]= thread(sub_counter,a.mat,i*rows_per_core, (i*rows_per_core)+rows_per_core, a.m, &ans[i]);
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
    Matriz a(16,30);
    a.show();
    
    vector<int> v=matrix_counter(a);
    
    
}
