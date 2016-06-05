/*
ID: ryan.qi1
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;
int num;
int lowest;
int hills[1000];
int highest;
int solve()
{

    for(int f=0; f<num; f++)
    {
        if(hills[lowest]>hills[f])
        {
            lowest=f;
        }
        if(hills[highest]<hills[f])
        {
            highest=f;
        }
    }
    int cost=INT_MAX;

    for(int f=hills[lowest]; f<=hills[highest]-17; f++)
    {
        int temp=0;
        for(int a=0; a<num; a++)
        {
            if(hills[a]<f)
            {
                temp+=(hills[a]-f)*(hills[a]-f);
            }
            else if(hills[a]>f+17)
            {
                temp+=(f+17-hills[a])*(f+17-hills[a]);
            }
        }
        if(temp<cost)
        {
            cost=temp;
        }
       // cout<<f<<" "<<temp<<endl;
    }



    return cost;
}

int main()
{
    ifstream in ("skidesign.in");
    ofstream out ("skidesign.out");
    in>>num;
    for(int f=0; f<num; f++)
    {
        in>>hills[f];
    }
    out<<solve()<<endl;


    //cout << "Hello world!" << endl;

    return 0;
}
