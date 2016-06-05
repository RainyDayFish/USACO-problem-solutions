/*
ID: ryan.qi1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int np, ng;
struct person
{
    string name;
    int gain=0, loss=0;
};
int find(string name, struct person people[])
{

    for(int f=0; f<np; f++)
    {
        if(people[f].name==name)
        {
            return f;
        }
    }
}
int main()
{
    ofstream out ("gift1.out");
    ifstream in  ("gift1.in");

    int index=0, give=0, total=0;
    in>>np;
    person * people= new person [np];
    //string people[np];
    string temp;
    for(int f=0; f<np; f++)
    {
        in>>people[f].name;
    }
    for(int f=0; f<np; f++)
    {
        in>>temp;
        index=find(temp,people);
        in>>total>>ng;
        if(ng>0){
        give=total/ng;
        }else{
        give=0;
        }
        people[index].loss=give*ng;
        for(int a=0; a<ng; a++)
        {
            in>>temp;
            index=find(temp,people);
            people[index].gain+=give;
        }
    }
    for(int f=0; f<np; f++)
    {
        out<<people[f].name<<" "<<(people[f].gain-people[f].loss)<<endl;
    }
    return 0;
}
