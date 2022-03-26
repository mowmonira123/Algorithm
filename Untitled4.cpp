#include <bits/stdc++.h>

using namespace std;

vector <int> adjecent[101];
vector <int> adjecentWeight[101];

bool visited[101];
int parent[101];
priority_queue < pair <int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
int dis[101];
int path[101];
int siz = 0;

void ucs(int s, int g){
    visited[s] = true;
    q.push({0, s});
    dis[s] = 0;

    while(!q.empty()){
        pair<int, int> u = q.top();
        visited[u.second] = true;
        if(u.second == g)
            return;

        q.pop();
        int v, w;
        for(int i=0; i<adjecent[u.second].size(); i++){

            v = adjecent[u.second][i];
            w = adjecentWeight[u.second][i];

            if(!visited[v] && dis[v] > u.first+w){
                dis[v] = u.first+w;
                parent[v] = u.second;
                q.push({dis[v], u.second});
            }
        }
    }
}

void printPath(int s, int g){

    int currentNode = g;

    while(currentNode != s){
        path[siz] = currentNode;
        siz++;
        currentNode = parent[currentNode];
    }
    cout << s;
    for(int i=siz-1; i>=0; i--){
        cout << "->" << path[i];
    }

}


int main(){

    int node, edge, u, v, w;

    cin >> node >> edge;

    for(int i=0; i<edge; i++){
        cin >> u >> v >> w;
        adjecent[u].push_back(v);
        adjecentWeight[u].push_back(w);
    }
    for(int i=0; i<node; i++){
        dis[i] = 10000;
    }

    ucs(1, 3);
    printPath(1, 3);

    return 0;
}
