#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
    int N,K,M;
    cin >> N;
    int idx=0;
    int t=0;
    deque<pair<int,int>> ds;
    ds.push_back({0,0});
    vector<vector<int>> v(N, vector<int>(N));
    v[0][0] =2;
    queue<pair<int, char>> L;
    cin >> K;
    for(int i=0;i<K;i++){
        int x,y;
        cin >> x >> y;
        v[--x][--y] = 1;
    }
    cin >> M;
    for(int i=0;i<M;i++){
        int s;
        char d;
        cin >> s >> d;
        L.push({s,d});
    }
    while(1){
        t++;
        int nx,ny;
        nx = ds.back().first + dx[idx];
        ny = ds.back().second + dy[idx];
        if(nx<0 || nx>=N || ny<0 || ny>=N || v[nx][ny]==2) break;
        if(v[nx][ny]!=1){
            int tx, ty;
            tie(tx,ty) = ds.front();
            v[tx][ty] = 0;
            ds.pop_front();
        }
        ds.push_back({nx,ny});
        v[nx][ny] = 2;
        if(L.empty() || t<L.front().first) continue;
        if (L.front().second == 'D') idx++;
        else idx--;
        idx = (idx%4+4)%4;
        L.pop();
        
    }
    cout << t;
    return 0;
}