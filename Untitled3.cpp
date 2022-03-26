#include<bits/stdc++.h>
using namespace std;
#define n 5
int minDist(int dist[], bool Set[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++){
        if (Set[v] == false && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
