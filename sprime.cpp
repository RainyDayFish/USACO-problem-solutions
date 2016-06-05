/*
ID: ryan.qi1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int num;
int primes[9];
bool first=true;
    ifstream in ("sprime.in");
    ofstream out ("sprime.out");
bool findPrime(int num)
{
    if(num==1)
    {
        return false;
    }
    else if(num==2)
    {
        return true;
    }
    for(int f=2; f<=sqrt(num); f++)
    {
        if(num%f==0)
        {
            return false;
        }
    }
    return true;
}
int power(int num )
{
    int temp=1;
    for(int f=0; f<num; f++)
    {
        temp*=10;
    }
    return temp;
}

bool ribs(int length)
{

    int temp=0;
    for(int f=0; f<length; f++)
    {
        temp+=power(length-1-f)*primes[f];
    }
    if(findPrime(temp))
    {
        if(length==1)
        {
            return true;
        }
        return ribs(length-1);
    }
    else
    {
        return false;
    }

}

bool rib()
{

    int temp=0;
    int countt=0;
    for(int f=0;primes[f]>0;f++){
        countt++;
    }
    for(int f=0; f<countt; f++)
    {
        temp+=power(countt-1-f)*primes[f];
    }
    //out<<temp<<" temp"<<endl;
    return findPrime(temp);

}

void findd(int pos)
{

    if(primes[num-1]>0)
    {
            for(int f=0; f<num; f++)
            {
                out<<primes[f];
            }
            out<<endl;

        return;
    }
    if(first)
    {
        for(int f=1; f<=9; f+=(f==1||f==2)?1:2)
        {
            primes[pos]=f;
                        if(rib()){
            findd(pos+1);
            }
        }
        first=false;
    }
    else
    {
        for(int f=1; f<=9; f+=2)
        {
            primes[pos]=f;
            if(f==9){
            }
            if(rib()){

            findd(pos+1);
            }

        }
    }
    primes[pos]=0;
}


int main()
{
    in>>num;
    findd(0);

    return 0;
}
