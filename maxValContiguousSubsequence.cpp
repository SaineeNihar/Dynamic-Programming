#include<bits/stdc++.h>
using namespace std;
int f1(int a[],int n)
{
    int maxSum=INT_MIN,length=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=a[k];
            }
            if(maxSum<sum)
            {
                maxSum=sum;
                length=j-i+1;
            }
        }
    }
    return maxSum;
}
int f2(int a[],int n)
{
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int cursum=0;
        for(int j=i;j<n;j++)
        {  
            cursum+=a[j];
            if(cursum>maxSum)
                maxSum=cursum;
        }
    }
    return maxSum;
}
int f3(int a[],int n)
{
    int maxsum=0;
    int m[n]={0};
    if(a[0]>0)
        m[0]=a[0];
    else
    {
        m[0]=0;
    }
    for(int i=1;i<n;i++)
    {
        if(m[i-1]+a[i]>0)
        {
            m[i]=m[i-1]+a[i];
        }
        else
        {
            m[i]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(maxsum<m[i])
        {
            maxsum=m[i];
        }
    }
    return maxsum;
}
int f4(int a[],int n)
{
    int sumsofar=0,sumendinghere=0;
    for(int i=0;i<n;i++)
    {
        sumendinghere=sumendinghere+a[i];
        if(sumendinghere<0)
            sumendinghere=0;continue;
        if(sumsofar<sumendinghere)
            sumsofar=sumendinghere;
    }
    return sumsofar;
}
int main()
{
    int a[]={1,-3,4,-2,-1,6};//{-2,11,-4,13,-5,2};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<f1(a,n)<<endl;
    cout<<f2(a,n)<<endl;
    cout<<f3(a,n)<<endl;
    cout<<f4(a,n)<<endl;
    return 0;
}