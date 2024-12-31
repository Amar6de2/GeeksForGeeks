//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int f(int ind, int sum, int &n, vector<int> &nums, vector<vector<int>> &dp) {
        if (sum < 0) return 0; // No valid subset
        if (ind == 0) {
            if (sum == 0 && nums[ind] == 0) return 2; // Two ways: include/exclude zero
            if (sum == 0) return 1; // Not taking anything
            return nums[ind] == sum; // Taking the element if it matches
        }
        if (dp[ind][sum] != -1) return dp[ind][sum];
        int nottake = f(ind - 1, sum, n, nums, dp);
        int take = (sum >= nums[ind]) ? f(ind - 1, sum - nums[ind], n, nums, dp) : 0;
        return dp[ind][sum] = take + nottake;
    }

    void fillDP(vector<vector<int>> &dp, vector<int> &nums, int &sum) {
        int n = nums.size();
        f(n - 1, sum, n, nums, dp);  // Fill the DP table for the target sum
    }

    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = 0;
        for (auto num : arr) sum += num;

        // Edge case: Partition not possible
        if ((sum + d) % 2 != 0 || sum < d) return 0;
        int target = (sum + d) / 2; // Target sum for one subset

        // Initialize DP table
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        fillDP(dp, arr, target);  // Fill DP table for subset sum problem

        int ans = 0;

        // Traverse the last row of DP table
        for (int i = 0; i <= target; i++) {
            int s1 = i;
            int s2 = sum - s1;
            // Check if the difference condition holds: s1 - s2 == d
            if (s1 - s2 == d && dp[n - 1][s1] != -1) {
                ans += dp[n - 1][s1];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends