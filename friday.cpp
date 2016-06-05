/*
ID: ryan.qi1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in ("friday.in");
    ofstream out("friday.out");

    int years, date=1900;
    in>>years;
    int num=0;
    int day=0;
    int occur [7]= {0};
    for(int f=date; f<years+date; f++)
    {
        for(int a=1; a<=12; a++)
        {
            if(a==4||a==6||a==9||a==11)
            {
                num=30;
            }
            else if(a==2)
            {
                if(f%400==0||(f%4==0&&f%100>0))
                {
                    num=29;
                }
                else
                {
                    num=28;
                }
            }
            else
            {
                num=31;
            }
            for(int d=1; d<=num; d++)
            {
                if (d==13)
                {
                    occur[day]++;
                }
                if(day==6)
                {
                    day=0;
                }
                else
                {
                    day++;
                }
            }
        }
    }
    out<<occur[5]<<" "<<occur[6]<<" "<<occur[0]<<" "<<occur[1]<<" "<<occur[2]<<" "<<occur[3]<<" "<<occur[4]<<endl;

    return 0;
}
