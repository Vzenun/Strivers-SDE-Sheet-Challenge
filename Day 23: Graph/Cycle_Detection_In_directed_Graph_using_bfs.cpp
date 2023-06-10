#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> a;
    vector<vector<int>> adj(n,a);
    vector<int> indegrees(n,0);
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first-1].emplace_back(edges[i].second-1);
        indegrees[edges[i].second-1]+=1;
    }
    queue<int> q;
    for(int it=0;it<n;it++){
        if(indegrees[it]==0){
            q.push(it);
        }
    }
    while(!q.empty()){
      int k=q.front();
      q.pop();
      for(int i=0;i<adj[k].size();i++){
        indegrees[adj[k][i]]-=1;
        if(indegrees[adj[k][i]]==0){
          q.push(adj[k][i]);
        }
      }
    }
    for(int it=0;it<n;it++){
        if(indegrees[it]!=0){
            return 1;
        }
    }
    return 0;
}