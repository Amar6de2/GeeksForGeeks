// User function Template for C++
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> vis(V,0);
        vector<vector<pair<int,int>>> adj(V);
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int>>>, greater<pair<int,pair< int,int> >>> pq;

        pq.push({0,{0,-1}});
        int ans=0;
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int nod=pq.top().second.first;
            int par=pq.top().second.second;
            pq.pop();
            if(!vis[nod]){ans+=wt;}
            vis[nod]=1;
            for(auto it: adj[nod])
            {   int adjnode=it.first;
                int dis=it.second;
                if(!vis[adjnode])
                {
                    pq.push({dis,{adjnode,nod}});
                }
            }
        }
        return ans;
    }
};