class Solution {
  public:
    int distinctSubsequences(string s) {
        // code  here
           int mod=(1e9+7);
        int n=s.size();
        vector<long long int> dp(n+1);
        dp[0]=1;// assuming that the number of subsequence with len =0 =1
        unordered_map<char,int> mp;
        for(int i=1;i<=n;i++)
        {
           
            dp[i]=(2*dp[i-1]);
            dp[i]=(dp[i]+mod)%mod;
            if(mp.find(s[i-1])!=mp.end() && mp[s[i-1]]>0 )
            {  
                dp[i]=dp[i]-dp[mp[s[i-1]]-1];
                dp[i]=(dp[i]+mod)%mod;
            }
            mp[s[i-1]]=i;
        }
        return (dp[n]+mod)%mod;
    }
};