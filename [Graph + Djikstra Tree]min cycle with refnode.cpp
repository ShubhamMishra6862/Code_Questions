vector<pair<ll,ll>> adj[100111]; //node, distance

// dist par
pair<vector<ll>, vector<PP>> dijkstraTree(ll ref,ll n){
    vector<ll> dist(n+2, 1e18); //total dist
    // parent, edgeWeight
    vector<PP> par(n+2, {-1, -1}); //parent,weight
    //djitkstra process

    set<pair<ll,ll>> s;
    s.insert({0, ref}); //TotalDist, node
    dist[ref]=0;
    while(s.size()){
        auto elem = *s.begin();
        s.erase(s.begin());
        for(auto itr : adj[elem.second]){  
            ll ndist = itr.second+elem.first; // nodeDist +parentDist
            if(ndist<dist[itr.first]){
                s.erase({dist[itr.first], itr.first}); // previous Dist, node
                dist[itr.first]=ndist;
                par[itr.first]={elem.second, itr.second}; // node= parent,distance
                s.insert({dist[itr.first], itr.first});
            }
        }
    }
    return {dist, par};
}

int main(){
    ll n, m; cin>>n>>m;
    vector<pair<pair<ll,ll>, ll>> edges;
    for(ll i=0;i<m;i++){
        ll x,y,z; cin>>x>>y>>z;
        edges.push_back({{x, y}, z});
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    ll ref; cin>>ref;
    pair<vector<ll>, vector<PP>> tmp = dijkstraTree(ref, n);
    vector<ll> dist = tmp.first;
    vector<PP> par = tmp.second; // parent,nodeWeight
    for(ll i=1;i<=n;i++) adj[i].clear(); //clear adj to make djikstra tree
    ll rootNode = ref;
    for(ll i=1;i<=n;i++){
        if(par[i].first!=-1){
            adj[par[i].first].push_back({i, par[i].second}); //child, nodeWeight
            adj[i].push_back({par[i].first, par[i].second}); //parent, nodeWeight
        }
    }
    ///again coloring
    vector<ll> color(n+2, 0);
    color[ref]=1;
    ll col = 2;
    for(ll i=1;i<=n;i++){
        if(color[i]!=0) continue;
        queue<ll> q;
        q.push(i);
        color[i]=col;
        while(q.size()){
            auto elem = q.front();
            q.pop();
            for(auto itr : adj[elem]){
                if(color[itr.first]!=0) continue;
                color[itr.first]=col;
                q.push(itr.first);
            }
        }
        col++;
    }

    ll ans = 1e18;
    for(auto itr : edges){
        ll x = itr.first.first;
        ll y = itr.first.second;
        ll z = itr.second;
        if(color[x]!=color[y]){
            // (ref, refChild) (refChild, ref)
            if(x==ref and par[y].first==ref) continue;
            if(y==ref and par[x].first==ref) continue;
            ans = min(ans, dist[x]+dist[y]+z);
        }
    }
    cout<<ans<<endl;
}
