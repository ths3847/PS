#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> visited;
vector<vector<char>> v;
vector<vector<int>> swan_visited;
queue<pair<int, int>> swanQ;
queue<pair<int, int>> warterQ;
queue<pair<int, int>> tmpQ;
int R,C;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool moveSwan(){
    while(swanQ.size()){
        int x,y;
        tie(x,y) = swanQ.front();
        swanQ.pop();
        for(int i=0;i<4;i++){
            int nx,ny;
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx>=0&&nx<R&&ny>=0&&ny<C&&swan_visited[nx][ny]!=1){
                swan_visited[nx][ny] = 1;
                if(v[nx][ny] == 'L')
                    return true;
                if(v[nx][ny]=='.')
                    swanQ.push({nx,ny});
                else if(v[nx][ny]=='X')
                    tmpQ.push({nx,ny});
            }
        }
    }
    return false;
}

void meltIce(){
    while(warterQ.size()){
        int x,y;
        tie(x,y) = warterQ.front();
        warterQ.pop();
        for(int i=0;i<4;i++){
            int nx,ny;
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx>=0&&nx<R&&ny>=0&&ny<C&&visited[nx][ny]!=1){
                visited[nx][ny] = 1;
                if(v[nx][ny] == 'X'){
                    tmpQ.push({nx,ny});
                    v[nx][ny] = '.';
                }
            }
        }
    }
}

int main(){
    int res=0;
    cin >> R >> C;
    pair<int, int> start = {-1,-1};
    for(int i=0;i<R;i++){
        string str;
        cin >> str;
        vector<char> tmp;
        for(int j=0;j<C;j++)
            tmp.push_back(str[j]);
        v.push_back(tmp);
        vector<int> itmp(C);
        visited.push_back(itmp);
        swan_visited.push_back(itmp);
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(v[i][j] != 'X'){
                visited[i][j] = 1;
                warterQ.push({i,j});
            }
            if(v[i][j] == 'L' && start.first == -1){
                swan_visited[i][j] = 1;
                start = {i,j};
                swanQ.push(start);
            }
        }
    }

    while(true){
        if(moveSwan())
            break;
        swanQ.swap(tmpQ);
        meltIce();
        warterQ.swap(tmpQ);
        res++;
    }
    cout << res;
    return 0;
}