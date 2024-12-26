//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int ans=1;
        int i=1;
        int n=arr.size();
        while(i<n)
        {
            if(arr[i]==arr[i-1]){ans+=1; i++; continue;}
            int up=1;
            while(i<n && arr[i]>arr[i-1])
            { up++;
             ans+=up;i++;
            }
            int down=1;
            while(i<n && arr[i-1]>arr[i])
            {
               ans+=down;
               down++;i++;
            }
            if(down>up)
            {
                ans+=(down-up);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr = inputLine();

        Solution obj;
        cout << obj.minCandy(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends