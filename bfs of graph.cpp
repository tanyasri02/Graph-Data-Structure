#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
   
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int>ans;
	    vector<bool>vis(V,false);
	    
	    queue<int>q;
	    
	    q.push(0);
	    vis[0]=true;
	    
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        ans.push_back(temp);
	        
	        for(auto it:adj[temp])
	        {
	            if(vis[it]==false)
	            {
	                q.push(it);
	                vis[it]=true;
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
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  
