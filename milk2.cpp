/*
ID: ryan.qi1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Farmer{
int start;
int fin;
};

bool compare (Farmer a, Farmer b){
return a.start<b.start;
}
bool compareReverse (Farmer a, Farmer b){
return a.fin<b.fin;
}
int main()
{
    ifstream in ("milk2.in");
    ofstream out ("milk2.out");
    int num;
    in>>num;

    Farmer people [num];
    for(int f=0;f<num;f++){
        in>>people[f].start>>people[f].fin;
    }
    sort(people,people+num,compare);
    int afk=0, milk=0;
    int beg=people[0].start, endd=0, temp=0;
    bool milked=true;
        if(num==1){
        afk=0;
        milk=people[0].fin-people[0].start;
    }else{

//cout<<people[0].start;
    for(int f=0;f<num-1;f++){
        if(people[f].fin>endd){
            endd=people[f].fin;
        }
        if(people[f+1].start>endd){
            temp=endd-beg;
            if(milk<temp){
                milk=temp;
            }
            temp=people[f+1].start-endd;
            if(temp>afk){
                afk=temp;
            }
            beg=people[f+1].start;
        }
    }
if(afk==0&&milk==0){
        int temp=people[0].start;
        sort(people,people+num,compareReverse);
    milk=people[num-1].fin-temp;
}
    }
    out<<milk<<" "<<afk<<endl;

    return 0;
}
