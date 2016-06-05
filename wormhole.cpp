
/*
ID: ryan.qi1
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int pairs[13];
int x[13];
int y[13];
int  holes=0;
int nextworm[13];
bool check()
{
for(int s=1;s<=holes;s++){
    int pos=s;
    for(int f=1; f<=holes; f++)
    {
        pos=pairs[nextworm[pos]];
      //  cout<<pos<<" ";
    }
  //  cout<<endl;
    if(pos>0)
    {
        return true;
    }
}
return false;
}

int solve()
{
    //find unpaired worm

    int f, counter=0;
    for( f=1; f<=holes; f++)
    {
        if(pairs[f]==0)
        {
            break;
        }
    }
    if(f>holes)
    {

        if(check()){
       //         cout<<1<<" ";
        for(int f=1;f<=holes;f++){
     //       cout<< pairs[f];
        }
     //   cout<<endl;
            return 1;
        }
      //                  cout<<0<<" ";
        for(int f=1;f<=holes;f++){
     //       cout<< pairs[f];
        }
     //   cout<<endl;
        return 0;
    }
//find next unpaired worm
    for(int a=f+1; a<=holes; a++)
    {
        if(pairs[a]==0)
        {
            pairs[a]=f;
            pairs[f]=a;
            //cout<<counter<<endl;
            //makes a config
            counter+=solve();
            //resets
            pairs[a]=pairs[f]=0;
        }
    }
//cout<<counter<<endl;
    return counter;
}

int main()
{
    ifstream in("wormhole.in");
    ofstream out("wormhole.out");

    in>>holes;
    for(int f=1; f<=holes; f++)
    {
        in>>x[f]>>y[f];
    }

    for(int f=1;f<=holes;f++){
        for(int a=1;a<=holes;a++){
            if(x[f]<x[a]&&y[a]==y[f]){
                    if(nextworm[f]==0||x[nextworm[f]]-x[f]>x[a]-x[f]){
                nextworm[f]=a;
                    }
            }
        }
     //   cout<<nextworm[f];
    }
  //  cout<<endl;

    out<<solve()<<endl;
    return 0;
}
