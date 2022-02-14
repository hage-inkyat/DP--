/*nn 個の品物があり、ii 番目の品物のそれぞれ重さと価値が weight[i],value[i]weight[i],value[i] 
となっている (i=0,1,...,n−1i=0,1,...,n−1)。
これらの品物から重さの総和が WW を超えないように選んだときの、
価値の総和の最大値を求めよ。*/
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,W,a;
  cin>>n>>W;
  int v[n+1],w[n+1];
  for(int i=1;i<=n;i++){
    cin>>v[i]>>w[i];
  }

  vector<vector<long long>> dp(n+1,vector<long long>(W+1,0));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=W;j++){
      if(j>=w[i]){
        dp[i][j]=max({dp[i-1][j],dp[i-1][j-w[i]]+v[i],dp[i][j-w[i]]+v[i]});
      }else{
        dp[i][j]=dp[i-1][j];            
      }
    }
  }
  cout<<dp[n][W]<<endl;

  return(0);
}