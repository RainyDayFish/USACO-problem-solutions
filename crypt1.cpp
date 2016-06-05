/*
ID: ryan.qi1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
bool decomp(int num, int nums[], int total){
while(num>0){
    if(find(nums,nums+total,num%10)==nums+total){
        return false;
    }
    num/=10;
}
return true;
}
int main()
{

    ifstream in("crypt1.in");
    ofstream out("crypt1.out");
int counter=0;
    int total;
    in>>total;
    int nums[total];
    for(int f=0;f<total;f++){
        in>>nums[f];
    }
    int top, bot, mid1, mid2, answer;
    for(int a=0;a<total;a++){
        for(int b=0;b<total;b++){
            for(int c=0;c<total;c++){
                for(int d=0;d<total;d++){
                    for(int e=0;e<total;e++){

                        top=nums[a]*100+nums[b]*10+nums[c];
                        bot=nums[d]*10+nums[e];
                        mid1=nums[d]*top;
                        mid2=nums[e]*top;
                        answer=top*bot;
                        //cout<<0;
//top=222;
//bot=22;
//mid1=444;
//mid2=444;

                       // cout<<top<<" "<<bot<<" "<<mid1<<endl;
                        if(floor(log10(mid1))+1!=3){
                                //out<<top<<" "<<bot<<" "<<mid1<<" "<<mid2<<" "<<answer<<" "<<1<<endl;
                            continue;
                        }
                       // cout<<1<<endl;
                        if(floor(log10(mid2))+1!=3){
                                //out<<top<<" "<<bot<<" "<<mid1<<" "<<mid2<<" "<<answer<<" "<<2<<endl;
                            continue;
                        }
                      //  cout<<2<<endl;
                        if(!decomp(mid1,nums,total)){
                                //out<<top<<" "<<bot<<" "<<mid1<<" "<<mid2<<" "<<answer<<" "<<3<<endl;
                            continue;
                        }
                        //cout<<3<<endl;
                        if(!decomp(mid2,nums,total)){
                                //out<<top<<" "<<bot<<" "<<mid1<<" "<<mid2<<" "<<answer<<" "<<4<<endl;
                            continue;
                        }
                      //  cout<<4<<endl;
                        if(floor(log10(answer))+1!=4){
                                //out<<top<<" "<<bot<<" "<<mid1<<" "<<mid2<<" "<<answer<<" "<<5<<endl;
                            continue;
                        }
                      //  cout<<5<<endl;
                        if(!decomp(answer,nums,total)){
                                //out<<top<<" "<<bot<<" "<<mid1<<" "<<mid2<<" "<<answer<<" "<<6<<endl;
                            continue;
                        }
                       // cout<<6<<endl;
                        counter++;
                        //out<<top<<" "<<bot<<" "<<mid1<<" "<<mid2<<" "<<answer<<endl;
                    }
                }
            }
        }
    }

    out<< counter<<endl;
    //cout<<floor(log10(50));
    //cout<<endl<<to_string(90);
    return 0;
}
