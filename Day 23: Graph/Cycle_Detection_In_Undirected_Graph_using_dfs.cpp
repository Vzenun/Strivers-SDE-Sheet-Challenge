bool dfs(int s,vector<vector<int>> adj,vector<int>& visited,int parent){
    visited[s]=1;
    for(int i=0;i<adj[s].size();i++){
        if(visited[adj[s][i]]==0){
            if(dfs(adj[s][i],adj,visited,s)){
                return true;
            }
        }
        else if(visited[adj[s][i]]==1 && adj[s][i]!=parent){
            return true;
        }
    }
    visited[s]=2;
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
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i,adj,visited,-1)){
                return "Yes";
            }
        }
    }
    return "No";
}
