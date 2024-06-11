//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int> ans;
            int m=pat.size();
            vector<int> LPS(m,0);
           int len=0;int j=1;
            while(j<m)
            {
                if(pat[len]==pat[j])
                {
                    len++;
                    LPS[j]=len;j++;
                }
                else
                {   if(len==0)
                {
                    LPS[j]=0;j++;
                }
                else{
                    len=LPS[len-1];
                }
                    
                }
            }
            int i=0;
            j=0;
            while(i<txt.size())
            {
                if(pat[j]==txt[i])
                {
                    i++;j++;
                }
                else if(pat[j]!=txt[i])
                {   if(j!=0)
                    {j=0+LPS[j-1];}
                    else{i++;}
                }
                if(j==m)
                {
                    ans.push_back(i-m+1);
                    j=LPS[j-1];
                }
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
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends