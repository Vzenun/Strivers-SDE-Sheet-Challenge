vector<int> ans;
void dfs(int node,vector<bool> &visited,vector<vector<int>> adjl){
    visited[node]=true;
    ans.push_back(node);
    for(int i=0;i<adjl[node].size();i++){
        if(!visited[adjl[node][i]]){
            dfs(adjl[node][i],visited,adjl);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> sol;
    vector<vector<int>> adj(V);
    for(int i=0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            dfs(i,visited,adj);
            sol.emplace_back(ans);
            ans.clear();
        }
    }
    return sol;
}