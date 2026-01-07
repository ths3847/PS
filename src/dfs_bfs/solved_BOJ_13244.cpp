#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>> v, vector<int> visited){
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(q.size()){
        int x = q.front();
        q.pop();
        for(int i : v[x]){
            if(visited[i]!=0) continue;
            visited[i] = 1;
            q.push(i);
        }
    }
    if(accumulate(visited.begin(),visited.end(),0) == visited.size())
        return true;
    else
        return false;
}
int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int N, M;
        cin >> N >> M;
        vector<int> visited(N);
        vector<vector<int>> v(N);
        for(int j=0;j<M;j++){
            int s,e;
            cin >> s >> e;
            v[s-1].push_back(e-1);
            v[e-1].push_back(s-1);
        }
        bool ret = bfs(v, visited);
        if(ret && M==N-1) cout << "tree" << endl;
        else cout << "graph" << endl;
    }
    return 0;
}