#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> v;
int R,C,K;
int res;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(int cnt, int x, int y, vector<vector<int>> visited){
    cnt++;
    if(cnt>K)
        return;
    if(x==0&&y==C-1&&cnt==K)
        res++;
    visited[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||nx>=R||ny<0||ny>=C||visited[nx][ny]==1||v[nx][ny]=='T') continue;
        dfs(cnt,nx,ny,visited);
    }
}

int main(){
  cin >> R >> C >> K;
  for(int i=0;i<R;i++){
    string str;
    vector<char> tmp;
    cin >> str;
    for(int j=0;j<C;j++)
        tmp.push_back(str[j]);
    v.push_back(tmp);
  }  
  vector<vector<int>> visited(R, vector<int>(C));
  dfs(0, R-1,0, visited);
  cout << res;
}