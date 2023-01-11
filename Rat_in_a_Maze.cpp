#include <bits/stdc++.h>
using namespace std;


void backtrack(vector<vector<int>> &arr,int row,int col,int m,int n,string str=""){
  if(row>=n || col>=m || arr[row][col]==2){
    return;
  }
  if(arr[row][col]==5){
    cout<<str<<endl;
  }

  backtrack(arr,row,col+1,m,n,str+='r');
  str.pop_back();
  backtrack(arr,row+1,col,m,n,str+='d');
}
int main()
{
  vector<vector<int>> arr{{0,0,0,2},{0,2,0,0},{0,0,0,0},{2,0,0,5}};
  backtrack(arr,0,0,4,4);
}
