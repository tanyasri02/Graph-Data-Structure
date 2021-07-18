#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
        int m=grid[0].size();
        
        int arr[n+1][m+1];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j]=INT_MAX;
            }
        }
        
        queue<pair<int,int>>rotton;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    rotton.push(make_pair(i,j));
                    arr[i][j]=0;
                }
            }
        }
        
        
        while(!rotton.empty())
        {
            int x=rotton.front().first;
            int y=rotton.front().second;
            
            rotton.pop();
            
            queue<pair<int,int>>q;
            
            q.push(make_pair(x,y));
            
            while(!q.empty())
            {
                x=q.front().first;
                y=q.front().second;
                
                q.pop();
                
                if(x>0 && arr[x-1][y]>arr[x][y]+1 && grid[x-1][y]!=0)
                {
                    arr[x-1][y]=arr[x][y]+1;
                     q.push(make_pair(x-1,y));
                }
                if(y>0 && arr[x][y-1]>arr[x][y]+1 && grid[x][y-1]!=0)
                {
                    arr[x][y-1]=arr[x][y]+1;
                     q.push(make_pair(x,y-1));
                }
                if(x<n-1 && arr[x+1][y]>arr[x][y]+1 && grid[x+1][y]!=0)
                {
                    arr[x+1][y]=arr[x][y]+1;
                    q.push(make_pair(x+1,y));
                }
                if(y<m-1 && arr[x][y+1]>arr[x][y]+1 && grid[x][y+1]!=0)
                {
                    arr[x][y+1]=arr[x][y]+1;
                     q.push(make_pair(x,y+1));
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    if(arr[i][j]==INT_MAX)
                        return -1;
                    ans=max(ans,arr[i][j]);
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
} 
