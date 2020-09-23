#include<bits/stdc++.h>
using namespace std;
typedef struct box
{
    int h,d,w;
}box;
bool comp(box b1,box b2)
{
    return b1.d*b1.w >b2.d*b2.w;
}
int boxstacking(box b[],int n)
{
    box newb[3*n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        newb[j].h=b[i].h;
        newb[j].d=max(b[i].d,b[i].w);
        newb[j].w=min(b[i].d,b[i].w);
        j++;
        newb[j].h=b[i].d;
        newb[j].d=max(b[i].h,b[i].w);
        newb[j].w=min(b[i].h,b[i].w);
        j++;
        newb[j].h=b[i].w;
        newb[j].d=max(b[i].d,b[i].h);
        newb[j].w=min(b[i].d,b[i].h);
        j++;
    }
    n=3*n;
    sort(newb,newb+n,comp);
    for(int i=0;i<n;i++)
    {
        cout<<newb[i].h<<" "<<newb[i].d<<" "<<newb[i].w<<endl;
    }
    int ans[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=newb[i].h;        
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(newb[i].w<newb[j].w and newb[i].d<newb[j].d and ans[i]<ans[j]+newb[i].h)
                ans[i]=ans[j]+newb[i].h;
        }
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
        if(max<ans[i])
        {
            max=ans[i];
        }
    }
    return max;
}
int main()
{
    box b[]={{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
    int n=sizeof(b)/sizeof(b[0]);
    cout<<boxstacking(b,n)<<endl;
    return 0;
}