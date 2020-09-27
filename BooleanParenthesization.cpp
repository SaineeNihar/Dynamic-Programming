#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
int recursiveBooleanParenthesization(string s,int i,int j,bool isTrue)
{
    if(i>j)
        return 0;
    if(i==j)
    {
        if(isTrue)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2)
    {
        //cout<<k<<s[k]<<endl;
        int lt=recursiveBooleanParenthesization(s,i,k-1,true);
        int lf=recursiveBooleanParenthesization(s,i,k-1,false);
        int rt=recursiveBooleanParenthesization(s,k+1,j,true);
        int rf=recursiveBooleanParenthesization(s,k+1,j,false);
        if(s[k]=='&')
        {
            if(isTrue)
                ans+=rt*lt;
            else
                ans+=lt*rf+lf*rf+rt*lf;
        }
        else if(s[k]=='|')
        {
            if(isTrue)
                ans+=rt*lt+lt*rf+rt*lf;
            else
                ans+=lf*rf;
        }
        else if(s[k]=='^')
        {
            if(isTrue)
                ans+=rt*lf+lt*rf;
            else
                ans+=lf*rf+rt*lt;
        }
    }
    return ans;
}

int memoizationBooleanParenthesization(string s,int i,int j,bool isTrue)
{
    string tmp=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
    if(i>j)
        return 0;
    if(i==j)
    {
        if(isTrue)
            return s[i]=='T';
        else 
            return s[i]=='F';
    }
    if(mp.find(tmp)!=mp.end())
        return mp[tmp];
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2)
    {
        int lf=memoizationBooleanParenthesization(s,i,k-1,false);
        int lt=memoizationBooleanParenthesization(s,i,k-1,true);
        int rf=memoizationBooleanParenthesization(s,k+1,j,false);
        int rt=memoizationBooleanParenthesization(s,k+1,j,true);
        if(s[k]=='&')
        {
            if(isTrue)
                ans+=lt*rt;
            else
                ans+=lf*rf+lf*rt+rf*lt;
        }
        else if(s[k]=='|')
        {
            if(isTrue)
                ans+=lt*rt+lt*rf+lf*rt;
            else
                ans+=lf*rf;
        }
        else if(s[k]=='^')
        {
            if(isTrue)
                ans+=lt*rf+lf*rt;
            else
                ans+=lf*rf+lt*rt;
        }
    }
    mp.insert({tmp,ans});
    return mp[tmp];
}
int main()
{
    string s="T^T^T^F|F";
    //Output =14
    int n=s.length();
    cout<<recursiveBooleanParenthesization(s,0,n-1,true)<<endl;
    mp.clear();
    cout<<memoizationBooleanParenthesization(s,0,n-1,true)<<endl;
}