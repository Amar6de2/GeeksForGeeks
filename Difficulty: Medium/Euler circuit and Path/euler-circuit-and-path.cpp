//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> adj[])
    {
        vis[node]=1;
        for(auto adjnode: adj[node])
        {
            if(!vis[adjnode])
            {dfs(adjnode,vis,adj);}
        }
    }
    bool connectedcheck(vector<int> adj[],int &V)
    {
        // (ANY node whose degree is greater than 0 must be visited by DFS done by the node whose indeg is ore than 1)
        int nodewithmorethanonedeg=-1;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(adj[i].size()>0)
            {
                nodewithmorethanonedeg=i;
            }
        }
        if(nodewithmorethanonedeg!=-1)
        {dfs(nodewithmorethanonedeg,vis,adj);}
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && adj[i].size()>0){return false;}
        }
        return true;
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    if(!connectedcheck(adj,V)){return 0;}
	    bool ep=true;
	    bool ec=true;
	    int nodewithodddegree=0;
	    for(int i=0;i<V;i++)
	    {
	        int deg=adj[i].size();
	        if(deg%2)
	        {
	            ec=false;
	            nodewithodddegree++;
	            if(nodewithodddegree>2){ep=false;}
	        }
	    }
	    if(ep && ec){return 2;}
	    else if(ep){return 1;}
	    return 0;
	    
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends