//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    class compare{public:
         bool operator()(vector<int> &a,vector<int> &b)
         {
             return a[1]<b[1];
         }
    };
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<vector<int>> meet;
        for(int i=0;i<start.size();i++)
        {
            meet.push_back({start[i],end[i]});
        }
        sort(meet.begin(),meet.end(),compare());
        int ans=0;
        int last=-1;
        for(auto it: meet)
        {
            int s=it[0];
            int e=it[1];
            if(s>last)
            {
                ans++;
                last=e;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends