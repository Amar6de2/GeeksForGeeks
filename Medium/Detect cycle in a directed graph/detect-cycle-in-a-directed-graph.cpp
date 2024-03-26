//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool cycledfs(int node,vector<int> &vis,vector<int> adj[])
    {
        vis[node]=2;//pathvis and vis
        for(auto j:adj[node])
        {
            if(vis[j]==0)//uvisited
            {
                if(cycledfs(j,vis,adj)){return true;}
            }
            else if (vis[j]==2){return true;}}
            
            vis[node]=1;
            return false;}
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);//1 for being visited and 2 for being visited as well as pathvisited!
        for(int i=0;i<V;i++)
        {   if(vis[i]!=1)//agar visited hai toh we won t go
           { bool b=cycledfs(i,vis,adj);
            if(b){return true;}}
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends