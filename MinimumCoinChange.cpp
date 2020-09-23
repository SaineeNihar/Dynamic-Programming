#include<bits/stdc++.h>
using namespace std;
void printCoins(int coins[],int n,int r[],int rlength)
{
    if(r[rlength-1]==-1)
    {    
        cout<<"No Solution Possible\n";
        return;
    }
    int start=rlength-1;
    cout<<"coin Used:\n";
    while(start!=0)
    {
        int j=r[start];
        cout<<coins[j]<<" ";
        start-=coins[j];
    }
    cout<<endl;
}
int f1(int coins[],int n,int total)
{
    int t[total+1];
    int r[total+1];
    for(int i=1;i<=total;i++)
    {
        t[i]=INT_MAX;
        r[i]=-1;
    }
    t[0]=0;
    for(int i=1;i<=total;i++)
    {   
        for(int j=0;j<n;j++)
        {
            if(i>=coins[j])
            {
                int subres=t[i-coins[j]];
                if(subres!=INT_MAX and subres+1<t[i])
                {
                    t[i]=subres+1;
                    r[i]=j;
                }
            }
        }
    }
    for(int i=0;i<=total;i++)
    {
        cout<<r[i]<<"  ";
    }
    cout<<endl;
    printCoins(coins,n,r,total+1);
    return t[total];
}
int main()
{
    int total = 11;
    int coins[] = {9, 6, 5, 1};
    int n=sizeof(coins)/sizeof(coins[0]);
    cout<<f1(coins,n,total)<<endl;


}