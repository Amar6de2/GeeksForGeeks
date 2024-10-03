//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            string x=pat+'#'+txt;
            int l=0;
            int r=0;
            vector<int> Z(x.size());Z[0]=0;
            for(int k=1;k<x.size();k++)
            {
                if(k>r)
                {
                  l=r=k;
                  while(r<x.size() && x[r-l]==x[r]){r++;}
                  Z[k]=r-l;
                  r--;
                }
                else//k is between l and r
                {
                 int k1=k-l;        
                 if(k+Z[k1]<=r)
                 {
                     Z[k]=Z[k1];
                 }
                 else
                 {
                    l=k=r;
                    while(r<x.size() && x[r-l]==x[r]){r++;}
                    Z[k]=(r-l);
                    r--;
                 }
                }
            }
            vector<int> ans;
            for(int i=0;i<x.size();i++)
            {
                if(Z[i]==pat.size()){ans.push_back(i-Z[i]);}
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends