int longestOnes(vector<int>& nums, int k) {
         queue<int>zeropos;
        int ki=k;
        int l=0,r=0;
        int maxcount=0;
        while(l<nums.size() && r<nums.size())
        {
            
            if(nums[r]==0){
                if(k>=0){
                    if(zeropos.size()>0){
                        l=zeropos.front()+1;
                        zeropos.pop();
                        zeropos.push(r);
                    }
                    else{
                        l=r;
                    }
                    
                }
                else{
                    zeropos.push(r);
                    k--;
                }
            }
            maxcount=max(maxcount,r-l);
            r++;
            
        }
        return maxcount;
    }
int main(){
    vector<int>arr{0,0,1,1,1,0,0};
    cout<<longestOnes(arr,0);
}
