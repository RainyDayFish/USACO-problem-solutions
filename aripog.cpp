/*
ID: ryan.qi1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in ("ariprog.in");
    ofstream out ("ariprog.out");
    int n, m;
    in>>n>>m;
    int maxm=m*m*2;
    bool bisquares[maxm+1];
    for(int f=0;f<maxm+1;f++){
        bisquares[f]=0;
    }
    for(int f=0;f<=m;f++){
        for(int i=0;i<=m;i++){
            bisquares[f*f+i*i]=1;
        }
    }
    int a;
int counter=0;
    for(int f=1;f<=maxm/(n-1);f++){
                for(int s=0;s<maxm-f*(n-1)+1;s++){
                if(!bisquares[s]){
                continue;
            }
        for( a=0;a<n;a++){
            if(s+a*f>maxm||!bisquares[s+a*f]){
                break;
            }

        }
        if(a==n){
                counter++;
            out<<s<<" "<<f<<endl;
        }
    }
    }
    if(counter==0){
out<<"NONE"<<endl;
}

    return 0;
}
