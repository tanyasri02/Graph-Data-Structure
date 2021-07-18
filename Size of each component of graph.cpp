#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	int c;
	int DFSUtil (int i, vector <int> g[], int N, bool vis[])
   {
   
    vis[i] = true;
    c=1;
    for (int j : g[i])
    {
        if (!vis[j]) 
        {
            c+=DFSUtil (j, g, N, vis);
        }
    }
    return c;
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
	        {
	            int count=DFSUtil(i,adj,V,vis);
	            res.push_back(count);
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
