#include<bits/stdc++.h>
using namespace std;
int FibonacciDNC(int n)
{
    if(n==0 || n==1)
    {
        //cout<<n<<"-";
        return n;
    }
    return FibonacciDNC(n-1)+FibonacciDNC(n-2);
}
int FibonacciMemoization(int n, vector<int>&fib)
{
    if(n==0 || n==1)
        return n;
    if(fib[n]!=0)
        return fib[n];
    return fib[n]=FibonacciMemoization(n-1,fib)+FibonacciMemoization(n-2,fib);    
}
int FibTab(int n)
{
    vector<int>v(n+1,0);
    v[0]=0;v[1]=1;
    for(int i=2;i<=n;i++)
    {
        v[i]=v[i-1]+v[i-2];
    }
    return v[n];
}
int main()
{
    int n=8;
    //cout<<FibonacciDNC(n)<<endl;   
    vector<int> fib(n+1,0);
    //cout<<FibonacciMemoization(n,fib)<<endl;
    cout<<FibTab(n);
}