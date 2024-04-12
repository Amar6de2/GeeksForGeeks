//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    vector<int> prev(V+1,0);
	    vector<int> curr(V+1,0);
	    for(int i=0;i<=V;i++)
	    {
	        if(i%coins[0]==0){prev[i]=i/coins[0];}
	        else{prev[i]=1e9;}
	    }
	    for(int ind=1;ind<M;ind++)
	    {
	        for(int t=0;t<=V;t++)//it is imprtant to start t from 0!
	        {
	            int nottake=prev[t];
	            int take=INT_MAX;
	            if(t>=coins[ind]){take=1+curr[t-coins[ind]];}
	            curr[t]=min(take,nottake);
	        }
	        prev=curr;
	    }
	    if(prev[V]<1e8)
	    {return prev[V];}
	    return -1;
	    
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends