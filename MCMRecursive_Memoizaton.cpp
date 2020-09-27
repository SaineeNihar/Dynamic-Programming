#include<bits/stdc++.h>
using namespace std;
int mcm(int a[],int i,int j)
{
    if(i>=j)
        return 0;
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=mcm(a,i,k)+mcm(a,k+1,j)+(a[i-1]*a[k]*a[j]);
        if(temp<min)
            min=temp;
    }
    return min;
}
int mcmMemoization(vector<vector<int>> &tab,int arr[],int i,int j)
{
    if(tab[i][j]!=-1)
        return tab[i][j];
    int min =INT_MAX;
    for(int k=i;k<=j-1;k++)
    {   
        int temp=mcmMemoization(tab,arr,i,k)+mcmMemoization(tab,arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(temp<min)
            min=temp;
    }
    //cout<<i<<" "<<j<<" "<<min<<endl;
    return tab[i][j]=min;
}
int main()
{
    
    int arr[]={40,20,30,10,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<vector <int>> tab(n+1,vector<int>(n+1,-1));
    cout<<mcm(arr,1,n-1)<<endl;
    for(int i=0;i<=n;i++)
    {
        tab[i][i]=0;        
    }
    cout<<endl;
    cout<<mcmMemoization(tab,arr,1,n-1)<<endl;
    return 0;
}
