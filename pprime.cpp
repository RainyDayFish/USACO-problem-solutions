/*
ID: ryan.qi1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

bool findPali(int a){
string temp="";
while(a>0){
    temp+=(char)(a%10);
    a/=10;
}
//cout<<" "<<temp<<" ";
for(int f=0;f<temp.length()/2;f++){
    if(temp[f]!=temp[temp.length()-f-1]){
        return false;
    }
}
return true;
}

bool findPrime(int a){
    int s=sqrt(a)+1;
for(int f=2;f<s;f++){
    if(a%f==0){
        return false;
    }
}
return true;
}


int main()
{
    ifstream in ("pprime.in");
    ofstream out ("pprime.out");

    int low, high;
    in>>low>>high;
vector <int> pal;

for(int f=0;f<=9;f++){
    for(int a=0;a<=9;a++){
        for(int s=0;s<=9;s++){
            for(int d=0;d<=9;d++){
                for(int w=1;w<=9;w+=2){
                   pal.push_back(w*100000000+d*10000000+s*1000000+a*100000+f*10000+a*1000+s*100+d*10+w);
                //   cout<<w*100000000+d*10000000+s*1000000+a*100000+f*10000+a*1000+s*100+d*10+w<<endl;

                }
            }
        }
    }
}

for(int f=0;f<=9;f++){
    for(int a=0;a<=9;a++){
        for(int s=0;s<=9;s++){
            for(int d=1;d<=9;d+=2){
                pal.push_back(d*10000000+s*1000000+a*100000+f*10000+f*1000+a*100+s*10+d);
                pal.push_back(d*1000000+s*100000+a*10000+f*1000+a*100+s*10+d);
            }
        }
    }
}

for(int f=0;f<=9;f++){
    for(int a=0;a<=9;a++){
        for(int s=1;s<=9;s+=2){
            pal.push_back(s*100000+a*10000+f*1000+f*100+a*10+s);
            pal.push_back(s*10000+a*1000+f*100+a*10+s);
        }
    }
}
 for(int f=1;f<=9;f+=2){
    for(int a=0;a<=9;a++){

            pal.push_back(f*1000+a*100+a*10+f);
            pal.push_back(f*100+a*10+f);

    }
}
 for(int f=1;f<=9;f+=2){


            pal.push_back(f*10+f);
            pal.push_back(f);


}

sort ( pal.begin(), pal.end());
for(int f=0;f<pal.size();f++){
                       if(pal[f]>=low&&pal[f]<=high&&findPrime(pal[f])){
                    out<<pal[f]<<endl;
                   }
}
   // cout<< findPrime(5);
    //cout<<endl<<findPrime(10)<<endl<<findPrime(29)<<endl<<endl<<findPali(3)<<endl<<findPali(101)<<endl<<findPali(100021);

    //cout << "Hello world!" << endl;
    return 0;
}
