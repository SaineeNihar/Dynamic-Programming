#include<bits/stdc++.h>
using namespace std;
int f1(int val[],int wt[],int W,int n)
{
    int dp[W+1];
    memset(dp,0,sizeof dp);
    for(int i=0;i<=W;i++)
    {
        for(int j=0;j<n;j++)
            if(wt[j]<=i)
                dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
    }
    return dp[W];
}
int main()
{
    int val[]={1,30},wt[]={1,50};
    int W=100;
    int n=sizeof(val)/sizeof(val[0]);
    cout<<f1(val,wt,W,n)<<endl;
    return 0;
}