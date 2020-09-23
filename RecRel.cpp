#include<bits/stdc++.h>
using namespace std;
int rec1(int n)
{   
    if(n==0 or n==1)
        return 2;
    int sum=0;
    for(int i=1;i<n;i++)
        sum+=2*rec1(i)*rec1(i-1);
    return sum;
}
int rec2(int n)
{
    int t[n+1];
    t[0]=t[1]=2;
    for(int i=2;i<=n;i++)
    {
        t[i]=0;
        for(int j=1;j<i;j++)
            t[i]+=2*t[j]*t[j-1];
    }
    return t[n];
}
int rec3(int n)
{
    int t[n+1];
    t[0]=t[1]=2;
    t[2]=2*t[1]*t[0];
    for(int i=3;i<=n;i++)
    {
        t[i]=0;
        t[i]=t[i-1]+2*t[i-2]*t[i-1];
    }
    return t[n];
}
int main()
{
    int n=20;
    cout<<rec1(n)<<endl;
    cout<<rec2(n)<<endl;
    cout<<rec3(n)<<endl;
    return 0;
}