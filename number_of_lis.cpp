#include<iostream>
#include<vector>
using namespace std;

int findlis(vector<int>&nums,int n){
    
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];

                }
                else if(nums[i]>nums[j] && dp[j]+1==dp[i]){
                    cnt[i]+=cnt[j];
                }
                
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans+=cnt[i];
            }
        }
        return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans=findlis(nums,n);
    cout<<"Number of LIS"<<" "<<ans;
    return 0;
}