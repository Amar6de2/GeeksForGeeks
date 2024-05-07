//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0;i<n;i++){hash[i]=i;}
        int maxlen=1;int lastindex=0;
        //dp[i] will give the max length of IS provided the arr[i] is included in the subsequence
        //hash[i] will give the index of penulitmate element present in that particular IS
        for(int ind=0;ind<n;ind++)
        {
            for(int i=0;i<=ind-1;i++)
            {
                if(arr[ind]>arr[i] && 1+dp[i]>dp[ind])//if arr[ind]>arr[i],then it needs to be included and the second condition is to check whether the dp[ind] gets updated or not as it is possible that even if arr[ind]>arr[i], the dp[ind] will not update as it is already equal to or greater than that dp[i]
                {
                    dp[ind]=1+dp[i];
                    hash[ind]=i;
                }
            }
            if(dp[ind]>maxlen)
            {maxlen=dp[ind];
             lastindex=ind;}
            
        }
        vector<int> ans(maxlen,0);
        ans[0]=arr[lastindex];
        int ain=0;
        while(hash[lastindex]!=lastindex)
        {
            ans[ain++]=arr[lastindex];
            lastindex=hash[lastindex];
            }
            ans[maxlen-1]=arr[lastindex];
            
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends