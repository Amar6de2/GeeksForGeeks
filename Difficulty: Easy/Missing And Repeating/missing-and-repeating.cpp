//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long int s1=0;
        long long int s2=0;
        long long int s1sq=0;
        long long int s2sq=0;
        int n=arr.size();
        for(auto it: arr)
        {
            s2+=it;
            s2sq+=(it*it);
        }
        for(int i=1;i<=n;i++)
        {
            s1+=i;
            s1sq+=(i*i);
        }
        long long int k1=(s2-s1);
        long long int k2=(s2sq-s1sq);
        k2=k2/k1;
        long long int x=(k1+k2)/2;
        long long int y=(k2-k1)/2;
        return {x,y};
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
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends