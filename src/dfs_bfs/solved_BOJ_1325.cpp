#include <bits/stdc++.h>
using namespace std;



int dfs(const vector<vector<int>> &g, vector<int> &visit, int s){
    int res = 1;
    visit[s] = 1;
    for(int i=0;i<g[s].size();i++){
        if(visit[g[s][i]])
            continue;
        else
            res+=dfs(g,visit,g[s][i]);
    }
    return res;
}

int main(){
    int N, M;
    int mx = 0;
    cin >> N >> M;
    vector<vector<int>> g(N+1);
    vector<int> visit(N+1);
    vector<int> res(N+1);
    for(int i=0;i<M;i++){
        int s,e;
        cin >> s >> e;
        g[e].push_back(s);
    }
    for(int i=1;i<N+1;i++){
        if(g[i].size() == 0)
            continue;
        res[i] = dfs(g, visit, i);
        fill(visit.begin(), visit.end(),0);
    }
    vector<int> p;
    mx = *max_element(res.begin(), res.end());
    for(int i=1;i<N+1;i++){
        if(res[i] == mx)
            p.push_back(i);
    }


    for(int i=0; i<p.size();i++){
        cout << p[i];
        if(i != p.size()-1)
            cout << " ";
    }
    return 0;
}