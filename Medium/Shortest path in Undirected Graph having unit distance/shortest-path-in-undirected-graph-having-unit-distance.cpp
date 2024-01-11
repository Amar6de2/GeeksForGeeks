//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        unordered_map<int,list<int>> adj;
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(N,1e9);
        queue<int> q;
        q.push(src);
        ans[src]=0;
        while(!q.empty())
        {
            int fron=q.front();
            q.pop();
            for(auto n:adj[fron])
            {
                if(ans[fron]+1< ans[n])
                {
                    ans[n]=ans[fron]+1;
                    q.push(n);
                }
            }
        }
        for(int b=0;b<N;b++)
        {
            if(ans[b]==1e9){ans[b]=-1;}
        }
        
        return ans;
        
        
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends