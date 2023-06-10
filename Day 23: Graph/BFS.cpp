#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<set<int> > adj(vertex);
    //cout<<vertex<<endl;
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].insert(edges[i].second);
        adj[edges[i].second].insert(edges[i].first);
    }
     vector<bool> visited(vertex,false);
     vector<int> ans;
     queue<int> q;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            q.push(i);
            while(!q.empty()){
                int s=q.front();
                q.pop();
                //cout<<s<<endl;
                ans.push_back(s);
                visited[s]=true;
                set<int> :: iterator it=adj[s].begin();
                while(it!=adj[s].end()){
                    if(!visited[*it]){
                        q.push(*it);
                        //ans.push_back(adj[s][i]);
                        visited[*it]=true;
                    }
                    it++;
                }
            }
        }
    }
    return ans;
}