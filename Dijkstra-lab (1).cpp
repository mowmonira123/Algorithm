#include <bits/stdc++.h>
using namespace std;

struct node
{
    int v,w;
}temp;

struct Queue
{
    int dis;
    int flag;
}Q[100];


vector<node>adj[100]; ///2D link list
///priority_queue<pair<int,int> >Q1,Q2;
int n,e;
int prev[100],d[100];
///int inf=4.0/0.0;


int pop(int n)
{
    int mini=9999,i,index;
    for(i=0;i<n;i++){
        if(Q[i].dis<mini && Q[i].flag==1){
            mini=Q[i].dis;
            index=i;
        }
    }
    Q[index].flag=0;
    return index;
}

int run(int n)
{
    int m,c=0;
    for(m=0;m<n;m++){
        if(Q[m].flag==0){
            c++;


        }
    }
    if(c==n)
        return 10;
    else
        return 20;
}

void Dijkstra(int n, int s)
{
    int u,i,k,x;
    for (u=0;u<n;u++){
        prev[u]=u;
        d[u]=99;
        Q[u].dis=99;
        Q[u].flag=1;
    }
	d[s]=0;
	///x=d[s];
	prev[s]=s;
	Q[s].dis=0;
	Q[s].flag=1;
	x=run(n);
    ///Q1.push(make_pair(x,s));
    while(x==20){
        ///u=Q1.top().second;
        u=pop(n);
        for(i=0;i<adj[u].size();i++){ /// the adj[i] head array is running up to its size
            k=adj[u][i].v;
            if(Q[k].flag==1){
            if(d[k]>(d[u]+adj[u][i].w)){
                prev[k]=u;
                d[k]=d[u]+adj[u][i].w;
                Q[u].dis=d[k];
                cout << Q[u].dis << endl;
                ///x=-1*d[k];
                ///Q1.push(make_pair(x,k));

            }
            }
        }
        x=run(n);
    }
}

void display(int s,int des)
{
    int d;
    d=des;
    cout << s << " to " << des << ": " << des;
    while(s!=d){
        d=prev[d];
        cout << "<-" << d;
    }
    cout << endl;
}

int main()
{
    int n,e,a,b,i,j,weight,s,des;
    cin >> n;
    cin >> e;
    for (i=0;i<e;i++){
        cin >> a;
        cin >> b;
        cin >> weight;
        temp.v=a;
        temp.w=weight;
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
    cin >> s;
    Dijkstra(n,s);
    for(des=0;des<n;des++){
    display(s,des);
    }


/*
5 5
0 1 5
0 2 10
1 2 3
2 3 60
3 4 25
*/
}


