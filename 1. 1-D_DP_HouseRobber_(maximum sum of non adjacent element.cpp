 int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            return arr[0];
        }
        int prev1=arr[0],prev2=0,res=0;
        for(int i=1;i<n;i++){
            int take=arr[i];
            if(i>1) take+=prev2;
            int Ntake=prev1;
            res=max(take,Ntake);
            prev2=prev1;
            prev1=res; 
        }
        return res;
    }
