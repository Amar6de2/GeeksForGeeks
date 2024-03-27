//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



#include<bits/stdc++.h>
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    for(int i=0;i<P;i++)
	    {
	        int u=prerequisites[i].first;
	        int v=prerequisites[i].second;
	        adj[u].push_back(v);
	    }
	    vector<int> indeg(N,0);
	    for(int i=0;i<N;i++)
	    {
	        for(auto k:adj[i])
	        {
	            indeg[k]++;
	        }
	    }
	    vector<int> ans;
	    queue<int> q;
	    for(int i=0;i<N;i++)
	    {
	        if(indeg[i]==0){q.push(i);}
	    }
	    while(!q.empty())
	    {
	        int fronti=q.front();q.pop();ans.push_back(fronti);
	        for(auto k: adj[fronti])
	        {
	            indeg[k]--;
	            if(indeg[k]==0){q.push(k);}
	        }
	        
	    }
	    if(ans.size()==N){return true;}
	    return false;}
	    
	    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends