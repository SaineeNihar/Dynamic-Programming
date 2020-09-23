#include<bits/stdc++.h>
using namespace std;
int lis(int a[],int n)
{
    int dp[n];
    int solution[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        solution[i]=i;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {   
            if(a[j]<a[i] and dp[i]<dp[j]+1)
            {    
                dp[i]=dp[j]+1;
                solution[i]=j;
            }
        }
    }
    int max=0;
    for(int i=1;i<n;i++)
        if(dp[i]>dp[max])
            max=i;
    int t,newt=max;
    do
    {
        t=newt;
        cout<<a[t]<<" ";
        newt=solution[t];
    } while (t!=newt);
    cout<<endl;
    return dp[max];
}


int main()
{
    int ar[]={3,4,-1,0,6,2,3,9};
    int n=sizeof(ar)/sizeof(ar[0]);
    cout<<lis(ar,n)<<endl;

    return 0;
}