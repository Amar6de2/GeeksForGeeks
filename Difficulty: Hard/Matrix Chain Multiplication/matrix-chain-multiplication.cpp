//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int s,int e,vector<int> &arr,vector<vector<int>> &dp)
    {   if(s>=e){return dp[s][e]=0;}
        if(dp[s][e]!=-1){return dp[s][e];}
        int mini=1e9;
        for(int k=s;k<e;k++)
        {
            int step=arr[s-1]*arr[k]*arr[e];
            step+=f(s,k,arr,dp)+f(k+1,e,arr,dp);
            mini=min(mini,step);
        }
        return dp[s][e]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(1,n-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends