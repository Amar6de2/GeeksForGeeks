//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<string> q;
        q.push(startWord);
        set<string> st(wordList.begin(),wordList.end());
        if(st.find(startWord)!=st.end())
        {
            st.erase(startWord);
        }
        int step=1;
        while(!q.empty())
        {
           int n=q.size();
           while(n--)
           {
               string fron=q.front();
               q.pop();
               if(fron==targetWord){return step;}
               int nf=fron.size();
               for(int i=0;i<nf;i++)
               {
                   char orig=fron[i];
                   for(char ch='a';ch<='z';ch++)
                   {
                       fron[i]=ch;
                       if(st.find(fron)!=st.end())
                       {
                           q.push(fron);
                           st.erase(fron);
                       }
                   }
                   fron[i]=orig;
               }
           }
           step++;
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends