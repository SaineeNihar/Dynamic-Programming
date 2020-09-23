#include<bits/stdc++.h>
using namespace std;
int lcs(string a,string b,int i,int j)
{
    if(i==a.length() or j==b.length())
        return 0;
    if(a[i]==b[j])
        return 1+lcs(a,b,i+1,j+1);
    return max(lcs(a,b,i+1,j),lcs(a,b,i,j+1));
}
int dplcs(string a,string b)
{
    int lc[a.length()+1][b.length()+1];
    for(int i=0;i<=a.length();i++)
        lc[i][b.length()]=0;
    for(int i=0;i<=b.length();i++)
        lc[a.length()][i]=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        for(int j=b.length()-1;j>=0;j--)
        {
            lc[i][j]=lc[i+1][j+1];
            if(a[i]==b[j])
                lc[i][j]++;
            if(lc[i+1][j]>lc[i][j])
                lc[i][j]=lc[i+1][j];
            if(lc[i][j+1]>lc[i][j])
                lc[i][j]=lc[i][j+1];
        }
    }
    cout<<lc[0][0]<<endl;                 
    return lc[0][0];
}
int main()
{
    string A="ABCBDAB",B="BDCABA";
    //cout<<lcs(A,B,0,0)<<endl;
    cout<<"DP lcs (Memoization)"<<dplcs(A,B)<<endl;
    return 0;

}