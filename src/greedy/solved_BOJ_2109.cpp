#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> check(10001);
    vector<pair<int, int>> v;
    priority_queue<int> p;
    int N;
    int res=0;
    cin >> N;
    if(N==0){
        cout << 0;
        return 0;
    }
    for(int i=0;i<N;i++){
        int p, d;
        cin >> p >> d;
        v.push_back({p,d});
    }
    sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int, int>& b){
        return a.second > b.second;
    });
    int last_day = v[0].second;
    int idx=0;
    for(int i=last_day;i>0;i--){
        while(idx<N && v[idx].second>=i){
            p.push(v[idx].first);
            idx++;
        }
        if(p.size()){
            res+=p.top();
            p.pop();
        }
    }
    
    cout << res;
    return 0;
}