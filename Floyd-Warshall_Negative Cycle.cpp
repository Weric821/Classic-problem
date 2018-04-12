//PTC201804 Problem 2. Healthy Network
//若圖中存在負環則No，否則Yes
//第一列輸入總共有幾個Case
//下一列輸入兩個數字n、m，n為總共有幾個nodes，m為nodes之間有幾個interactions
//接下來m列，每列會有三個數字node1、node2、length輸入，代表node1到node2的距離為length
#include<iostream>
using namespace std;

int main()
{
    int case_number=0;
    cin>>case_number;       //case數
    while(case_number--)
    {
        int nodes=0,interactions=0;
        cin>>nodes>>interactions;   //總共點的個數，總共有幾個關係要輸入
        int **arr=new int*[nodes];
        for(int i=0;i<nodes;i++)
        {
            arr[i]=new int [nodes];
            for(int j=0;j<nodes;j++)
                arr[i][j]=9999;
        }

        for(int i=0,node1,node2,value;i<interactions;i++)
        {
            cin>>node1>>node2>>value;   //輸入node1->node2，且距離存在value變數
            arr[node1-1][node2-1]=value;
        }

        //Floyd-Warshall
        for(int k=0;k<nodes;k++)
            for(int i=0;i<nodes;i++)
                for(int j=0;j<nodes;j++)
                    arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);

        int flag=0;
        //再做一次Floyd-Warshall，若發現距離持續有變短，則存在負環，break
        for(int k=0 ; k<nodes && flag!=1 ; k++)
            for(int i=0 ; i<nodes && flag!=1 ; i++)
                for(int j=0 ; j<nodes && flag!=1 ; j++)
                {
                    if(arr[i][k]+arr[k][j]<arr[i][j])
                        flag=1;
                }

        if(flag==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
