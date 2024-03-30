//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int> &vis,stack<int> &s,vector<vector<int>> &adj)
	{
	    vis[node]=1;
	    for(auto j: adj[node])
	    {
	        if(!vis[j]){dfs(j,vis,s,adj);}
	    }
	    s.push(node);
	}
	void normaldfs(int node,vector<int> &vis,vector<vector<int>> &revadj)
	{
	    vis[node]=1;
	    for(auto j:revadj[node])
	    {
	        if(!vis[j]){normaldfs(j,vis,revadj);}
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        //step 1 will be to store the nodes acc to their finishing time such that topmost element will be the one to finish last
        stack<int> s;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {   if(!vis[i]){
            dfs(i,vis,s,adj);
        }}
        for(int i=0;i<V;i++){vis[i]=0;}
        //step 2 will be to reverse the graph and remember that the graph is directed
        vector<vector<int>> revadj(V);
        for(int i=0;i<V;i++)
        {
            int node=i;
            for(auto j: adj[node])
            {
                revadj[j].push_back(node);
            }}
            //step 3 now dfs on revadj
            int c=0;
            while(!s.empty())
            {
                int topi=s.top();
                s.pop();
                if(!vis[topi]){
                    normaldfs(topi,vis,revadj);c=c+1;
                }
                }
                return c;
           
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends