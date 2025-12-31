#include <bits/stdc++.h>
using namespace std;
int R, C;
vector<vector<char>> v;
vector<vector<int>> vVisited;
vector<vector<int>> fVisited;
queue<pair<int,int>> f;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int res;
int sx, sy;

void bfsF(int x,int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    fVisited[x][y] = 0;
    while(q.size()){
        int cx,cy;
        tie(cx,cy) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx<0||nx>=R||ny<0||ny>=C||v[nx][ny]=='#'||v[nx][ny]=='J'||v[nx][ny]=='F') continue;
            if(fVisited[cx][cy]+1>=fVisited[nx][ny]) continue;
            fVisited[nx][ny] = fVisited[cx][cy]+1;
            q.push({nx,ny});
        }
    }
}

bool bfsJ(){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vVisited[sx][sy] = 0;
    while(q.size()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        if(x==0||x==R-1||y==0||y==C-1){
            res=vVisited[x][y];
            return true;
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||nx>=R||ny<0||ny>=C||v[nx][ny]=='#'||v[nx][ny]=='J'||v[nx][ny]=='F') continue;
            if(vVisited[x][y]+1 >= vVisited[nx][ny]) continue;
            if(vVisited[x][y]+1 >= fVisited[nx][ny]) continue;
            vVisited[nx][ny] = vVisited[x][y]+1;
            q.push({nx,ny});
        }
    }
    return false;
}

int main(){
    cin >> R >> C;
    for(int i=0;i<R;i++){
        string str;
        cin >> str;
        vector<char> tmp;
        for(int j=0;j<C;j++){
            tmp.push_back(str[j]);
            if(str[j] == 'F')
                f.push({i,j});
            if(str[j]=='J'){
                sx=i;
                sy=j;
            }
        }
        // vector<int> tmpv(C);
        // vVisited.push_back(tmpv);
        vector<int> tmpvv(C,10000000);
        vVisited.push_back(tmpvv);
        fVisited.push_back(tmpvv);
        v.push_back(tmp);
    }

    while(f.size()){
        int x,y;
        tie(x,y) = f.front();
        f.pop();
        bfsF(x,y);
    }

    if(bfsJ())
        cout << (res+1);
    else
        cout << "IMPOSSIBLE";

    return 0;
}