//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int f(int i,int prevsum,string &str,vector<vector<int>> &dp)
	{
	    if(i==0){return dp[i][prevsum]=1;}
	    int s=0;
	    if(dp[i][prevsum]!=-1){return dp[i][prevsum];}
	    long long int ans=0;
	    for(int j=i;j>=1;j--)
	    {
	        s+=str[j-1]-'0';
	        if(s<=prevsum)
	        {
	           ans+=f(j-1,s,str,dp); 
	        }
	    }
	    return dp[i][prevsum]=ans;
	}
	int TotalCount(string str){
	    // Code here
	    int sum=0;
	    for(int i=0;i<str.size();i++)
	    {
	        sum+=str[i]-'0';
	    }
	    int n=str.size();
	   vector<vector<int>> dp(n+1,vector<int>(sum+2,-1));
	    return f(n,sum+1,str,dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends