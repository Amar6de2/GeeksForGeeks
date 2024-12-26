//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        //LPS is made for pattern!
        int m=pat.size();
        vector<int> LPS(m,0);
        int j=1;
        int len=0;
        while(j<m)
        {
            if(pat[j]==pat[len])
            {
                len++;
                LPS[j]=len;j++;
            }
            else
            {
                if(!len)
                {
                    LPS[j]=0;j++;
                }
                else
                {
                    len=LPS[len-1];
                }
            }
        }
        vector<int> ans;
        int i=0;
          j=0;
        int n=txt.size();
        while(i<n)
        {
            if(txt[i]==pat[j])
            {
                i++;
                j++;
                if(j==m){ans.push_back(i-m);
                         j=LPS[j-1];
                }
            }
            else
            {
                if(!j)
                {
                    i++;
                }
                else
                {
                    j=LPS[j-1];
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends