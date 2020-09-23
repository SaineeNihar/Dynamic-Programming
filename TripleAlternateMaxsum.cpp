#include<bits/stdc++.h>
using namespace std;
int f1(int a[],int n)
{
    int m[n];
    m[0]=a[0];
    m[1]=a[1]>a[0]+a[1]?a[1]:a[0]+a[1];
    m[2]=max(a[2]+a[1],max(a[2]+m[0],m[1]));
    for(int i=3;i<n;i++)
        m[i]=max(a[i]+a[i-1]+m[i-3],max(a[i]+m[i-2],m[i-1]));
    
    return m[n-1];
}
int main()
{
    int a[]={-2,11,13,32,-4,-5,2};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<f1(a,n)<<endl;
    return 0;
}