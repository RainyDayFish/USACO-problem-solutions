/*
ID: ryan.qi1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct Farmer{
int amount;
int price;
};

bool compare(Farmer a, Farmer b){
return (a.price<b.price);
}
int main()
{

    ifstream in ("milk.in");
    ofstream out ("milk.out");
    int numf, milkTotal, milk=0, cost=0;
    in>>milkTotal>>numf;
    Farmer farmers[numf];
    for(int f=0; f<numf;f++){
        in>>farmers[f].price>>farmers[f].amount;
    }
    sort(farmers, farmers+numf, compare);
    for(int f=0;f<numf;f++){
        if(milk+farmers[f].amount>=milkTotal){
            cost+=(milkTotal-milk)*farmers[f].price;
            break;
        }
        cost+=farmers[f].amount*farmers[f].price;
    milk+=farmers[f].amount;
    }

    out << cost<< endl;
    return 0;
}
