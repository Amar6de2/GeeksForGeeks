class Solution {
  public:
        vector<int> tim;
        vector<int> low;
        vector<int> ans;
        int timer=0;
    void dfs(int node,vector<vector<int>> &adj,vector<int> &low,vector<int> &tim,int par,vector<int> &vis)
    {
        vis[node]=1;
        int child=0;
        low[node]=tim[node]=timer++;
        for(auto adjnode: adj[node])
        {   
            if(adjnode==par){continue;}
            if(!vis[adjnode])
            {child++;
             dfs(adjnode,adj,low,tim,node,vis);
             low[node]=min(low[node],low[adjnode]);
             if(tim[node]<=low[adjnode] && par!=-1)
             {ans.push_back(node);}
            }
            else
            {
             low[node]=min(low[node],tim[adjnode]);
            }
        }
        if(par==-1 && child>1)
        {ans.push_back(node);}
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> vis(V,0);
        low.resize(V);
        tim.resize(V);
        vector<vector<int>> adj(V);
        for(auto it : edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int node=0;node<V;node++)
        {   if(!vis[node])
            {dfs(node,adj,low,tim,-1,vis);}}
        if(ans.size()==0){ans.push_back(-1);}
        set<int> st(ans.begin(),ans.end());
        vector<int> ansfinal(st.begin(),st.end());
        return ansfinal;
    }
};