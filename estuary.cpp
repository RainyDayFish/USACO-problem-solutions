#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int row, col;
int grid [150][150];
int visit [150][150];
void debug(int s,int d){
for(int f=0;f<row;f++){
    for(int a=0;a<col;a++){
        if(f==s&&a==d){
            cout<<" * ";
        }else{
        cout<<" "<<visit[f][a]<<" ";
        }

    }
    cout<<endl;
}
}

void clean (){
for(int f=0;f<row;f++){
    for(int a=0;a<col;a++){
        grid[f][a]=0;
        visit[f][a]=0;
    }
}
}
void cleanSmall (){
for(int f=0;f<row;f++){
    for(int a=0;a<col;a++){
        visit[f][a]=0;
    }
}
}

int solve (int deep){
for(int f=deep;visit[row-1][col-1]==0;f++){
queue <int>x ;
    queue <int>y;

for(x.push(0),y.push(0);!x.empty();x.pop(),y.pop()){
int c=x.front();
int r=y.front();
int value=grid[r][c];
visit[r][c]=f-grid[r][c];
if(r==row-1&&c==col-1){
    visit[r][c]=1;
}
cout<<r<<" "<<c<<" - "<<grid[r][c]<<" "<<visit[row-1][col-1]<<endl;
debug(r,c);
if(r<row-1&&visit[r+1][c]==0&&(grid[r+1][c]<f)||(r+1==row-1&&c==col-1&&grid[r+1][c]<=f)){
    //    cout<<"a";
    y.push(r+1);
    x.push(c);
}
if(visit[r][c+1]==0&&c<col-1&&(grid[r][c+1]<f)||(r==row-1&&c+1==col-1&&grid[r][c+1]<=f)){
   // cout<<"b";
    y.push(r);
    x.push(c+1);
}
if(visit[r-1][c]==0&&r>0&&grid[r-1][c]<f){
   // cout<<"c";
    y.push(r-1);
    x.push(c);
}
if(visit[r][c-1]==0&&c>0&&grid[r][c-1]<f){
   // cout<<"d";
    y.push(r);
    x.push(c-1);
}
//cout<<" "<<grid[r][c]<<endl;
}
if(visit[row-1][col-1]>0){
return f;
}
cleanSmall();
//cout<<endl<<f<<endl;
}
}

int vol(int depth){
int sum=0;
for(int f=0;f<row;f++){
    for(int a=0;a<col;a++){
        sum+=visit[f][a];
    }
}
return sum;
}
int main()
{
    cout << "Hello world!" << endl;
    ifstream in ("estuary.in");
    ofstream out ("estuary.out");
    int terms;
    in>>terms;
   // for(int a=0;a<terms;a++){

        in>>row>>col;
        for(int f=0;f<row;f++){
            for(int s=0;s<col;s++){
                in>>grid[f][s];
            }
        }
        cout<<":)";
      int depth=solve(grid[row-1][col-1]);
      cout<<depth<<endl;
            cout<<vol(depth)-1;
                clean();
  //  }
    return 0;
}
