#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int M, N,cnt;
vector<vector<int>> v;
vector<vector<int>> visited;
queue<pair<int, int>> tmpQ;

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    while(q.size()){
        int cx,cy;
        tie(cx,cy) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx<0||nx>=N||ny<0||ny>=M||v[nx][ny]==-1||visited[nx][ny]==1) continue;
            visited[nx][ny]=1;
            if(v[nx][ny]==1)
                q.push({nx,ny});
            else if(v[nx][ny]==0){
                cnt--;
                tmpQ.push({nx,ny});
                v[nx][ny] = 1;
            }
        }
    }
}

int main(){
    cin >> M >> N;
    int res=0;
    for(int i=0;i<N;i++){
        vector<int> tmpv;
        for(int j=0;j<M;j++){
            int n;
            cin >> n;
            if(n==0)
                cnt++;
            if(n==1)
                tmpQ.push({i,j});
            tmpv.push_back(n);
        }
        v.push_back(tmpv);
        vector<int> vv(M);
        visited.push_back(vv);
    }
    while(cnt>0){
        int n = tmpQ.size();
        for(int i=0;i<n;i++){
            int x,y;
            tie(x,y) = tmpQ.front();
            tmpQ.pop();
            bfs(x,y);
        }
        res++;
        if(!tmpQ.size() && cnt!=0){
            cout << -1;
            return 0;
        }
    }
    cout << res;
    return 0;
}