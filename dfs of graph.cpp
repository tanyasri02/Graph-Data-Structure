#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
	
   void DFSUtil (int i, vector <int> g[], int N, bool vis[], vector <int> &res)
    {
    if (vis[i]) return;
    vis[i] = true;
    res.push_back (i);
    
    for (int j : g[i])
    {
        if (!vis[j]) DFSUtil (j, g, N, vis, res);
    }
    }
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    bool vis[V];
	    memset(vis,false,sizeof(vis));
	    
	    vector<int>res;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==false)
	        DFSUtil(i,adj,V,vis,res);
	    }
	    return res;
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
    		adj[v].push_back(u);
    	}
      
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  
