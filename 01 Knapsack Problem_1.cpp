//UVa 624
#include<iostream>
#include<map>
#include<queue>

using namespace std;
int *arr;
map<int,int> mp;
map<int,int>::iterator iter;
int Knapsack(int n,int total,int MAX_SIZE,int array_SIZE,queue<int> qu)
{

       if(total==MAX_SIZE||n==-1)
       {
           mp.clear();          //把其他較差的遞回結果清除
           while(!qu.empty())   //將queue中此次遞回結果記錄送入map
           {
               mp[qu.front()]=1;
               qu.pop();
           }
           return total;        //回傳sum
       }
       if(total+arr[n]<=MAX_SIZE)   //加上第n個track的時間不會超過最大時間，可取可不取
       {
           //如果取了比較好，則取
           if(Knapsack(n-1,total+arr[n],MAX_SIZE,array_SIZE,qu)>Knapsack(n-1,total,MAX_SIZE,array_SIZE,qu))
           {
               qu.push(n);
               return total=Knapsack(n-1,total+arr[n],MAX_SIZE,array_SIZE,qu);
           }
           else     //不取
               return total=Knapsack(n-1,total,MAX_SIZE,array_SIZE,qu);

       }
       else                         //加上第n個track的時間會超過最大時間，不取
           return Knapsack(n-1,total,MAX_SIZE,array_SIZE,qu);
}
int main()
{
    int TIME=0;         //總共有的時間
    int case_number=0;  //number of tracks

    while(cin>>TIME>>case_number)
    {
        arr=new int[case_number];   //durations of the tracks
        for(int i=0;i<case_number;i++)
            cin>>arr[i];

        queue<int> qu;
        int output=0;   //sum輸出

        output=Knapsack(case_number-1,0,TIME,case_number,qu);
        for(iter=mp.begin();iter!=mp.end();iter++)  //map中存放選擇結果
                cout<<arr[iter->first]<<" ";

        cout<<"sum:"<<output<<endl;
        mp.clear();
    }
}
