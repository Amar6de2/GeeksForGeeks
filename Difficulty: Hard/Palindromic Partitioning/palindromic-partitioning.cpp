//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool ispal(int s,int e,string &si)
    {
        while(e>s)
        {
            if(si[s]!=si[e]){return false;}
            e--;s++;
        }
        return true;
    }
    int func(int i,string &s,vector<int> &dp)
    {   if(i==s.size()){return dp[i]=0;}
        if(dp[i]!=-1){return dp[i];}
        int mini=INT_MAX;
        for(int j=i;j<s.size();j++)
        {
            if(ispal(i,j,s))
            {
                int p=1+func(j+1,s,dp);
                mini=min(mini,p);
            }
        }
        return dp[i]=mini;
    }
    int palindromicPartition(string &s) {
        // code here
        int n=s.size();
        vector<int> dp(n+1,-1);
        return func(0,s,dp)-1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends