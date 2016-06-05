/*
ID: ryan.qi1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
    bool is[7]={1};
    bool i[5]={1};
int main()
{
    ifstream in ("transform.in");
    ofstream out ("transform.out");
    int n;
    in>>n;
    char start [n][n];
    char endd [n][n];
    char tempp [n][n];
    string temp;
    int answer=0;
    for(int f=0;f<7;f++){
        is[f]=1;
    }
    for(int f=0;f<5;f++){
        i[f]=1;
    }
    for(int f=0; f<n; f++)
    {
        in>>temp;
        for(int a=0; a<n; a++)
        {
            start[f][a]=temp[a];
            tempp[f][a]=start[f][a];
        }
    }
    for(int f=0; f<n; f++)
    {
        in>>temp;
        for(int a=0; a<n; a++)
        {
            endd[f][a]=temp[a];
        }
    }

    for(int f=0; f<n; f++)
    {
        for(int a=0; a<n; a++)
        {
          //  cout<< a<<" "<<f<<endl;
            if(is[0]&&endd[f][a]!=start[n-a-1][f])
            {
                is[0]=false;
               // break;
            }
             if(is[1]&&endd[f][a]!=start[n-f-1][n-a-1])
            {
                is[1]=false;
            }
            if(is[2]&&endd[f][a]!=start[a][n-f-1])
            {
                is[2]=false;
            }
            if(is[3]&&endd[f][a]!=start[f][n-a-1])
            {
                is[3]=false;
            }
            if(is[5]&&endd[f][a]!=start[f][a]){
                is[5]=false;
            }
          //  cout<<endd[f][a]<<" "<<start[n-f-1][n-a-1]<<endl;
        }
    }

   for(int f=0;f<n;f++){
    for(int a=0;a<n/2;a++){
        char s=tempp[f][a];
        tempp[f][a]=tempp[f][n-1-a];
        tempp[f][n-1-a]=s;
    }
   }
    for(int f=0; f<n; f++)
    {
        for(int a=0; a<n; a++)
        {
          //  cout<< a<<" "<<f<<endl;
            if(i[0]&&endd[f][a]!=tempp[n-a-1][f])
            {
                i[0]=false;
               // break;
            }
             if(i[1]&&endd[f][a]!=tempp[n-f-1][n-a-1])
            {
                i[1]=false;
            }
            if(i[2]&&endd[f][a]!=tempp[a][n-f-1])
            {
                i[2]=false;
            }
            if(i[3]&&endd[f][a]!=tempp[f][n-a-1])
            {
                i[3]=false;
            }
            if(i[4]&&endd[f][a]!=tempp[f][a]){
                i[4]=false;
            }
          //  cout<<endd[f][a]<<" "<<start[n-f-1][n-a-1]<<endl;
        }
    }
    is[4]=false;
    for(int f=0;f<5;f++){
        if(i[f]){
            is[4]=true;
        }
    }

    for(int f=0;f<7;f++){
        if(is[f]){
            out<<f+1<<endl;
            break;
        }
       // cout<<is[f]<<" "<<endl;
    }

    return 0;
}
