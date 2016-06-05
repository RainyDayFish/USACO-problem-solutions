/*
ID: ryan.qi1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
queue <int> remain;
vector <int> number;
int power(int num){
int temp=1;
for(int f=0;f<num;f++){
    temp*=10;
}
return temp;
}

int convert(int base, int num){
while(num>=base){
    remain.push(num-base*(int)(num/base));
num/=base;
}
remain.push(num);
int temp=0;
number.clear();
for(int f=0;remain.size()>0;f++){
    temp+=remain.front()*power(f);
    number.push_back(remain.front());
    remain.pop();
}
return temp;
}

bool isPal(){
for(int f=0;f<number.size()/2;f++){
   //     cout<<"size: "<< number.size()<<" ";
    if(number[f]!=number[number.size()-1-f]){
        return false;
    }
}
return true;
}
int main()
{
    ifstream in ("dualpal.in");
    ofstream out ("dualpal.out");
    int countt, start, counter;
int total=0;
    in>>countt>>start;
    while(total<countt){
            counter=0;
            start++;
      for(int f=2;f<=10;f++){
        convert(f,start);
        if(isPal()){
            counter++;
        }
      }
      if(counter>=2){
            total++;
        out<<start<<endl;
      }
    }
    return 0;
}
