/*
ID: ryan.qi1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

    struct Gap{
    int start;
    int endd;
    };



bool compare (Gap a, Gap b){
return (a.endd-a.start)>(b.endd-b.start);
}
int main()
{
    ifstream in ("barn1.in");
    ofstream out ("barn1.out");
        int maxb, nums, numc;
    in>>maxb>>nums>>numc;
        Gap gaps[maxb-1];
    Gap allGaps[numc-1];
    int cows[numc];
    int temp;
    for(int f=0;f<numc;f++){
        in>>cows[f];
      //  stalls[cows[f]-1]=1;
        }
        sort(cows,cows+numc);
//find gaps
for(int f=0;f<numc;f++){
    allGaps[f].start=cows[f];
    allGaps[f].endd=cows[f+1];
}
sort(allGaps,allGaps+numc-1,compare);
for(int f=0;f<maxb-1;f++){
    gaps[f]=allGaps[f];
   // cout<<gaps[f].start<<" "<<gaps[f].endd<<endl;
}
int answer=cows[numc-1]-cows[0]+1;
for(int f=0;f<maxb-1;f++){
       // cout<< answer<<endl;
        if(answer>numc){
    answer-=(gaps[f].endd-gaps[f].start)-1;
}else{break;}
}
out<< answer<<endl;
    return 0;
}
