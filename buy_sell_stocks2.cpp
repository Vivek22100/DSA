#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int maxpro(int i,int buy,vector<int>&stocks,int n,vector<vector<int>>&dp){
    if(i==n)return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    int maxp=0;
    if(buy){
        maxp= max(-stocks[i]+maxpro(i+1,0,stocks,n,dp),0+maxpro(i+1,1,stocks,n,dp));
    }
    else {
        maxp=max(stocks[i]+maxpro(i+1,1,stocks,n,dp),0+maxpro(i+1,0,stocks,n,dp));
    }
    return dp[i][buy]=maxp;

}
int main(){
    int n;
    cin>>n;
    vector<int>stocks(n);
    for(int i=0;i<n;i++){
        cin>>stocks[i];
    }
vector<vector<int>>dp(n+1,vector<int>(2,-1));
    cout<<maxpro(0,1,stocks,n,dp);
  return 0;
}    