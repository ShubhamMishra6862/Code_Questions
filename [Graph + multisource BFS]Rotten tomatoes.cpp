 vector<int> dx{1,-1,0,0},dy{0,0,1,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int count1s=0;
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    count1s++;
                }
            }
        }
        cout<<q.empty()<<endl;
        if(count1s==0){
            return 0;
        }
        q.push({-1,-1});
        int count=0;
        while(q.size()>1){
            int x=q.front().first,y=q.front().second;
            q.pop();
            if(x==-1 && y==-1){
                q.push({-1,-1});
                count++;
            }
            for(int k=0;k<dx.size();k++){
                if((x+dx[k])>=0 && (x+dx[k])<row && (y+dy[k])>=0 && (y+dy[k])<col &&grid[x+dx[k]][y+dy[k]]==1){
                    count1s--;
                    grid[x+dx[k]][y+dy[k]]=2;
                    q.push({x+dx[k],y+dy[k]});
                }
            }
        }
        if(count1s==0){
            return count;
        }
        else
        {
            return -1;
        }
    }
