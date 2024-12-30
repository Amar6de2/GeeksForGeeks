//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        map<int,int> m;//( number -> freq )
        m[0]=-1;
        int i=0;
        int n=arr.size();
        long long int sum=0;
        int ans=0;
        while(i<n)
        {
            sum+=arr[i];
            int search=sum;
            if(m.find(search)!=m.end())
            {
                ans=max(ans,(i-m[search]));
            }
            
            if(m.find(sum)==m.end())
            {
                m[sum]=i;
            }
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends