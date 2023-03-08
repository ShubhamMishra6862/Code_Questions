int minEatingSpeed(vector<int>& arr, int h) {
        int  maxe=arr[0];
        for(int i=0;i<arr.size();i++){
            maxe=max(maxe,arr[i]);
        }
        int res=INT_MAX;
        int low=1,high=maxe;
        while(low<high){
            int mid=(low+high)/2;
            int hc=0;
            for(int i=0;i<arr.size();i++){
                hc+=ceil(double(arr[i])/double(mid));
            }
            
            if(hc<=h){
                res=min(res,mid);
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
