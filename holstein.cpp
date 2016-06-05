/*
ID: ryan.qi1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
//#include <iostream>
using namespace std;

int N,fnum;
int p[26];
int v[26];
int cf[16];
int feed[16][26];
int store [16];
int maxx=10000000;

ifstream in ("holstein.in");
ofstream out("holstein.out");

void dfs(int n)
{
  //  cout<<maxx<<endl;
    for(int f=0;f<N;f++){
     //   cout<<p[f]<<" ";
    }
  //  cout<<endl;
 //   cout<<endl;
    bool done=1;
    for(int f=0; f<N; f++)
    {
        if(p[f]<v[f])
        {
            done=false;
            break;
        }
    }
    if(done)
    {
        int used=0;
        for(int f=0; f<n; f++)
        {
            used+=cf[f];
        }

        if(used<=maxx)
        {
            maxx=used;
            for(int f=0; f<fnum; f++)
            {
                store[f]=cf[f];
            }
        }

        /*
                if (used <= maxx)
        {
            maxx = used;
            memset (store, 0, sizeof (store));
            for (int i = 0; i <fnum; i++)
                if (cf[i] == 1) store [i] = 1;
        }
*/
/*
                cout<<maxx<<" "<<n<<endl;
        for(int f=0; f<N; f++)
        {
            cout<<p[f]<<" ";
        }
        cout<<endl<<"stored"<<endl;
        for(int f=0; f<N; f++)
        {
            cout<<store[f]<<" ";
        }
        cout<<endl;
        cout<<endl;
        */
        return;
    }

    if(n==fnum)
    {
        return;
    }

    cf[n]=0;
    dfs(n+1);
    cf[n]=1;
    for(int f=0; f<N; f++)
    {
        p[f]+=feed[n][f];
    }
    dfs(n+1);
    for(int f=0; f<N; f++)
    {
        p[f]-=feed[n][f];
    }
    cf[n]=0;



}

void input()
{
    in>>N;
    for(int f=0; f<N; f++)
    {
        in>>v[f];
    }
    in>>fnum;

    for(int f=0; f<fnum; f++)
    {
        for(int a=0; a<N; a++)
        {
            in>>feed[f][a];
        }
    }
}


int main()
{
    input();
    dfs(0);
    out<<maxx;
    for(int f=0; f<fnum; f++)
    {
        if(store[f])
        {
            out<<" "<<f+1;
        }
    }
    out<<endl;
    return 0;
}

/*
ifstream fin ("holstein.in");
ofstream fout ("holstein.out");


int N;
int v [25]; // required for each vitamin
int G;
int f [15] [25]; // feed i can provide the number of j vitamins
int s [15]; // record i feed useless
int p [25]; // Each vitamin has the number of
int minans;
int hashh [15]; // record every search what kind of feed is used


void input ()
{
    fin >> N;
    for (int i = 0; i <N; i++)
        fin >> v [i];
    fin >> G;
    for (int i = 0; i <G; i++)
        for (int j = 0; j <N; j++)
            fin >> f [i] [j];
}


void DFS (int n)
{
    int ok = 1; // deep search the border with pruning, meet all of the vitamins and exit, no more forage species
    for (int i = 0; i <N; i++)
        if (p [i] <v [i])
        {
            ok = 0;
            break;
        }
    if (ok)
    {
        int ans = 0;
        for (int i = 0; i <n; i++)
            ans += s[i];
        if (ans <= minans)
        {
            minans = ans;
            memset (hashh, 0, sizeof (hashh));
            for (int i = 0; i <G; i++)
                if (s [i] == 1) hashh [i] = 1;
        }
                cout<<minans<<" "<<n<<endl;
        for(int i=0; i<N; i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl<<"stored"<<endl;
        for(int i=0; i<N; i++)
        {
            cout<<hashh[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        return;
    }


    if (n == G) return;






    for (s [n] = 0; s [n] <= 1; s [n]++)
    {
        for (int i = 0; i <N; i++)
            p [i] += f [n] [i] * s [n];
        DFS (n +1);
        for (int i = 0; i <N; i++)
            p [i] -= f [n] [i] * s [n];
    }
}


int main ()
{
    input ();
    minans = 100000;
    DFS (0);
    fout << minans;
    for (int i = 0; i <G; i++)
        if (hashh [i]) fout << ' ' << i +1;
    fout << endl;
    return 0;
}
*/
