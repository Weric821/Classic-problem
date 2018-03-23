#include<iostream>
using namespace std;

//Hanoi problem
int output;
//A為起始點，B為過渡柱，C為目的地，n為移動數量
void Hanoi(char A,char B,char C,int n)
{
    if(n==1)    //一次移動一個盤子
    {
        cout<<"Move plate :"<<A<<"->"<<C<<endl;
        output++;
    }
    else
    {
            Hanoi(A,C,B,n-1);
            Hanoi(A,B,C,1);
            Hanoi(B,A,C,n-1);
    }
}
int main()
{
    int input=0;
    while(cin>>input)
    {
        output=0;
        Hanoi('A','B','C',input);
        cout<<"Total "<<output<<" steps."<<endl;
    }
}
