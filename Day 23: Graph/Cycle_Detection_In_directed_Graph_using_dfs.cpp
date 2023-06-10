#include <bits/stdc++.h>

vector<int> visited;
bool dfs(int vert, vector<vector<int>> & adj,vector<int> & visited){
    visited[vert]=1;
    for(int i=0;i<adj[vert].size();i++){
        if(visited[adj[vert][i]]==0){
            if(dfs(adj[vert][i],adj,visited)){
                return true;
            }
        }
        else if(visited[adj[vert][i]]==1){
            return true;
        }
    }
    visited[vert]=2;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> a;
    vector<vector<int>> adj(n,a);
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first-1].emplace_back(edges[i].second-1);
    }
    vector<int> visited(n,0);
    //vector<int> visited(n,0);
    for(int it=0;it<n;it++){
        if(!visited[it]){
            if(dfs(it,adj,visited)){
                return 1;
            }
        }
    }
    return 0;
}