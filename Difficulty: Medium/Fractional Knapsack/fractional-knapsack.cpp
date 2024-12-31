//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
class compare{public:
    bool operator()(vector<int> &a,vector<int> &b)
    {
        double num1=a[0];//val/wt must be high
        double den1=a[1];
        double frac1=num1/den1;
        double num2=b[0];
        double den2=b[1];
        double frac2=num2/den2;
        return frac1>frac2;
    }
    
};
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        vector<vector<int>> data;
        for(int i=0;i<val.size();i++)
        {
            data.push_back({val[i],wt[i]});
        }
        sort(data.begin(),data.end(),compare());
        double ans=0;
        for(auto it: data)
        {
            int v=it[0];
            int w=it[1];
            if(!capacity){break;}
            else if(capacity>=w)
            {
                ans+=v;
                capacity-=w;
            }
            else
            {
                double num=v;
                double den=w;
                double frac=num/den;
                double add=frac*((double) (capacity));
                ans+=add;
                capacity=0;
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends