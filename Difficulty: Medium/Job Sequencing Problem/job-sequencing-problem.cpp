//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    class P{public:
    int id;
    int deadline;
    int profit;
    P(int id,int deadline,int profit)
    {
        this->id=id;
        this->profit=profit;
        this->deadline=deadline;
    }
    };
    class compare{public:
      bool operator()(P a,P b)
      {
          return a.profit>b.profit;
      }
    };
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        vector<P> data;
        int maxd=1;
        for(int i=0;i<id.size();i++)
        {
            P obj(id[i],deadline[i],profit[i]);
            data.push_back(obj);
            maxd=max(maxd,deadline[i]);
        }
        sort(data.begin(),data.end(),compare());
        vector<int> day(maxd+1,-1);
        for(auto it: data)
        {
            int i=it.id;
            int d=it.deadline;//day hii represent karta hai
            int p=it.profit;
            while(d>=1)
            {
                if(day[d]==-1)
                {
                   day[d]=p;
                   break;
                }
                else
                {
                    d--;
                }
            }}
            int profi=0;
            int jobdone=0;
            for(int i=1;i<day.size();i++)
            {
                if(day[i]!=-1)
                {
                    jobdone++;
                    profi+=day[i];
                }
            }
            return {jobdone,profi};
        
        
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends