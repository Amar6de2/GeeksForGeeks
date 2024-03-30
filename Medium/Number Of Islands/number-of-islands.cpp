//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class disjoint{public:
    vector<int> size,par;
    disjoint(int n)
    {
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++)
        {par[i]=i;
         size[i]=1;    
        }
    }
    int findpar(int node)
    {
        if(node==par[node]){return node;}
        return par[node]=findpar(par[node]);
    }
    void unionbysize(int u,int v)
    {
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
        if(ulp_u==ulp_v){return;}
        if(size[ulp_u]<size[ulp_v]){par[ulp_u]=ulp_v;
                                    size[ulp_v]+=size[ulp_u];}
        else{par[ulp_v]=ulp_u;
             size[ulp_u]+=size[ulp_v];}
    }};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> ans;
        int di[]={0,1,0,-1};
        int dj[]={1,0,-1,0};
        int isl=0;
        int l=n*m;
        disjoint d(l);
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<operators.size();i++)
        {
            int r=operators[i][0];
            int c=operators[i][1];
            int node=r*m+c;
            if(vis[r][c]!=1){vis[r][c]=1;isl++;}
            for(int k=0;k<4;k++)
            {
                int nr=r+di[k];
                int nc=c+dj[k];
                int newnode=nr*m+nc;
                if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==1 && d.findpar(node)!=d.findpar(newnode))
                {
                    d.unionbysize(node,newnode);
                    isl--;
                }
            }
            if(isl!=0)
            {ans.push_back(isl);}
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends