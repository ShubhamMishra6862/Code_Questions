#Leetcode question Reorder routes to make all path lead to city zero

class Solution {
public:
    int count=0;
    void dfs(int node,int parent,vector<vector<pair<int,int>>> &adj){
        for(auto i:adj[node]){
            if(i.first!=parent){
                count+=i.second;
                dfs(i.first,node,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        count=0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto & i:connections){
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],0});
        }
        for(int i=0;i<n;i++)
        {
            cout<<i<<": ";
            for(int j=0;j<adj[i].size();j++){
                cout<<"{"<<adj[i][j].first<<","<<adj[i][j].second<<"} ";
            }
            cout<<endl;
        }
        dfs(0,-1,adj);
        return count;
    }
};
