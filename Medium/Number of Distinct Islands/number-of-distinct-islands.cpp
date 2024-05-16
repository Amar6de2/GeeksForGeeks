//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include<bits/stdc++.h>
class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>> &grid,vector<pair<int,int>> &v,vector<vector<int>> &vis,int n,int m,int pari,int parj)
    {
        vis[i][j]=1;
        v.push_back({i-pari,j-parj});
        int di[]={-1,0,1,0};
        int dj[]={0,1,0,-1};
        for(int k=0;k<=3;k++)
        {
          int nr=i+di[k];
          int nc=j+dj[k];
          if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && !vis[nr][nc])
          {
              dfs(nr,nc,grid,v,vis,n,m,pari,parj);
          }
        }
        
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    vector<pair<int,int>> v;
                    dfs(i,j,grid,v,vis,n,m,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends