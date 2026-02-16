#include <bits/stdc++.h>
using namespace std;
int N, v[18][18], dp[18][18][3];
/**
 * 0: 가로, 1: 대각선, 2: 세로
 */
bool check(int x, int y, int stat){
    if(stat==0 || stat==2){
        if(v[x][y]) return false;
        else return true;
    }
    if(v[x][y] || v[x-1][y] || v[x][y-1]) return false;
    else return true;
}
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            cin >> v[i][j];
    }
    dp[1][2][0] = 1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            //가로에서 진행
            if(check(i,j+1,0)) dp[i][j+1][0] += dp[i][j][0];
            if(check(i+1,j+1,1)) dp[i+1][j+1][1] += dp[i][j][0];
            //세로에서 진행
            if(check(i+1,j,2)) dp[i+1][j][2] += dp[i][j][2];
            if(check(i+1,j+1,1)) dp[i+1][j+1][1] += dp[i][j][2];
            //대각선에서 진행
            if(check(i,j+1,0)) dp[i][j+1][0] += dp[i][j][1];
            if(check(i+1,j,2)) dp[i+1][j][2] += dp[i][j][1];
            if(check(i+1,j+1,1)) dp[i+1][j+1][1] += dp[i][j][1];
        }
    }
    int ret = 0;
    for(int i=0;i<3;i++)
        ret+=dp[N][N][i];
    cout << ret;
    return 0;
}