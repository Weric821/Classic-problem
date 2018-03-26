#include<iostream>
using namespace std;

struct node
{
    int data=0;
    node *L=NULL;
    node *R=NULL;
};
node **arr;

void Adjustment(int number)
{
    //若目前的點並非root，且此點的data大於父點的data
    if(number!=1 && arr[number]->data>arr[number/2]->data)
    {
        swap(arr[number]->data,arr[number/2]->data);
        Adjustment(number/2);
    }
    else
        return;
}

void trace(node *root)
{
    cout<<root->data<<" ";
    if(root->L!=NULL)
        trace(root->L);
    if(root->R!=NULL)
        trace(root->R);
    return;
}

int main()
{
    int SIZE=0;
    cin>>SIZE;      //總共輸入數字

    arr=new node *[SIZE+1];     //建樹，以array的形式存node
    for(int i=1;i<SIZE+1;i++)
    {
        arr[i]=new node();
        arr[i]->data=0;
        arr[i]->L=NULL;
        arr[i]->R=NULL;
        cin>>arr[i]->data;
    }

    for(int i=2;i<SIZE+1;i++)   //將各點左子樹、右子樹連結起來
    {
        if(i%2==0)
            arr[i/2]->L=arr[i];
        else
            arr[i/2]->R=arr[i];
    }

    for(int i=SIZE;i>=1;i--)    //從最後一個點開始做調整，調成Max Heap
    {
        Adjustment(i);
    }

    for(int i=1;i<=SIZE;i++)    //輸出最終array的資料順序
    {
        cout<<arr[i]->data<<" ";
    }
    cout<<endl;

    trace(arr[1]);              //以DLR前序(preorder)走訪此樹
    cout<<endl;
}
