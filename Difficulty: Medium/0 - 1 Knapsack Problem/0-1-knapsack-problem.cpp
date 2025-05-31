class Solution {
  public:
    int f(int i,int w,vector<int> &val,vector<int> &wt,int &n,vector<vector<int>> &dp)
    {
        if(i==n)
        {
            return dp[i][w]=0;
        }
        if(dp[i][w]!=-1){return dp[i][w];}
        
        int take=0,nottake=0;
        nottake+=f(i+1,w,val,wt,n,dp);
        if(w>=wt[i])
        {
            take=val[i]+f(i+1,w-wt[i],val,wt,n,dp);
        }
        return dp[i][w]=max(take,nottake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return f(0,W,val,wt,n,dp);
        
    }
};