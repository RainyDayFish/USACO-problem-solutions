/*
ID: ryan.qi1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int milk [21] [21] [21];
int ca, cb, cc;
void findd(int a,int b,int c){
    if(milk[a][b][c]==0){
        milk[a][b][c]=1;
        if(a>cb-b){
            findd(a-cb+b,cb,c);
        }else{
        findd(0,b+a,c);
        }       if(a>cc-c){
            findd(a-cc+c,b,cc);
        }else{
        findd(0,b,c+a);
        }        if(b>ca-a){
            findd(b-ca+a,ca,c);
        }else{
        findd(b+a,0,c);
        }        if(b>cc-c){
            findd(a,b-cc+c,cb);
        }else{
        findd(a,0,c+b);
        }        if(c>ca-a){
            findd(ca,b,c-ca+a);
        }else{
        findd(a+c,b,0);
        }        if(c>cb-b){
            findd(a,cb,c-cb+b);
        }else{
        findd(a,b+c,0);
        }
    }

}

int main()
{
        ifstream in("milk3.in");
    ofstream out ("milk3.out");
in>>ca>>cb>>cc;
int counter=0;
findd(0,0,cc);
    for(int f=20;f>=0;f--){
        for(int a=20;a>=0;a--){
            for(int s=20;s>=0;s--){

                if(milk[f][a][s]==1&&f==0){
                        if(counter==1){out<<" ";}
                out<<s;
                counter=1;
                }

            }
        }
    }
out<<endl;
    return 0;
}
