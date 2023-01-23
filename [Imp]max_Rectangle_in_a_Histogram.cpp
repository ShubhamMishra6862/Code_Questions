#include<bits/stdc++.h>
using namespace std;

int recArea(vector<int> arr){
  int n=arr.size();
  vector <int> rt(n,n),lt(n,-1);                         // rt[] stores index next smaller element index present in right
                                                         // lt[] stores previous smaller element index present in leftside
  //we are assigning rt default value as n because we were not able to find next min value ans thus it is the minimum value in that array, so out of bound
  // same lt has -1 because no one in leftside has minimum value so outofbound
                                                         //the main aim is to find number of bar for which arr[i] is minimum 
                                                         //then to multiply is by arr[i] than check whether it is maximum area
  stack<int> st;
  for(int i=0;i<n;i++){                                  //To find element smaller than i in rightside 
    while(st.size() and arr[st.top()]>arr[i]){
      rt[st.top()]=i;
      st.pop();
    }
    st.push(i);
  }
  for(int i=n-1;i>=0;i--){                               //To find element smaller than i in leftside
    while(st.size() and arr[st.top()]>arr[i]){
      lt[st.top()]=i;
      st.pop();
    }
    st.push(i);
  }
 
  cout<<endl;
  int ans=0;
  for(int i=0;i<n;i++){
    ans=max(ans,arr[i]*(rt[i]-lt[i]-1));                 
  }
  return ans;
}

int main(){
    vector<int> height{2,1,5,6,2,3};
    cout<<recArea(height);
}
