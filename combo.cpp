/*
ID: ryan.qi1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int shorten(int num, int total, int combo){
    int temp=combo+num;
while(temp<=0){
temp+=total;
}
return temp;
}
int small(int num, int total, int combo){
int temp=combo+num;
while(temp>total){
temp-=total;
}
return temp;
}
int main()
{
    int counter=0;
    vector <int> solutions;
    ifstream in ("combo.in");
    ofstream out ("combo.out");
    int nnum;
    in>>nnum;
    int numbers[nnum];
    for(int f=1;f<nnum;f++){
        numbers[f]=f;
    }
    int farmer[3];
    int master [3];
    for(int f=0; f<3; f++)
    {
        in>>farmer[f];
    }
    for(int f=0; f<3; f++)
    {
        in>>master[f];
    }
    int temp;
    for(int f=-2;f<=2;f++){
        for(int a=-2;a<=2;a++){
            for(int s=-2;s<=2;s++){
                    temp=0;
                temp+=((farmer[0]+f<=0)?shorten(f,nnum,farmer[0]):small(f,nnum,farmer[0]))*10000;
            temp+=((farmer[1]+a<=0)?shorten(a,nnum,farmer[1]):small(a,nnum,farmer[1]))*100;
             temp+=((farmer[2]+s<=0)?shorten(s,nnum,farmer[2]):small(s,nnum,farmer[2]));
                if(find(solutions.begin(),solutions.end(),temp)==solutions.end()){
               // cout<<temp<<endl;
                    solutions.push_back(temp);
                    counter++;
                }
            }
        }

    }
  for(int f=-2;f<=2;f++){
        for(int a=-2;a<=2;a++){
            for(int s=-2;s<=2;s++){
                    temp=0;
                temp+=((master[0]+f<=0)?shorten(f,nnum,master[0]):small(f,nnum,master[0]))*10000;
            temp+=((master[1]+a<=0)?shorten(a,nnum,master[1]):small(a,nnum,master[1]))*100;
             temp+=((master[2]+s<=0)?shorten(s,nnum,master[2]):small(s,nnum,master[2]));
                if(find(solutions.begin(),solutions.end(),temp)==solutions.end()){
               // cout<<temp<<endl;
                    solutions.push_back(temp);
                    counter++;
                }
            }
        }

    }

    out << counter << endl;
    return 0;
}
