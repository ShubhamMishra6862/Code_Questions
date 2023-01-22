#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//atmost is the function to count all subarray that has sum value <=goal
//our main idea is to count all subarray with sum <=goal ans then subtract it with value <=goal-1
int atmost(vector<int>&arr,int goal){
	int i=0,j=0,count=0,ans=0;
	for(i=0;i<arr.size();i++){
		count+=arr[i];
		while(count>goal){
			count-=arr[j];
			j++;
		}
		ans+=i-j+1;// formula of possible subarray from i to j
	}
	return ans;
}
int numSubarraysWithSum(vector<int> &arr, int goal)
{
	return atmost(arr,goal)-atmost(arr,goal-1); // if we find all subarray with sum <=goal and then we find the number of subarray with sum <=goal-1;
	//than the number of subarray with exact == goal will =>(subarray with sum<=goal)-(subarray with sum<=goal-1) 
}

int main()
{
	vector<int> arr{1,0,1,0,1};
	cout << numSubarraysWithSum(arr, 2);
}
