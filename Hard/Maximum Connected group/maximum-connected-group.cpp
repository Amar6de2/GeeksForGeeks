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
        size.resize(n);
        par.resize(n);
        for(int i=0;i<n;i++){size[i]=1;par[i]=i;}}
    int findpar(int node)
    {
        if(node==par[node]){return node;}
        return par[node]=findpar(par[node]);
    }
    void unionbysize(int u,int v)
    {
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
        if(ulp_u==ulp_v){return ;}
        if(size[ulp_u]<size[ulp_v]){par[ulp_u]=ulp_v;size[ulp_v]+=size[ulp_u];}
        else{par[ulp_v]=ulp_u;
             size[ulp_u]+=size[ulp_v];}
    }};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        disjoint d(n*n);
        int di[]={0,1,0,-1};
        int dj[]={1,0,-1,0};
        //first let us connect the "one" components
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {   int node=i*n+j;
                    for(int k=0;k<=3;k++)
                    {
                        int nr=i+di[k];
                        int nc=j+dj[k];
                        int newnode=nr*n+nc;
                        if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1 && d.findpar(node)!=d.findpar(newnode)){
                            d.unionbysize(node,newnode);
                        }
                    }}}}
                    int ans=0;
                    bool ekbhi0nahihai=true;
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            if(grid[i][j]==0)
                            {   ekbhi0nahihai=false;
                                int si=1;
                                unordered_map<int,int> m;
                                for(int k=0;k<=3;k++)
                                {   
                                    int nr=i+di[k];
                                    int nc=j+dj[k];
                                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1)
                                    {   int newnode=nr*n+nc;
                                        int ulp_newnode=d.findpar(newnode);
                                        if(m.find(ulp_newnode)==m.end())
                                        {
                                            m[ulp_newnode]=1;
                                            si+=d.size[ulp_newnode];
                                        }else{continue;}
                                    }
                                }
                                ans=max(ans,si);
                                
                            }
                        }
                    }
                    if(ekbhi0nahihai){return n*n;}
                    return ans;
                    
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends