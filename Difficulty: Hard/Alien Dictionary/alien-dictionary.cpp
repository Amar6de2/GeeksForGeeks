//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // Function to detect cycle and return topological sort if no cycle exists
    string findOrder(vector<string>& dict, int k) {
        // Step 1: Build the graph (adjacency list)
        vector<vector<int>> adj(k);
        for (int i = 1; i < dict.size(); i++) {
            string word1 = dict[i - 1], word2 = dict[i];
            int n1 = word1.size(), n2 = word2.size();
            int i1 = 0, i2 = 0;
            while (i1 < n1 && i2 < n2 && word1[i1] == word2[i2]) {
                i1++; i2++;
            }
            if (i1 < n1 && i2 < n2) {
                adj[word1[i1] - 'a'].push_back(word2[i2] - 'a');
            }
        }

        // Step 2: Perform topological sorting using Kahn's Algorithm (BFS approach)
        vector<int> indegree(k, 0);
        for (int i = 0; i < k; i++) {
            for (auto& node : adj[i]) {
                indegree[node]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        string topo;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            topo += (char)(curr + 'a');
            for (auto& neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Check if topological sort includes all nodes (cycle check)
        if (topo.size() != k) {
            return "";  // Cycle detected, invalid order
        }

        return topo;
    }
};


//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }
        int K;
        cin >> K;
        getchar();
        Solution obj;
        string ans = obj.findOrder(a, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[a.size()];
        std::copy(a.begin(), a.end(), temp);
        sort(temp, temp + a.size(), f);

        bool f = true;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != temp[i])
                f = false;

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends