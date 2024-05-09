//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int j,int arr[],vector<vector<int>> dp)
    {
        if(i==j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int mini=INT_MAX;// if i is greater than j hummein aisa case nahi chahiye...vaise oopar vala base case will make sure vaisi condition naa aaye
               for(int k=i;k<=j;k++)
        {
            int step=arr[i-1]*arr[k]*arr[j];
            step+=f(i,k,arr,dp)+f(k+1,j,arr,dp);
            mini=min(mini,step);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        //vector<vector<int>> dp1(N,vector<int>(N,-1));
        //return f(1,N-1,arr,dp);//here i will start from 1!...as i-1 array element will mutiply to give the operation intially
        //now tabulation:
        vector<vector<int>> dp(N,vector<int>(N,0));
        for(int i=N-1;i>=1;i--)
        {
            for(int j=i+1;j<N;j++)
            {   int mini=1e9;
                for(int k=i;k<j;k++)//note that i and j shall not become same acc to BASE CASE HENCE k<j
                {
                    int step=arr[i-1]*arr[k]*arr[j];
                    if(k+1<N)
                    {step+=dp[i][k]+dp[k+1][j];}
                    mini=min(mini,step);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][N-1];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends