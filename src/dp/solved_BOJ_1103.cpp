#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int N, M, dp[51][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<int>> v;
vector<vector<int>> visited;
int rec(int x, int y){
    if(x<0||x>=N||y<0||y>=M) return 0;
    if(v[x][y] == -1) return 0;
    if(visited[x][y]) return INF;
    if(dp[x][y]!=-1) return dp[x][y];
    visited[x][y]=1;
    int &ret = dp[x][y];
    for(int i=0;i<4;i++){
        int nx,ny;
        nx = x+dx[i]*v[x][y];
        ny = y+dy[i]*v[x][y];
        ret = max(ret, rec(nx,ny)+1);
    }
    visited[x][y]=0; 
    return ret;
}

int main(){
    cin >> N >> M;
    v.assign(N, vector<int>(M));
    visited.assign(N, vector<int>(M));
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<N;i++){
        string tmp;
        cin >> tmp;
        for(int j=0;j<tmp.length();j++){
            if(tmp[j]=='H') v[i][j]=-1;
            else v[i][j] = tmp[j]-'0';
        }
    }
    int ret = rec(0,0);
    if(ret >= INF) cout << -1;
    else cout << ret;
    return 0;
}
