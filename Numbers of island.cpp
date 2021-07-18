#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
   void dfs(vector<vector<char>>& grid,int r,int c)
    {
        if(c<0 || r<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]=='0')
            return;
        grid[r][c]='0';
        dfs(grid,r-1,c);
        dfs(grid,r,c-1);
        dfs(grid,r+1,c);
        dfs(grid,r,c+1);
        dfs(grid,r+1,c+1);
        dfs(grid,r-1,c-1); 
        dfs(grid,r-1,c+1);
        dfs(grid,r+1,c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  
