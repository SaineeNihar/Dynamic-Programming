#include<bits/stdc++.h>
using namespace std;
int lis(int c[],int n)
{
    int l[n];
    for(int i=0;i<n;i++)
        l[i]=1;
    for(int i=1;i<n;i++)
    {   
        for(int j=0;j<i;j++)
        {
            if(c[i]>c[j] and l[i]<l[j]+1)
                l[i]=l[j]+1;
        }
    }
    int max=0;
    for(int i=0;i<n;i++)
        if(l[i]>max)
            max=l[i];
    return max;
}
int main(){
    //Pairwise sorting of North-south and then find LIS, 
    //*Solution is not exaclty the sol. of building bridges problem.
    int north[]={2,4,5,1,6,8,3,7};
    int south[]={1,5,7,3,8,2,7,6};
    int n=sizeof(north)/sizeof(north[0]);
    sort(north,north+n);
    cout<<lis(south,n);
    return 0;
}