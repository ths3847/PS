#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;

int N;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int check(vector<pair<int, int>> p){
    int res=0;
    vector<vector<int>> visited(N, vector<int>(N));
    for(int i=0;i<3;i++){
        int x,y;
        tie(x,y) = p[i];
        res+=v[x][y];
        visited[x][y] = 1;
        for(int j=0;j<4;j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx<0 || nx >= N || ny<0 || ny >= N ||visited[nx][ny])
                return -1;
            visited[nx][ny] = 1;
            res+=v[nx][ny];
        }
    }
    return res;
}
int main(){
   cin >> N;
    string str;
    getline(cin, str);
    int nx=INT_MAX;
   for(int i=0;i<N;i++){
    getline(cin, str);
    istringstream iss(str);
    int tmp;
    vector<int> vtmp;
    while(iss>>tmp)
        vtmp.push_back(tmp);
    v.push_back(vtmp);
   } 
   for(int i=0;i<N*N;i++){
    for(int j=i+1;j<N*N;j++){
        for(int k=j+1;k<N*N;k++){
            vector<pair<int, int>> p;
            p.push_back({i%N, i/N});
            p.push_back({j%N, j/N});
            p.push_back({k%N, k/N});
            int res = check(p);
            if(res==-1) continue;
            if(res<nx) nx = res;
        }
    }
   }
   cout << nx;
}