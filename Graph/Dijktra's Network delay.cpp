class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>>adj(n+1);
       
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
       vector<int>dist(n+1,1e9);
       priority_queue<pair<int,int>,vector<pair<int,int>>,
       greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
            for(auto it : adj[node])
            {
                int edgeweight = it.second;
                int edgeNode = it.first;;
                if(edgeweight+dis< dist[edgeNode])
                {
                    dist[edgeNode]  = dis + edgeweight;
                    pq.push({ dist[edgeNode],edgeNode});
                }
            }
        }
        int ans =-1;
        for(int i=1;i<=n;i++)
        {
            if(dist[i] == 1e9)return -1;
            ans = max(ans,dist[i]);
        }

        return ans;
    }
};