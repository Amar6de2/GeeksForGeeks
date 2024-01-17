//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:int pntr=0;
    void dfs(int node,int parent,int vis[],vector<int> adj[],vector<int> &tim,vector<int> &low,vector<int> &mark)
    {
        vis[node]=1;
        tim[node]=low[node]=pntr++;
        int child=0;
        for(int neigh:adj[node])
        { if(neigh==parent){continue;}
            if(vis[neigh]==0){
                dfs(neigh,node,vis,adj,tim,low,mark);
                low[node]=min(low[node],low[neigh]);
                if(low[neigh]>=tim[node] && parent!=-1)
                {
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],tim[neigh]);
            }
        }
        if(parent==-1 && child>1){mark[node]=1;}
        
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        int vis[V];
        for(int k=0;k<V;k++){vis[k]=0;}
        //we will need mark vector,tim vector,low vector and vis
        vector<int> mark(V,0);
        vector<int> tim(V);
        vector<int> low(V);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,-1,vis,adj,tim,low,mark);
            }
        }
        
        vector<int> ans;
        for(int n=0;n<V;n++)
        {
            if(mark[n]==1){ans.push_back(n);}
        }
        if(ans.size()==0){return {-1};}
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends