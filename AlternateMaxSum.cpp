#include<bits/stdc++.h>
using namespace std;
int f1(int a[],int n)
{
    int m[n];
    m[0]=a[0];
    m[1]=a[1]>a[0]?a[1]:a[0];
    for(int i=2;i<n;i++)
    {
        m[i]=m[i-1]>(m[i-2]+a[i])?m[i-1]:m[i-2]+a[i];
    }
    return m[n-1];
}
int main()
{
    int a[]={-2,11,-4,13,-5,2};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<f1(a,n)<<endl;
    return 0;
}