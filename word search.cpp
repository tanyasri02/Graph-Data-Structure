#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
 bool dfs(vector<vector<char>>& board,int i,int j,string word,int count) {
        if(count == word.size())
            return true;
        if(i<0 || j<0 || i>=board.size()|| j>=board[i].size() ||board[i][j] != word[count])
            return false;
        char temp = board[i][j];
        board[i][j]= ' ';
        bool found = dfs(board,i+1,j,word,count+1) || dfs(board,i-1,j,word,count+1) ||
                     dfs(board,i,j+1,word,count+1) || dfs(board,i,j-1,word,count+1);
        board[i][j] = temp;
        return found;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j]== word[0] && dfs(board,i,j,word,0)){
                    return true;
                }
            }
        }
         return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
