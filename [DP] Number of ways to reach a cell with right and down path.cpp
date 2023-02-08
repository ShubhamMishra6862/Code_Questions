#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n+1,vector<int>(n+1,0));
    arr[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1 and j==1)continue;
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
