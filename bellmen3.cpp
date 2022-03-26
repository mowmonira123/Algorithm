#include <bits/stdc++.h>
using namespace std;

struct node
{
    int v;
    int w;
}temp;

vector<node>adj[100];
int n,e;
int prev[100],dis[100];
struct edge
{
    int f;
    int t;
    int we;
}arr[100];

bool bellmenford(int n, int e, int s)
{
    int u,i,v,x,y,z,c,j;
    for (u=0;u<n;u++){
        prev[u]=u;
        dis[u]=999;
    }
    dis[s]=0;
    prev[s]=s;
    for(i=0;i<n-1;i++){
        for(j=0;j<e;j++){
            x=arr[j].f;
            y=arr[j].t;
            z=arr[j].we;
            c=dis[x]+z;
            if(dis[y]>c){
                prev[y]=x;
                dis[y]=c;
            }
        }
    }
    for(i=0;i<n;i++){
        cout << dis[i] << " ";
    }
    for(j=0;j<e;j++){
            x=arr[j].f;
            y=arr[j].t;
            z=arr[j].we;
            c=dis[x]+z;
            if(dis[y]>c){
                  return false;

            }
        }
    return true;

}
int main()
{
    int a,b,weight,s,i,j;
    cin >>n>>e;
    for(i=0;i<e;i++){
        cin >> a >> b >> weight;
        arr[i].f=a;
        arr[i].t=b;
        arr[i].we=-1*weight;
        temp.v=a;
        temp.w=-1*weight;
        adj[b].push_back(temp);
        temp.v=b;
        adj[a].push_back(temp);
    }
    cout << "---------Adjacency List of the Graph------------\n";
    ///traverse and print algorithm
    for(i=0;i<n;i++){
            cout << i << "-> ";
        for(j=0;j<adj[i].size();j++){ /// the adj[i] head array is running up to its size
            cout << adj[i][j].v << "(" << adj[i][j].w << ") ";  ///printing the connected nodes
        }
        cout << endl;
    }
    cout << "Enter source : ";
    cin >> s;
    if(!bellmenford(n,e,s)){
        cout << "\nnegative cycle\n";
    }
    else if (bellmenford(n,e,s)){
        cout << "\nPositive cycle\n";
    }
    return 0;

}

