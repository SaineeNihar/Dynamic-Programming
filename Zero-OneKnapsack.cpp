#include<bits/stdc++.h>
using namespace std;

int f1(int val[],int wt[],int n,int W)
{
    if(n==0 || W==0)
        return 0;
    if(wt[n]>W)
        return f1(val,wt,n-1,W);
    return max(f1(val,wt,n-1,W),val[n]+f1(val,wt,n-1,W-wt[n]));
}
int f2(int val[],int wt[],int n,int W)
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(wt[i-1]<=j)
                dp[i][j]=val[i-1]+dp[i-1][j-wt[i-1]]>dp[i-1][j]?val[i-1]+dp[i-1][j-wt[i-1]]:dp[i-1][j];            
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    int val[] = { 60, 100, 120 }; 
    int wt[]  = { 10, 20, 30 };  
    int W=50;
    int n=sizeof(wt)/sizeof(wt[0]);
    cout<<f1(val,wt,n-1,W)<<endl;
    cout<<f2(val,wt,n,W)<<endl;
    return 0;
}