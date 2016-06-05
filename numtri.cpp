/*
ID: ryan.qi1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int num[1001][1001];

int main()
{
    ifstream in ("numtri.in");
    ofstream out ("numtri.out");
    int r;
    in>>r;
    for(int f=0;f<r;f++){
        for(int a=0;a<=f;a++){
            in>>num[f][a];
         //   cout<<num[f][a];
        }
        //cout<<endl;
    }
   // int sum[r][r];
    for(int f=r-1;f>=1;f--){
        for(int a=0;a<f;a++){
             //   cout<<num[f-1][a]<<" + :"<<num[f][a]<<" "<<num[f][a+1]<<" :";
            num[f-1][a]+=max (num[f][a],num[f][a+1]);
         //   cout<<num[f-1][a]<<" ";
        }
     //   cout<<endl;
    }
    out<<num[0][0]<<endl;

    return 0;
}
