#include<bits/stdc++.h>
using namespace std;
class graph()
{

public:
    map<int,list<int>>mp;
    void addEdges(int u,int v,bool dir);
    {
       adj[u].push_back(v);
       if(!dir)
       {
           adj[v].push_back(u);
       }

    }

    void print()
    {

        for(auto i:adj)
        {
            cout<<i<<"::";
            for(auto j:adj[i])
            {
                cout<<j<<" ";

            }
            cout<<endl;
        }
    }


};
int main()
{
   int n,e;
   cin>>n>>e;
   for(int i=0;i<n;i++)
   {
       int u;
       cin>>u;l
       int v;
       cin>>v;
       graph.addEdges(u,v,0);
       print()

   }
}

//BFS

vector<int>bfsGraph(int n,vector<int>adj[])
{
    int vis[n] ={0};
    vis[0] =1;
    vector<int>bfs;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        q.push_back(node);
        for(auto  it:adj[node])
        {
            if(!vis[it])
            {
                vis[it] =1;
                q.push(it);
            }
        }
    }

    return bfs;
}

//DFS

void dfs(int node,int vis[],vector<int>&ans,vector<int>adj)
{
    vis[node]  =1;
    ans.push_back(node);
    for(auto it :adj[node])
    {
        if(!vis[it])
        {
             dfs(it,vis,ans,adj);

        }
    }
}

vector<int>bfsGraph(int n,vector<int>adj[])
{
    int vis[n] = {0};
    vis[0] = 1;
    vector<int>ans;
    dfs(0,vis,ans,adj);
    return ans;
}