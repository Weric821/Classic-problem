#include<iostream>
#include<bitset>
using namespace std;
int main()
{
    /*進位制轉換*/
    /*bitset*/
    int a=10;
    string b="100";

    //------OUTPU：  10 to dec 10------//
    cout<<"10 to dec "<<a<<endl;

    //------OUTPU：  100 bin to dec 4------//
    cout<<"100 bin to dec "<<bitset<5>(b).to_ulong()<<endl;

    //------OUTPU：  10 to oct 12------//
    cout<<"10 to oct "<<oct<<a<<endl;

    //------OUTPU：  10 to bin 1010------//
    cout<<"10 to bin "<<bitset<4>(a)<<endl;
}
