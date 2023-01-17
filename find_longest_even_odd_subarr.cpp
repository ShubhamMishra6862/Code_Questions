int eveOdd(vector<ll> &arr){
    int n=arr.size();
    map<ll,ll> pref;
    pref[0]=0;
    ll sum=0, res=0;

    for(ll i=1;i<=n;i++){
        ll ele=arr[i-1];
        if(ele%2) sum=sum-1;
        else sum=sum+1;
        if(pref.count(sum)){
          res=max(res,i-pref[sum]); //-1, x,...........-1 so x to -1 is our subarray //x.........i //thats why we are storing i not i-1 in pref
        } 
        else{
          pref[sum]=i;
        } 
    }
    return res;
}
