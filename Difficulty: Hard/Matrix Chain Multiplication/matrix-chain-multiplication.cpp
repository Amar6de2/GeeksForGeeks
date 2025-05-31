class Solution {
  public:
    long long int f(int i,int j,vector<int> &arr,vector<vector<int>> &dp)
    {   
        if(i>=j){return  dp[i][j]=0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        long long int ans=1e9;
        for(int k=i;k<j;k++) // k is the partition and i and j vaale multiply hone hii vaale haii!
        {
            long long int a=arr[i-1]*arr[k]*arr[j];
            a+=f(i,k,arr,dp)+f(k+1,j,arr,dp);
            ans=min(ans,a);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(1,n-1,arr,dp);
    }
};