#include <bits/stdc++.h>
using namespace std;
int Kthsmallest(vector<int> &arr,int n,int k){
  int maxE=arr[0],minE=arr[0];
  for(int i=0;i<n;i++){
    maxE=max(maxE,arr[i]);
    minE=min(minE,arr[i]);
  }
  int low=minE,high=maxE;
  while(low<=high){
    int mid=(low+high)/2;
    int countL=0; 
    for(int i=0;i<n;i++){
      if(arr[i]<=mid){
        countL++;
      }
    }
    if(countL==k){
      return mid;
    }
    if(countL<k){
      low=mid+1;
    }
    else{
      high=mid-1;
    }
  }
}
int main()
{
  vector<int> arr{5,3,4,1,2,0};
  cout<<search(arr,6,3);
}
