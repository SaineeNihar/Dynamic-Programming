#include<bits/stdc++.h>
using namespace std;
int halfsubset(int a[],int n)
{
    int k=0;
    for(int i=0;i<n;i++)
        k+=a[i];
    int t[k]={0};
    t[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=k-a[i];j>=0;j--)
        {
            if(t[j])
                t[j+a[i]]=1;
        }
    }
    return t[k/2];
}
int main()
{
    int a[]={2,4,6,10};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<halfsubset(a,n);
}