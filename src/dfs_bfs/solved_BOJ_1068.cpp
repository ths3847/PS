#include <bits/stdc++.h>
using namespace std;

int res;

void dfs(vector<vector<int>> g, int s){
    if(g[s].size() == 0){
        res++;
        return;
    }
    for(int i=0;i<g[s].size();i++)
        dfs(g, g[s][i]);
}

int main(){
    int N, m;
    int root;
    cin >> N;
    vector<int> v(N);
    vector<vector<int>> tree(N);
    vector<int> p;
    for(int i=0;i<N;i++){
        cin >> v[i];
        if(v[i] == -1){
            root = i;
            continue;
        }
        tree[v[i]].push_back(i);
    }
    cin >> m;
    //root 지우는 경우 제외하고, 부모에 노드에서 삭제
    if(v[m] == -1)
    {
        cout << 0;
        return 0;   
    }
    else{
        auto it =find(tree[v[m]].begin(), tree[v[m]].end(), m);
        tree[v[m]].erase(it);
    }

    dfs(tree, root);
    cout << res;

    return 0;
}