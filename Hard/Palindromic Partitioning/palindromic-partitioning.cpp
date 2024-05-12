//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool ispalindrome(int i,int j,string s)
    {
        int n=s.size();
        if(i==j){return true;}
        
        while(i<j)
        {
            if(s[i++]!=s[j--])
            {return false;}
        }
        return true;
    }
    int f(int i,string str,int n,vector<int> dp)
    {
        if(i==n){return 0;}
        if(dp[i]!=-1){return dp[i];}
        int mini=1e9;
        for(int ind=i;ind<n;ind++)
        {
            int way=1e9;
            if(ispalindrome(i,ind,str))
            {
                way=1+f(ind+1,str,n,dp);
            }
            mini=min(mini,way);
        }
        return dp[i]=mini;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        //return f(0,str,n,dp)-1;
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            int mini=1e9;
            for(int ind=i;ind<n;ind++)
            {
                int way=1e9;
                if(ispalindrome(i,ind,str))
                {   if(ind+1<=n)
                    {way=1+dp[ind+1];}
                }
                mini=min(mini,way);
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends