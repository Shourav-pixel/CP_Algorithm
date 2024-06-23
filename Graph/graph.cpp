#include<bits/stdc++.h>
using namespace std;

class graph{
public:
    map<int,list<int>>adj;
    void addEdges(int u,int v,bool dir)
    {
        //dir = 0->undirected;
        //dir = 1->directed;
        adj[u].push_back(v);
        if(dir == 0)
        {
            adj[v].push_back(u);

        }
    }

    void print()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
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
    cout<<"Enter Nodes::";
    cin>>n;
    cout<<"Enter Edges:: ";
    cin>>e;

    graph g;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdges(u,v,0);

    }
    g.print();
}
