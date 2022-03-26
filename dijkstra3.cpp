#include<bits/stdc++.h>

using namespace std;
#define N 5
int m[N][N]={{0,4,0,0,0},{4,0,7,0.0},{0,8,0,9,0},{0,0,7,0,6},{0,2,0,9,0}};
vector<int>dis(N,0);
vector<bool>Set(N,false);

int mindis()
{
    int mmin=INT_MAX,min_index;
    for(int v=0;v<N;v++)
    {
        if(Set[v]==false && dis[v] <= mmin)
        {
            mmin=dis[v];
            min_index= v;
        }
    }
    return min_index;
}

int printsol()
{
    cout<<"vertex distance from source :"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"\t\n"<<i<<"\t"<<dis[i]<<endl;
    }
}

void dijk(int source)
{
    for(int i =0;i<N;i++)
    {
        dis[i]=INT_MAX;
        Set[i]=false;
    }
    dis[source]=0;
    for(int c=0; c<N-1;c++)
    {
        int u =mindis();
        Set[u]=true;
        for(int v=0;v<N;v++)
        {
            if(!Set[v] && m[u][v] && dis[u] != INT_MAX && dis[u]+m[u][v]<dis[v])
            {
                dis[v]=dis[u]+m[u][v];
            }
        }

    }
    printsol();
}

int main()
{
    dijk(0);
    return 0;
}
