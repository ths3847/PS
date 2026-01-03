#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> a;
vector<vector<int>> v;

int check(int n){
    vector<int> tmp;
    int res=0;
    for(int i=0;i<N;i++)
        if(n&(1<<i)) tmp.push_back(i);
    if(tmp.size()==0) return 0;
    vector<int> visited(tmp.size());
    visited[0] = 1;
    queue<int> q;
    q.push(tmp[0]);
    res+=a[tmp[0]];
    while(q.size()){
        int x = q.front();
        q.pop();
        for(int j : v[x]){
            auto it = find(tmp.begin(), tmp.end(), j);
            if(it!=tmp.end() && visited[it-tmp.begin()]==0){
                visited[it-tmp.begin()] = 1;
                q.push(*it);
                res+=a[*it];
            }
        }
    }
    int vsum = accumulate(visited.begin(), visited.end(), 0);
    if(vsum==visited.size()) return res;
    else return 0;
}

int main(){
    cin >> N;
    int mn=100000000;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        if(n==0){
            vector<int> tmpv(1,-1);
            v.push_back(tmpv);
            continue;
        }
        vector<int> tmpv;
        for(int j=0;j<n;j++){
            int tmp;
            cin >> tmp;
            tmpv.push_back(tmp-1);
        }
        v.push_back(tmpv);
    }

    for(int i=1;i<(1<<N)-1;i++){
        int x,y;
        x = check(i);
        y = check(~i);
        if(x==0 || y==0) continue;
        mn = (mn>abs(x-y)) ? abs(x-y) : mn;
    }
    if(mn == 100000000){
        cout << -1;
        return 0;
    }
    cout << mn;
    return 0;
}