#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for(int i=0;i<N;i++){
        int n,m;
        cin >> n >> m;
        v.push_back({n,m});
    }
    sort(v.begin(), v.end());
    int res=0;
    for(int i=0;i<N;i++){
        if(res < v[i].first)
            res = v[i].first;
        res+=v[i].second;
    }
    cout << res;
    return 0;
}