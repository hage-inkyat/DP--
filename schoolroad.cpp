#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while( cin >> a >> b , a || b ){
        int n, dp[20][20] = {0};
        dp[1][1] = 1;
        cin >> n;
        for(int i=0 ; i < n ; i++ ){
            int x,y;
            cin >> x >> y;
            dp[y][x] = -1; //交差点(x,y)までの経路の数が求まっていないので-1で初期化する
        }
        for(int y=1 ; y <= b ; y++ ){
            for(int x=1 ; x <= a ; x++ ){
                if( dp[y][x] != -1 ){
                    if( y != 1 && dp[y-1][x] != -1 ){
                        dp[y][x] += dp[y-1][x];
                    }
                    if( x != 1 && dp[y][x-1] != -1 ){
                        dp[y][x] += dp[y][x-1];
                    }
                }
            }
        }// (a,b)までの経路の数を出力
        cout << dp[b][a] << endl;
    }
    return(0);
}