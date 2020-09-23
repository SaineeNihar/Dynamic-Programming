#include<bits/stdc++.h>
using namespace std;
long int findTrades(long int x,long int y, long int k)
{
 int trade=0,coal=0,stick=1;
    while(stick<(k*y)+k)
    {
        trade++;
        stick+=x-1;
    }
    cout<<trade<<endl;
    trade+=k;
    return trade;
}
int main()
{
    int t=0;
    cin>>t;
    while(t>0)
    {
        long int x,y,k;
        cin>>x>>y>>k;
        cout<<findTrades(x,y,k)<<endl;
        t--;
    }
    return 0;
}