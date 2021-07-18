class Solution {
public:
    int count=1;
   int dfs(vector<vector<int>>& grid,int r,int c)
    {
        if(c<0 || r<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==0)
            return 0;
        count=1;
        grid[r][c]=0;
        return 1+dfs(grid,r-1,c)+dfs(grid,r,c-1)+dfs(grid,r+1,c)+dfs(grid,r,c+1);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};
