//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long int f(int ind,int prevind,vector<int> &arr,vector<vector<int>> &dp)
    {
       if(ind==arr.size()+1)
       {
           return 0;
       }
       if(dp[ind][prevind]!=-1)
       {return dp[ind][prevind];}
       long long int ans=-1e9;
       if((prevind==0) || (arr[ind-1]>arr[prevind-1]) )
       {
           int nottpick=0+f(ind+1,prevind,arr,dp);
           int pick=arr[ind-1]+f(ind+1,ind,arr,dp);
           ans=max(pick,nottpick);
       }
       else
       {
           ans=0+f(ind+1,prevind,arr,dp);
       }
       return dp[ind][prevind]=ans;
    }
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(1,0,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends