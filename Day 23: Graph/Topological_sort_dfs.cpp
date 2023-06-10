#include <bits/stdc++.h> 
vector<int> ans;
void dfs(int node,vector<bool> &visited,vector<vector<int>>& adjl){
    visited[node]=true;
    for(int i=0;i<adjl[node].size();i++){
        if(!visited[adjl[node][i]]){
            dfs(adjl[node][i],visited,adjl);
        }
    }
    ans.push_back(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            dfs(i,visited,adj);
        }
    }
    reverse(ans.begin(),ans.end());
    vector<int> k=ans;
    ans.clear();
    return k;
}