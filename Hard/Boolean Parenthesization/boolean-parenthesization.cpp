//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include<bits/stdc++.h>
int mod=1003;
class Solution{
public:
    int f(int i,int j,string s,bool istrue,vector<vector<vector<long long int>>> dp)
    {
        if(i>j){return 0;}
        if(i==j){if(istrue){return s[i]=='T';}
                 else{return s[j]=='F';}}
                 if(dp[i][j][istrue]!=-1){return dp[i][j][istrue];}
                 long long int ways=0;
        for(int ind=i+1;ind<j;ind+=2)
        {
            long long int  lt=f(i,ind-1,s,true,dp);
            long long int lf=f(i,ind-1,s,false,dp);
            long long int rt=f(ind+1,j,s,true,dp);
            long long int rf=f(ind+1,j,s,false,dp);
            if(s[ind]=='|')
            {   if(istrue)
                {ways=(ways+(rt*lt)%mod+(rt*lf)%mod+(rf*lt)%mod)%mod;}
                else{ways=(ways+(rf*lf)%mod)%mod;}
            }
            else if(s[ind]=='&')
            {
                if(istrue){ways=(ways+(rt*lt)%mod)%mod;}
                else{ways=(ways+(rf*lf)%mod+(rf*lt)%mod+(rt*lf)%mod)%mod;}
            }
            else if(s[ind]=='^')
            {
                if(istrue){ways=(ways+(rt*lf)%mod+(rf*lt)%mod)%mod;}
                else{ways=(ways+(rt*lt)%mod+(rf*lf)%mod)%mod;}
            }
        }
    return dp[i][j][istrue]=ways;
    }
    int countWays(int n, string s){
        // code here
        vector<vector<vector<long long int>>> dp(n,vector<vector<long long int>>(n,vector<long long int>(2,0)));
        //return f(0,n-1,s,true,dp);
        //base case for tabulation:
        for(int i=0;i<n;i++)
        {
            dp[i][i][0]=(s[i]=='F');
            dp[i][i][1]=(s[i]=='T');
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int istrue=0;istrue<=1;istrue++)
                {
                    long long int ways=0;
                    for(int ind=i+1;ind<j;ind+=2)
                    {
                        long long int lt=dp[i][ind-1][1];
                        long long int lf=dp[i][ind-1][0];
                        long long int rt=dp[ind+1][j][1];
                        long long int rf=dp[ind+1][j][0];
                         if(s[ind]=='|')
            {   if(istrue)
                {ways=(ways+(rt*lt)%mod+(rt*lf)%mod+(rf*lt)%mod)%mod;}
                else{ways=(ways+(rf*lf)%mod)%mod;}
            }
            else if(s[ind]=='&')
            {
                if(istrue){ways=(ways+(rt*lt)%mod)%mod;}
                else{ways=(ways+(rf*lf)%mod+(rf*lt)%mod+(rt*lf)%mod)%mod;}
            }
            else if(s[ind]=='^')
            {
                if(istrue){ways=(ways+(rt*lf)%mod+(rf*lt)%mod)%mod;}
                else{ways=(ways+(rt*lt)%mod+(rf*lf)%mod)%mod;}
            }
                       
                    }
                    dp[i][j][istrue]=ways;
                }
            }
        }
        return dp[0][n-1][1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends