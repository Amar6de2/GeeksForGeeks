//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        int i = 0, j = n - 1;

        // Narrow down to one candidate
        while (i < j) {
            if (mat[i][j] == 1) {
                i++; // i knows j, so i can't be a celebrity
            } else {
                j--; // j knows i, so j can't be a celebrity
            }
        }

        // Candidate for celebrity
        int candidate = i;

        // Verify the candidate
        for (int k = 0; k < n; k++) {
            if (k != candidate) {
                if (mat[candidate][k] == 1 || mat[k][candidate] == 0) {
                    return -1; // Not a celebrity
                }
            }
        }

        return candidate;
    }
};
    

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends