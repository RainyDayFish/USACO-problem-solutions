/*
ID: ryan.qi1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

   int num[1000];
   int n;
int small(int a, int b){
    int minn=a;
for(int f=n-1;f>=a;f--){
if(num[f]==b){
    minn=f;
}

}
return minn;
}

int main()
{
    ifstream in ("sort3.in");
    ofstream out ("sort3.out");

   in>>n;

   for(int f=0;f<n;f++){
    in>>num[f];
   }
   vector<int> sorted (num,num+n);
   sort(sorted.begin(),sorted.begin()+n);

   int swaps=0;
for(int f=0;f<n;f++){
    if(sorted[f]!=num[f]){
    //        cout<<sorted[f]<<" "<<num[f]<<" : ";
     for(int a=f+1;a<n;a++){
        if(sorted[f]==num[a]&&sorted[a]==num[f]){
            swaps++;
 //   cout<<sorted[a]<<" "<<num[a];
            swap(num[f],num[a]);
            break;
        }
     }
   //  cout<<endl;
    }
}
/*
for(int f=0;f<n;f++){
    cout<<num[f]<<" ";
}cout<<endl;
for(int f=0;f<n;f++){
    cout<<sorted[f]<<" ";
}

cout<<endl;
*/
for(int f=0;f<n;f++){
    if(sorted[f]!=num[f]&&num[f]==1){
        swaps+=2;
    }
}
out<<swaps<<endl;

    return 0;
}
