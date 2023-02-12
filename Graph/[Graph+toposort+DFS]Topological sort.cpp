void dfs(int v,vector<int> adj[],stack<int> &s,vector<int>&visit,int k){
	    visit[k]=1;
	    for(int j=0;j<adj[k].size();j++){
	        if(visit[adj[k][j]]==-1){
	           dfs(v,adj,s,visit,adj[k][j]);
	        }
	    }
	    s.push(k);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visit(V,-1);
	    stack<int> s;
	    for(int i=0;i<V;i++){
	        if(visit[i]==-1){
	            dfs(V,adj,s,visit,i);
	        }
	    }
	    vector<int> res;
	    while(s.size()){
	        res.push_back(s.top());
	        s.pop();
	    }
	    return res;
	}
