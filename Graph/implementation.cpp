#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
        unordered_map<int,list<int>>adj;

    void addEdges(int u,int v , bool dir)
    {
        adj[u].push_back(v);
        if(dir == 0 )
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"-->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
   int n,e;
   cout<<"Enter Number of Node:: ";
   cin>>n;
   cout<<"Enter Number of Edge:: ";
   cin>>e;
   Graph g;
   for(int i=0;i<n;i++)
   {
     int u,v;
     cin>>u>>v;
     g.addEdges(u,v,0);
   }

   g.printGraph();



}