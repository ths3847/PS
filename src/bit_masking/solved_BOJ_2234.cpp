#include <bits/stdc++.h>
using namespace std;
int N, M;
int cnt;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

vector<vector<int>> v;
vector<vector<int>> visited(50, vector<int>(50));
vector<vector<int>> visited2(50, vector<int>(50));

set<pair<int, int>> ss;

int bfs(int x, int y){
    visited[x][y] = cnt;
    int ret = 0;
    queue<pair<int, int>> q;
    q.push({x,y});
    while(q.size()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        ret++;
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx<0||nx>=M||ny<0||ny>=N||visited[nx][ny]!=0) continue;
            if(v[cx][cy]&(1<<i)) continue;
            visited[nx][ny] = cnt;
            q.push({nx,ny});
        }
    }
    return ret;
}

bool check(int x, int y){
    int ret = false;
    visited2[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x,y});
    while(q.size()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0||nx>=M||ny<0||ny>=N||visited2[nx][ny]!=0) continue;
            if(visited[cx][cy] != visited[nx][ny]){
                ss.insert({visited[cx][cy]-1, visited[nx][ny]-1});
                continue;
            }
            visited2[nx][ny] = 1;
            q.push({nx,ny});
            }
    }
    return false;
}

int main(){
    cin >> N >> M;
    int mx=0;
    vector<vector<int>> res;
    for(int i=0;i<M;i++){
        vector<int> tmpv;
        for(int j=0;j<N;j++){
            int tmp;
            cin >> tmp;
            tmpv.push_back(tmp);
        }
        v.push_back(tmpv);
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j] == 0){
                cnt++;
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(bfs(i,j));
                res.push_back(tmp);
                mx = max(mx,res[cnt-1][2]);
            }
        }
    }
    int total = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(visited2[i][j]==0)
                check(i,j);
        }
    }
    for (auto it = ss.begin(); it != ss.end(); ++it) {
        total = max(total, (res[it->first][2]+res[it->second][2]));
    }

    cout << cnt << endl;
    cout << mx << endl;
    cout << total;
}