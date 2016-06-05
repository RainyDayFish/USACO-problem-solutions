/*
ID: ryan.qi1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in ("beads.in");
    ofstream out ("beads.out");
    int num, total=0, big=0;
    in>>num;
    string beads, spare, state;
    int lengths[4]= {0};
    in>>beads;
    for(int f=0; f<num; f++)
    {
        char letter=beads[0];
        if(letter=='w'){
            for(int s=0;s<beads.length();s++){
                if(beads[s]!='w'){
                    letter=beads[s];
                    break;
                }
            }
        }
        spare=beads;
        int a=0;
        while(beads[a]==letter||beads[a]=='w')
        {
            total++;
            a++;
        }
        //cout<<total<<" "<<a-1<<" ";;
        spare=beads.substr(a,beads.length()-1);
        a=spare.length()-1;
        char l2=spare[spare.length()-1];
            if(l2=='w'){
            for(int s=spare.length()-1;s>=0;s--){
                if(spare[s]!='w'){
                    l2=beads[s];
                    break;
                }
            }
        }
        while((spare[a]==l2||spare[a]=='w')&&a>=0)
        {
            total++;
            a--;
        }
        if(total>big)
        {
            state=beads;
            big=total;
        }
        //cout<<total<<" "<<beads<<endl;
        total=0;
        beads=beads.substr(1,num-1)+beads[0];
       // cout<<total<<" "<<beads;
    }


    out<< big<<endl;
    //cout<< lengths[0]<<" "<<lengths[1]<<" "<<lengths[2]<<" "<<lengths[3]<<endl;
    return 0;
}
