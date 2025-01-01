//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool cancolor(int node,int color,vector<int> &col,vector<vector<int>> &adj)
    {
        for(auto adjnode: adj[node])
        {
            if(col[adjnode]==color){return false;}
        }
        return true;
    }
    bool f( vector<vector<int>> &adj,int node, int &v, vector<int> col,int &m)
    {
        if(node==v){return true;}
        bool ans=false;
        for(int color=1;color<=m;color++)
        {
            if(cancolor(node,color,col,adj))
            {
                col[node]=color;
                ans |=f(adj,node+1,v,col,m);
                if(ans){return true;}
                col[node]=-1;
            }
        }
        return ans;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        for(auto it: edges)
        {
            int u=it.first;
            int v=it.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> col(v,-1);
        return f(adj,0,v,col,m);
        //we  are t performing dfs her !!
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends