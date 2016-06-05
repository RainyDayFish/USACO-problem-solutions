/*
ID: ryan.qi1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("ride.in");
    ofstream out("ride.out");
    string comet, name;
    in>>comet>>name;
    int sumc=1, sumn=1;

    for(int f=0;f<comet.length();f++){
        sumc*=(comet[f]-64);
    }
    for(int f=0;f<name.length();f++){
        sumn*=(name[f]-64);
    }
    sumc%=47;
    sumn%=47;
    if(sumc==sumn){
        out<<"GO";
    }else{
    out<<"STAY";
    }
    out<<endl;

    return 0;
}
