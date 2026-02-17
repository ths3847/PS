#include <bits/stdc++.h>
using namespace std;
int N, M, K;
vector<vector<int>> v;
vector<vector<deque<int>>> aTrees;
vector<vector<vector<int>>> dTrees;
vector<vector<int>> A;

int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

void spring(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            deque<int> tmp = aTrees[i][j];
            deque<int> back;
            int sz = tmp.size();
            if(tmp.empty()) continue;
            int k;
            for(k=0;k<sz;k++){
                int t = tmp.front();
                tmp.pop_front();
                if(t <= v[i][j]){
                    v[i][j]-=t;
                    t++;
                    back.push_back(t);
                }
                else{
                    dTrees[i][j].push_back(t);
                }
            }
            aTrees[i][j] = back;
        }
    }
}

void summer(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            vector<int> &tmp = dTrees[i][j];
            if(tmp.empty()) continue;
            for(int k=0;k<tmp.size();k++)
                v[i][j]+=tmp[k]/2;
            tmp.clear();
        }
    }
}

void fall(){
    vector<pair<int,int>> newt;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0; k<aTrees[i][j].size();k++){
                if(aTrees[i][j][k]%5==0){
                    for(int l=0;l<8;l++){
                        int nx,ny;
                        nx = i+dx[l];
                        ny = j+dy[l];
                        if(nx<0||nx>=N||ny<0||ny>=N) continue;
                        newt.push_back({nx,ny});
                    }
                }
            }
        }
    }
    for(int i=0;i<newt.size();i++){
        int nx,ny;
        tie(nx,ny) = newt[i];
        aTrees[nx][ny].push_front(1);
    }
}

void winter(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            v[i][j] += A[i][j];
        }
    }
}

int main(){
    cin >> N >> M >> K;
    v.assign(N, vector<int>(N,5));
    A.assign(N, vector<int>(N));
    aTrees.assign(N, vector<deque<int>>(N));
    dTrees.assign(N, vector<vector<int>>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> A[i][j];
    }
    for(int i=0;i<M;i++){
        int x,y,a;
        cin >> x >> y >> a;
        aTrees[x-1][y-1].push_back(a);
        sort(aTrees[x-1][y-1].begin(), aTrees[x-1][y-1].end());
    }
    for(int i=0;i<K;i++){
        spring();
        summer();
        fall();
        winter();
    }
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cnt+=aTrees[i][j].size();
        }
    }
    cout << cnt;
    return 0;
}