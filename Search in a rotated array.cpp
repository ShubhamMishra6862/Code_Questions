bool search(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;
        while(low<=high){
            int mid=ceil(((double)high+(double)low)/2);
            if(nums[mid]==target){
                return true;
            }
            //mid was not equal to target 
            //now we know that there will be two parts
            //now unsorted part can be on either side 
            //like [3,4,5|0,1,2] or [4,5|0,1,2,3] 
            //1. sorted which will be monotonic
            //2. unsorted part where the rotated elements are also there
            //if mid is not the target now our main aim is to find which part of the search space is sorted because:
            //1. if the element is between that sorted side than search that part 
            //2. else if not then search unsorted part or rotated part
        
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //now if arr[low]>arr[mid] this means arr[low].....arr[mid] search space is unsorted
            else{
                if(target<=nums[high] && nums[mid]<target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
