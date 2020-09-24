#include<bits/stdc++.h>
using namespace std;
bool subsum(int a[],int n,int sum)
{
    bool ans[n+1][sum+1];
    for(int i=0;i<=sum;i++)
        ans[0][i]=false;
    for(int i=0;i<=n;i++)
        ans[i][0]=true;
    int res[n];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j<a[i-1])
                ans[i][j]=ans[i-1][j];
            else
                ans[i][j]=ans[i-1][j]|| ans[i-1][j-a[i-1]];
        }
    }
    return ans[n][sum];
}

int main()
{
    int  a[]={3,-2,4,19,3,7,13,10,6,11};
    int sum=1;
    int size=sizeof(a)/sizeof(a[0]);
    cout<<subsum(a,size,sum)<<endl;
}
