 bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>indegree(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(q.size()){
            int curr=q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[curr].size();i++){
                if(--indegree[adj[curr][i]]==0){
                    q.push(adj[curr][i]);
                }
            }
        }
        if(count==n) {return true;}
        else {return false;}
    }
