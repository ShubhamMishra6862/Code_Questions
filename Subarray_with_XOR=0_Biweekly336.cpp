// the intuition was that if there is a subbaray which after given operation becomes zero that means its setbits conincide thus on prefix XOR it will result 0
//now to find that create map push value if that value occurs it means we have found our subbarray from i+1 to j-1 
// Main intuition is PREFIX_XOR
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
       map<int,int> mp;
       mp[0]=1;
        long long curr=0;
        long long res=0;
       for(int i=0;i<nums.size();i++){
            curr^=nums[i];
            res+=mp[curr];
            mp[curr]++;
       }
        return res;
    }
};
