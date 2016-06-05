/*
ID: ryan.qi1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;
struct answer{
string base;
string square;
};
    ifstream in ("palsquare.in");
    ofstream out ("palsquare.out");
    int base;
    int temp;
  //  string displayB;
    vector <answer> correct;
    stack <int> num;
    vector <int> solution;
    stack <int> remain;
    long int dSquare=0;
    string displayS;
void num2stack(int number){
while(number>0){
    num.push(number%10);
    number/10;
}
}
int power(int num){
int temp=1;
for(int f=0;f<num;f++){
    temp*=10;
}
return temp;
}
 int convert2ten(int base, int num){
return 0;
}

int convertFromTen(int base, int num){
int temp=num;
while(temp>=base){
         int remainder= temp-(base*(int)(temp/base));
  temp/=base;
  remain.push(remainder);
}
remain.push(temp);
dSquare=0;
solution.clear();
displayS="";
for(int f=0;remain.size()>0;f++){
    solution.push_back(remain.top());
    dSquare+=remain.top()*power(remain.size()-1);
    if(remain.top()>=10){
        displayS+=(char)(55+remain.top());
    }else{
    displayS+=(char)(48+remain.top());
    }
    remain.pop();
}
//out<<dSquare<<endl;
}

int main()
{
    in>>base;

    for(int f=1;true;f++){
        temp=f*f;
        convertFromTen(base,temp);
        bool pal=true;
        for(int f=0;f<solution.size()/2;f++){
            if(solution[f]!=solution[solution.size()-1-f]){
                pal=false;
            }
        }
        if(pal){
                answer b;
        b.square=displayS;
        convertFromTen(base,f);
        b.base=displayS;
        //cout<<dSquare<<endl;
             if(f>300){
                 //cout<<";askdjfsldkfj";
                   // cout<<dSquare<<b.base<<" "<<b.square<<endl;
            break;
        }
            correct.push_back(b);
        }

    }
    for(int f=0;f<correct.size();f++){
        out<<correct[f].base<<" "<<correct[f].square<<endl;
    }
    return 0;
}
