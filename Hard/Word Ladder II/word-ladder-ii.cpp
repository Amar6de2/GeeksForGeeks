//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord); int size=1e9;
        queue<vector<string>> q;vector<vector<string>> ans;
        q.push({beginWord});
        while(!q.empty())
        {
            int n=q.size();
            set<string> tobedeleted;
            for(int i=0;i<n;i++)
            {   
                vector<string> vec=q.front();
                q.pop();
                string end=vec.back();
                if(end==endWord)
                {   ans.push_back(vec);
                    while(!q.empty())
                    {   
                        vector<string> vec2=q.front();q.pop();
                        string end=vec2.back();
                        if((end==endWord) && size>=vec.size())
                        {
                            ans.push_back(vec2);
                            size=vec.size();
                        }
                    }
                    return ans;
                }
                int send=end.size();//size of ending string
                for(int j=0;j<send;j++)
                {
                    char c=end[j];//original
                    for(char ch='a';ch<='z';ch++)
                    {
                        end[j]=ch;
                        if(st.find(end)!=st.end())
                        {
                            tobedeleted.insert(end);
                            vec.push_back(end);
                            q.push(vec);
                            vec.pop_back();
                        }
                        end[j]=c;
                       
                    }
                }
            }
            for(auto s: tobedeleted)
            {
                st.erase(s);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends