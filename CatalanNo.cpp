#include<bits/stdc++.h>
using namespace std;
int tab[1024];

int f1(int n)
{
    if(n==0)
        return 1;
    int count=0;
    for(int i=1;i<=n; i++) 
        count+=f1(i-1)*f1(n-i);
    return count;
}
int f2(int n)
{
    if(tab[n]!=1)
        return tab[n];
    tab[n]=0;
    for(int i=1;i<=n; i++) 
        tab[n]+=f2(i-1)*f2(n-i);
    return tab[n-1];
}

int main()
{
    int a[]={-2,11,13,32,-4,-5,2};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<f1(3)<<endl;
    cout<<f2(3)<<endl;
    return 0;
}