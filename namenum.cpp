/*
ID: ryan.qi1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
struct Letters
{
    char l[3];
};

int main()
{
    Letters phone[8];

    for(int f=0; f<5; f++)
    {
        for(int a=0; a<3; a++)
        {
            phone[f].l[a]=65+a+f*3;
        }
    }
phone[5].l[0]='P';
phone[5].l[1]='R';
phone[5].l[2]='S';
phone[6].l[0]='T';
phone[6].l[1]='U';
phone[6].l[2]='V';
phone[7].l[0]='W';
phone[7].l[0]='X';
phone[7].l[0]='Y';
    ifstream in ("namenum.in");
    ifstream dic ("dict.txt");
    ofstream out ("namenum.out");
    vector <string> words;
    vector <string> real;
    string temp;
    in>>temp;
    string part="";
    int num[temp.length()];
    for(int f=0; f<temp.length(); f++)
    {
        num[f]=(int)temp[f]-48;
    }
    temp="";
    while(dic>>temp)
    {
        words.push_back(temp);
    }
    int length=(sizeof(num)/sizeof(*num));
    /*
int done[length];

for(int f=0;f<length;f++){
    done[f]=0;
}
//cout<<length<<endl;
int current=(length)-1;
  while(done[0]<3){

//cout<<1;

            if(find(words.begin(),words.end(),part)!=words.end())
            {
                real.push_back(part);

            }

            part[current]=phone[num[current]-2].l[done[current]];
            //out<<current<<" "<<done[0]<<" "<<done[1]<<" "<<done[2]<<" "<<done[3]<<" "<<part<<endl;
            current=length-1;
            done[current]++;
           // cout<<5;
            while(done[current]==3&&current>0){
                done[current]=0;
                part[current]=phone[num[current]-2].l[done[current]];
                current--;
                done[current]++;
              //  cout<<3;
            }
            part[current]=phone[num[current]-2].l[done[current]];
  }

//cout<<"4";
*/
bool is;
for(int f=0;f<words.size();f++){
        is=true;
    if(words[f].length()==length){
        for(int a=0;a<length;a++){
            if(find (phone[num[a]-2].l, phone[num[a]-2].l+3, (words[f])[a])==phone[num[a]-2].l+3){
                is=false;
            }
        }

    if(is){
        real.push_back(words[f]);
    }
    }
}

    for(int f=0;f<real.size();f++)
    {
        out<<real[f]<<endl;
    }
    if (real.size()==0){
        out<<"NONE"<<endl;
    }
    return 0;
}
