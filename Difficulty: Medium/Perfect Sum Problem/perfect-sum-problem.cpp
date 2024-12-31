//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp)
    {   
        if(ind==0)
        {
            if( (!arr[ind]) && (!target) ){return 2;}
            if(target==0){return 1;}//nottake
            return (arr[ind]==target);
        }
        if(dp[ind][target]!=-1){return dp[ind][target];}
        int take=0,nottake=0;
        nottake+=f(ind-1,target,arr,dp);
        if(target>=arr[ind])
        {
            take+=f(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target]=(take+nottake);
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return f(n-1,target,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends