int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> m;
        
        for(int i=0;i<n;i++){
            m.push_back({position[i],speed[i]});
        }
        sort(m.begin(),m.end());
        vector<double> pos;
        stack<double> s;
        for(auto i: m){
            pos.push_back(((double)target-(double)i.first)/(double)i.second);
        }
        for(int i=0;i<n;i++){
            
            while(!s.empty() && pos[s.top()]<= pos[i]){
                s.pop();
            }
            s.push(i);
        }
        return s.size();
    }
