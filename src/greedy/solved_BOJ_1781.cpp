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
    priority_queue<int> q;
    sort(v.begin(), v.end(), [](const pair<int,int>&a, const pair<int,int>&b){
        return a.first > b.first;
    });
    int res=0;
    int idx=0;
    int mx = v[0].first;
    for(int i=mx;i>0;i--){
        while(idx<N&&v[idx].first>=i){
            q.push(v[idx].second);
            idx++;
        }
        if(q.size()){
            res+=q.top();
            q.pop();
        }
    }
    cout << res;
    return 0;
}