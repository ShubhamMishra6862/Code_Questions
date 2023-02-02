//the queue operation was increasing time complexity but recursion doesn't increase its time complexity in leetcode?
vector<int> dx{1,-1,0,0},dy{0,0,-1,1};
    int count=0;
    void track(vector<vector<char>>&grid,int x,int y,int n,int m){
         for(int k=0;k<dx.size();k++){
             if((x+dx[k])<0 || (x+dx[k])>=m || (y+dy[k])<0 || (y+dy[k])>=n){
                 continue;
             }
             if(grid[x+dx[k]][y+dy[k]]=='2' || grid[x+dx[k]][y+dy[k]]=='0'){
                 continue;
             } 
             grid[x+dx[k]][y+dy[k]]='2';
             track(grid,(x+dx[k]),(y+dy[k]),n,m);
         }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid[0].size(),m=grid.size();
        
        // vector<vector<int>> visit(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='2' || grid[i][j]=='0'){
                    continue;
                }
                // queue<pair<int,int>>q;
                // q.push({i,j});
                grid[i][j]='2';
                count++;
                track(grid,i,j,n,m);
                // while(q.size()){
                //     int x=q.front().first,y=q.front().second;
                    
                // }
            }
            
        }
        return count;
    }
