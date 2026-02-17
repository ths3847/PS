#include <bits/stdc++.h>
using namespace std;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int N, K;
vector<vector<int>> k;
vector<vector<int>> n(14,vector<int>(14,2));

vector<vector<deque<int>>> v;

bool check(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(v[i][j].size()>=4) return true;
        }
    }
    return false;
}

int main(){
    int ret=0;
    cin >> N >> K;
    k.assign(K, vector<int>());
    v.assign(N+1, vector<deque<int>>(N+1));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> n[i][j];
        }
    }

    for(int i=0;i<K;i++){
        int x, y, d;
        cin >> x >> y >> d;
        k[i].push_back(x);
        k[i].push_back(y);
        k[i].push_back(d);
        v[x][y].push_back(i);
    }

    while(1){
        if(check())
            break;
        if(ret>1000)
            break;
        ret++;
        for(int i=0;i<K;i++){
            int nx, ny;
            int x(k[i][0]),y(k[i][1]),d(k[i][2]);

            nx = x + dx[d];
            ny = y + dy[d];
            if(n[nx][ny]==0 || n[nx][ny]==1){
                deque<int> tmp;
                while(1){
                    int p = v[x][y].back();
                    v[x][y].pop_back();
                    if(n[nx][ny]==0)
                        tmp.push_front(p);
                    else
                        tmp.push_back(p);
                    k[p][0] = nx;
                    k[p][1] = ny;
                    if(p==i)
                        break;
                }
                v[nx][ny].insert(v[nx][ny].end(), tmp.begin(), tmp.end());
                if(check())
                    break;
            }
            else if(n[nx][ny]==2){
                int tx, ty, td;
                td = d%2 ? d+1 : d-1;
                tx = x + dx[td];
                ty = y + dy[td];
                k[i][2] = td;
                if(n[tx][ty] == 2)
                    continue;
                deque<int> tmp;
                while(1){
                    int p = v[x][y].back();
                    v[x][y].pop_back();
                    if(n[tx][ty]==0)
                        tmp.push_front(p);
                    else
                        tmp.push_back(p);
                    k[p][0] = tx;
                    k[p][1] = ty;
                    if(p==i)
                        break;
                }
                v[tx][ty].insert(v[tx][ty].end(), tmp.begin(), tmp.end());
                if(check())
                    break;
            }
        }
    }
    if(ret>=1000) cout << -1;
    else cout << ret;
    return 0;

}