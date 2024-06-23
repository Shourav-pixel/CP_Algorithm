#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&ans,int vis[],vector<int> adj[])
{
    vis[node] =1;
    ans.push_back(node);
    for(auto it:adj[node])
    {
        dfs(it,ans,vis,adj);
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int>ans;
    int vis[n] = {0};
    dfs(0,ans,vis,adj);

    return ans;
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>adj[n+1];
    for(int i=0;i<=e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

  vector<int>ans =  dfsOfGraph(n,adj);

  for(auto it:ans)
  {
    cout<<it<<" ";
  }
}