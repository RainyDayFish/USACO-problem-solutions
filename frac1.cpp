/*
ID: ryan.qi1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct frac {
int n;
int d;
};

bool cmd(const frac & s1, const frac & s2)
{
   return (double)s1.n/s1.d<(double)s2.n/s2.d;
}

bool common(int a,int b){
for(int f=2;f<=a;f++){
    if(a%f==0&&b%f==0){
        return 0;
    }
}
return 1;
}

int main()
{
    ifstream in ("frac1.in");
    ofstream out ("frac1.out");
    int n;
    in>>n;
    out<<"0/1"<<endl;

    vector <frac> num;

    for(int f=1;f<=n;f++){
        for( int a=1;a<f;a++){
            if(a==1||common(a,f)){
                frac temp;
                temp.n=a;
                temp.d=f;
                num.push_back(temp);
            }
        }
    }
    sort(num.begin(), num.end(), cmd);
    for(int f=0;f<num.size();f++){
        out<<num[f].n<<"/"<<num[f].d<<endl;
    }
    out<<"1/1"<<endl;
    return 0;
}
