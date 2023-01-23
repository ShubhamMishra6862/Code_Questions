#include <bits/stdc++.h>
using namespace std;

int pivot(vector<vector<int>>&arr, int i, int j,int k)
{
  int high=j,low=0;
  while(low<high){
    int mid=(low+high)/2;
    if(arr[i][mid+1]>=k && arr[i][mid]<arr[i][mid+1] && arr[i][mid]<k){
      return mid;
    }
    if(arr[i][mid]<k && arr[i][mid]<arr[i][mid+1]){
       low=mid+1;
    }
    else if(arr[i][mid]>k && arr[i][mid]>arr[i][mid-1]){
       high=mid-1;
    }
  }
}
void solve(vector<vector<int>>&arr,int row,int col, int k)
{
  
  int count = 0;
  for (row = 0; row <4; row++)
  {
    if (arr[row][col] < k)
    {
      count += col+1;
      cout<<count<<"/"<<endl;
    }
    if (arr[row][col] > k)
    {
      row=pivot(arr, row, col,k);
      count+=row+1;
      break;
    }
  }
  cout<<count;
}
int main()
{
  vector<vector<int>>arr{{0, 1, 2, 3, 4}, {2, 6, 7, 8, 9}, {5, 8, 12, 13, 14}, {15, 16, 17, 18, 19}};
  solve(arr,4,4,18);
}
