/*
ID: ryan.qi1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Wall{
int row=0;
int col=99;
char sid='D';
};
        /*
    1=w
    2=n
    4=e
    8=s
    3=wn
    5=we
    9=ws
    6=ne
    10=sn
    12=es
    11=wns
    7=wne
    13=wes
    14=nes
    */



    int n[55][55];
    int v[55][55];
        int rooms=0;
        int row, col;
            void clearr(){
    for(int f=0;f<55;f++){
        for(int a=0;a<55;a++){
            v[f][a]=0;
        }
    }

    }
         int dfs(int a, int b, int rooms);
    int left(int a,int b){
    if(b>0){
    return dfs(a,b-1, rooms);
    }return 0;
    }
        int right(int a,int b){
    if(b<col-1){
    return dfs(a,b+1, rooms);
    }return 0;
    }
        int down(int a,int b){
    if(a<row-1){
    return dfs(a+1,b, rooms);
    }return 0;
    }
        int up(int a,int b){
    if(a>0){
    return dfs(a-1,b, rooms);
    }return 0;
    }

    int dfs(int a, int b, int c){
    if(v[a][b]){
        return 0;
    }
    v[a][b]=c+1;
    int area=1;
    if(n[a][b]==1){
        area+=right(a,b);
        area+=up(a,b);
        area+=down(a,b);
    }else if(n[a][b]==2){
    area+=right(a,b);
        area+=down(a,b);
        area+=left(a,b);
    }else if(n[a][b]==3){
        area+=down(a,b);
        area+=right(a,b);
    }else if(n[a][b]==4){
        area+=left(a,b);
        area+=down(a,b);
        area+=up(a,b);
    }else if(n[a][b]==5){
        area+=down(a,b);
        area+=up(a,b);
    }else if(n[a][b]==6){
        area+=down(a,b);
        area+=left(a,b);
    }else if(n[a][b]==8){
        area+=right(a,b);
        area+=up(a,b);
        area+=left(a,b);
    }else if(n[a][b]==9){
        area+=right(a,b);
        area+=up(a,b);
    }else if(n[a][b]==10){
        area+=right(a,b);
        area+=left(a,b);
    }else if(n[a][b]==12){
        area+=up(a,b);
        area+=left(a,b);
    }else if(n[a][b]==11){
        area+=right(a,b);
    }else if(n[a][b]==7){
        area+=down(a,b);
    }else if(n[a][b]==13){
        area+=up(a,b);
    }else if(n[a][b]==14){
        area+=left(a,b);
    }
    return area;
    }

int main()
{
    ifstream in ("castle.in");
    ofstream out ("castle.out");
    in>>col>>row;

    for(int f=0;f<row;f++){
         for(int a=0;a<col;a++){
            in>>n[f][a];
         }
    }
    int maxx=0;
    for(int f=0;f<row;f++){
        for(int a=0;a<col;a++){
                if(v[f][a]==0){
            int temp=dfs(f,a,rooms);
            if(temp>maxx){
                maxx=temp;
            }
            rooms++;
          //  cout<<temp<<endl;
          //  cout<<maxx<<endl;
        }
        }
    }
int e[55][55];
for(int f=0;f<55;f++){
    for(int a=0;a<55;a++){
        e[f][a]=v[f][a];
    }
}
       //  out<<endl;
       out<<rooms<<endl;
        out<<maxx<<endl;
        Wall d;
    for(int f=0;f<row;f++){
        for(int a=0;a<col;a++){
            if(e[f][a]!=e[f][a+1]){
                n[f][a]-=4;
                n[f][a+1]-=1;

clearr();
                int siz=dfs(f,a,1);
               //cout<<" "<< siz<<" " << f<<" "<<a<< endl;
                if(siz>maxx||siz==maxx&&(d.col>a||(d.col==a&&d.row<f))){


                    maxx=siz;
                    d.row=f+1;
                    d.col=a+1;
                    d.sid='E';

                }
                n[f][a]+=4;
                n[f][a+1]+=1;
            }
            // verticle
            if(e[f][a]!=e[f-1][a]){
                n[f][a]-=8;
                n[f][a+1]-=2;

clearr();
                int siz=dfs(f,a,1);
               // cout<<" "<< siz<<" " << f<<" "<<a<< endl;
                if(siz>maxx||siz==maxx&&(d.col>a||(d.col==a&&d.row<f))){


                    maxx=siz;
                    d.row=f+1;
                    d.col=a+1;
                    d.sid='N';

                }
                n[f][a]+=8;
                n[f][a+1]+=2;
            }
        }
    }
out<<maxx<<endl;
out<< d.row<<" "<<d.col<<" "<<d.sid<<endl;


    return 0;
}
