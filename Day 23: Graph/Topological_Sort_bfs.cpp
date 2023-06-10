#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> a;
    vector<vector<int>> adj(v,a);
    vector<int> indegrees(v,0);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].emplace_back(edges[i][1]);
        indegrees[edges[i][1]]+=1;
    }
    vector<int> ans;
    queue<int> q;
    for(int it=0;it<v;it++){
        if(indegrees[it]==0){
            q.push(it);
            ans.emplace_back(it);
        }
    }
    while(!q.empty()){
      int k=q.front();
      q.pop();
      for(int i=0;i<adj[k].size();i++){
        indegrees[adj[k][i]]-=1;
        if(indegrees[adj[k][i]]==0){
          q.push(adj[k][i]);
          ans.emplace_back(adj[k][i]);
        }
      }
    }
    return ans;
}