//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
     int f(int i, int j, int freq[], vector<vector<int>> &dp, vector<int> &freqSum) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k = i; k <= j; k++) {
            int cost = (freqSum[j + 1] - freqSum[i]) + 
                       f(i, k - 1, freq, dp, freqSum) + 
                       f(k + 1, j, freq, dp, freqSum);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
         vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> freqSum(n + 1, 0);

        // Precompute cumulative frequencies
        for (int i = 0; i < n; i++) {
            freqSum[i + 1] = freqSum[i] + freq[i];
        }

        return f(0, n - 1, freq, dp, freqSum);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends