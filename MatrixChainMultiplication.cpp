#include<bits/stdc++.h>
using namespace std;
int tab[1024];
int f1(int a[],int i,int j)
{
    if(i==j)
        return 0;
    
    int min=INT_MAX,count=0;;
    for(int k=i;k<j;k++)
    {
        count=f1(a,i,k)+f1(a,k+1,j)+(a[i-1]*a[k]*a[j]);
        if(count<min)
            min=count;
    }
    return min;
}
int f2(int p[],int n)
{
    int m[n][n];
    for(int i=0;i<n;i++)
        m[i][i]=0;
    int q=0,j=0;
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            if(j==n)
                continue;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];  
                if(q<m[i][j])
                    m[i][j]=q;
            }
        }
    }
    return m[1][n-1];
}


int main()
{
    int a[] = {40, 20, 30, 10, 30};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<f1(a,1,n-1)<<endl;
    cout<<f2(a,n)<<endl;
    return 0;
}