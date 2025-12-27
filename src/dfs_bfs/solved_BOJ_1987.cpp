#include <bits/stdc++.h>
using namespace std;
int R,C;
size_t mx=-0;
vector<vector<char>> v;
vector<vector<int>> visited;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void dfs(vector<char> &ch, int x, int y){
    if(ch.size() > mx)
        mx = ch.size();
    for(int i=0;i<4;i++){
        int nx, ny;
        nx = x+dx[i];
        ny = y+dy[i];
        if(nx>=0&&nx<R&&ny>=0&&ny<C){
            if(find(ch.begin(), ch.end(), v[nx][ny])==ch.end()){
                ch.push_back(v[nx][ny]);
                visited[nx][ny]=1;
                dfs(ch, nx, ny);
                ch.pop_back();
            }
        }
    }
}
int main(){
    cin >> R >> C;
    for(int i=0;i<R;i++){
        string str;
        cin >> str;
        vector<char> tmp;
        for(int j=0;j<C;j++)
            tmp.push_back(str[j]);
        v.push_back(tmp);
        vector<int> itmp(C);
        visited.push_back(itmp);
    }
    vector<char> ch;
    ch.push_back(v[0][0]);
    dfs(ch, 0, 0);
    cout << mx;
}