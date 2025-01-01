//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int f(int mid,vector<vector<int>> &mat)
    {
        
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin());
        }
        return ans;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int s=1e9;
        int e=-1e9;
        int n=mat.size();
        int m=mat[0].size();
        int totele=m*n;
        int halfele=totele/2;
        for(int i=0;i<n;i++)
        {
            s=min(s,mat[i][0]);
            e=max(e,mat[i][m-1]);
        }
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            int numbehindmid=f(mid,mat);
            if(numbehindmid>halfele)
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends