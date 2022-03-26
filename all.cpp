#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return (a>b) ? a:b ;
}
int ks(int W,int wt[],int val[],int N)
{
    int k[N+1][W+1];
    for(int i=0;i<=N;i++)
    {
        for(int w=0 ;w<=W;w++)
        {
            if(i==0 || w==0)
            {
                k[i][w]=0;
            }
            else if(wt[i]<= w)
            {
                k[i][w]=max(val[i]+k[i-1][w-wt[i]],k[i-1][w]);
            }
            else{
                k[i][w]=k[i-1][w];
            }
        }
    }
    return k[N][W];
}

int main()
{
    int w,wt[20],val[20],n;
    cin>>n;
    //wt and value
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    //highest wt
    cin>>w;
    cout<<ks(w,wt,val,n);
    return 0;
}
