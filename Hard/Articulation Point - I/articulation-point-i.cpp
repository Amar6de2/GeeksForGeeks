//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
class Solution {
  public:
    int timer=1;
    void dfs(int node,int par,vector<int> &vis,vector<int> &tim,vector<int> &low,set<int> &m,vector<int> adj[])
    {
        vis[node]=1;
        int child=0;
        tim[node]=low[node]=timer++;
        for(auto j:adj[node])
        {
            if(j==par){continue;}
            if(!vis[j]){dfs(j,node,vis,tim,low,m,adj); child++;
                        low[node]=min(low[node],low[j]);
                        if(low[j]>=tim[node] && par!=-1){m.insert(node);}}
            else{low[node]=min(low[node],tim[j]);}            
        }
        if(par==-1 && child>1){m.insert(node);}
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        set<int> m;
        vector<int> vis(V,0);
        vector<int> tim(V,0);
        vector<int> low(V,0);
        vector<int> ans;
        
        for(int i=0;i<V;i++)
        {
            dfs(i,-1,vis,tim,low,m,adj);
        }
       for(auto n:m){ans.push_back(n);}
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