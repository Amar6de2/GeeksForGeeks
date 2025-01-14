//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DSU{public:
      vector<int> par;
      vector<int> size;
      DSU(int n)
      {
          par.resize(n);
          size.resize(n);
          for(int i=0;i<n;i++)
          {
              par[i]=i;
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
          if(size[ulp_u]>size[ulp_v])
          {
              par[ulp_v]=ulp_u;
              size[ulp_u]+=size[ulp_v];
          }
          else
          {
              par[ulp_u]=ulp_v;
              size[ulp_v]+=size[ulp_u];
          }
      }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DSU obj(n*m+1);
        int isl=0;
        vector<int> ans;
        int di[]={0,0,1,-1};
        int dj[]={1,-1,0,0};
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(auto it: operators)
        {
            int r=it[0];
            int c=it[1];
            if(!vis[r][c]){vis[r][c]=1;isl++;}
         
            int block=r*m+c;
            for(int k=0;k<=3;k++)
            {
                int nr=r+di[k];
                int nc=c+dj[k];
                int nearblock=nr*m+nc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc] && obj.findpar(block)!=obj.findpar(nearblock))
                {
                    isl--;
                    obj.unionbysize(block,nearblock);
                }
            }
            ans.push_back(isl);
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
    
cout << "~" << "\n";
}
}

// } Driver Code Ends