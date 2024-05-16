//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {   
            if(grid[i][0]==1){q.push({i,0});}
            if(grid[i][m-1]==1){q.push({i,m-1});}
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1){q.push({0,i});}
            if(grid[n-1][i]==1){q.push({n-1,i});}
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            vis[r][c]=1;
            q.pop();
            int di[]={-1,0,1,0};
            int dj[]={0,1,0,-1};
            for(int k=0;k<=3;k++)
            {
                int nr=r+di[k];
                int nc=c+dj[k];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
                {   q.push({nr,nc});
                    
                    grid[nr][nc]=0;
                }
            }
            
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && i!=0 && j!=0 && i!=n-1 && j!=m-1){c++;}
            }
        }
        return c;
        
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends