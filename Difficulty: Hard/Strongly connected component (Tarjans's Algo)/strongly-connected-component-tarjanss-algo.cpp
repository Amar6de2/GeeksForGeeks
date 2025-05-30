class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto adjnode : adj[node]) {
            if (!vis[adjnode]) {
                dfs(adjnode, adj, vis, st);
            }
        }
        st.push(node);
    }

    void dfsCollect(int node, vector<int> adj[], vector<int> &vis, vector<int>& component) {
        vis[node] = 1;
        component.push_back(node);
        for (auto adjnode : adj[node]) {
            if (!vis[adjnode]) {
                dfsCollect(adjnode, adj, vis, component);
            }
        }
    }

    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        stack<int> st;
        vector<int> vis(V, 0);

        // 1st pass DFS to fill the stack
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // Reverse the graph
        vector<int> adjrev[V];
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjrev[it].push_back(i);
            }
        }

        // 2nd pass DFS on reversed graph
        fill(vis.begin(), vis.end(), 0);
        vector<vector<int>> ans;

        while (!st.empty()) {
            int topi = st.top();
            st.pop();
            if (!vis[topi]) {
                vector<int> component;
                dfsCollect(topi, adjrev, vis, component);
                sort(component.begin(), component.end());
                ans.push_back(component);
            }
        }

        // Optional: sort components based on their smallest member
        sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        return ans;
    }
};
