#include<queue>
bool bfs(int s,vector<vector<int> > adj,vector<int>& visited){
    visited[s]=1;
    queue<pair<int,int> > q;
    q.emplace(s,-1);
    while(!q.empty()){ 
        int k=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(int i=0;i<adj[k].size();i++){
            if(adj[k][i]!=parent && visited[adj[k][i]]==1){
                return true;
            }
            else if(visited[adj[k][i]]==0){
                visited[adj[k][i]]=1;
                q.emplace(adj[k][i],k);
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adj(n);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]-1].emplace_back(edges[i][1]-1);
        adj[edges[i][1]-1].emplace_back(edges[i][0]-1);
    }
    vector<int> visited(n,0);
    for(int it=0;it<n;it++){
        if(!visited[it]){
            if(bfs(it,adj,visited)){
                return "Yes";
            }
        }
    }
    return "No";
}
