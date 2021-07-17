#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<pair<int,int>> adj[])
    {
        // code here
        int ans=0;
        int parent[V],key[V];
        bool mstset[V]={false};
        
        for(int i=0;i<V;i++)
        {
            key[i]=INT_MAX;
            mstset[i]=false;
        }
        
        parent[0]=-1;
        key[0]=0;
        
        for(int i=0;i<V-1;i++)
        {
            int mini=INT_MAX,u;
            for(int v=0;v<V;v++)
            {
                if(mstset[v]==false && key[v]<mini)
                {
                    mini=key[v];
                    u=v;
                }
            }
            mstset[u]=true;
            
            for(auto it:adj[u])
            {
                int v=it.first;
                int wt=it.second;
                
                if(mstset[v]==false && wt<key[v])
                {
                    parent[v]=u;
                    key[v]=wt;
                }
            }
        }
        
        for(int i=1;i<V;i++)
        {
            ans+=key[i];
            cout<<parent[i]<<"-> "<<i<<" "<<key[i]<<endl;
        }
        
        return ans;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>adj[V];
        int i=0;
        while (i++<E) {
            int u, v, wt;
            cin >> u >> v >> wt;
            adj[u].push_back(make_pair(v,wt));
            adj[v].push_back(make_pair(u,wt));
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
