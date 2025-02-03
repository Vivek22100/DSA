#include<iostream>
#include<vector>
using namespace std;

int main(){
  string s;
  string p;
  
cin>>s;

cin>>p;
  int n=s.size();
  int m=p.size();
  vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
dp[0][0]=true;
for(int j=1;j<=m;j++){
    if(p[j-1]=='*'){
        dp[0][j]=dp[0][j-1];
    }
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            dp[i][j]=dp[i-1][j-1];
        }
        else if(p[j-1]=='*'){
            dp[i][j]=dp[i-1][j]||dp[i][j-1];
        }
    }
}
  
   cout << (dp[n][m] ? "True" : "False") << endl;
  
  return 0;
}
