#include<bits/stdc++.h>
using namespace std;
bool comp(int a,int b){
    if(a<0 && b<0){
        return a>b;
    }
    if(a>0 && b>0){
        return a<b;
    }
    return a<b;
 
}
//sort template works differently like usual 
//to swap value you have to return false instead of true
bool should_iswap(int a,int b){
  return a<b; // I want sorting algorithm to sort in decreasing order thats why a>b
  //if a is not less than b than it needs to be swapped means it is not in order
}
int main(){
    vector<int> arr {-5,-3,-1,0,5,6,7};
    sort(arr.begin(),arr.end(),comp);
    for(auto i:arr){
        cout<<i<<" ";
    }
}
//in simple words you need to give return function to comparator in which type you want
