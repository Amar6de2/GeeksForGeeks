//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include<vector>
#include<stack>
class Solution {
  public:
     void dfs(int node,stack<int> &s,vector<vector<pair<int,int>>> adj, int vis[])
     {
         vis[node]=1;
         for(auto n:adj[node])
         {int v=n.first;
             if(vis[v]!=1){dfs(v,s,adj,vis);}}
             
         s.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        //making an adj list
        vector<vector<pair<int,int>>> adj(N);
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            pair<int,int> a;a.first=v;a.second=wt;
            adj[u].push_back(a);
        }
        //topological sort
        stack<int> s;
        int vis[N]={0};
        for(int j=0;j<N;j++)
        {
            if(vis[j]==0)
            {dfs(j,s,adj,vis);}
        }
        //now dist
        vector<int> dist(N);
        for(int l=0;l<N;l++){dist[l]=1e9;}
        dist[0]=0;
        while(!s.empty())
        {
            int fron=s.top();
            s.pop();
            
           for(auto v:adj[fron])
           {
               int m=v.first;
               int wt=v.second;
               if(dist[fron]+wt<dist[m])
               {dist[m]=dist[fron]+wt;}
            
           }
            
        }
        for(int h=0;h<N;h++)
        {if(dist[h]==1e9){dist[h]=-1;}}
        return dist;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends