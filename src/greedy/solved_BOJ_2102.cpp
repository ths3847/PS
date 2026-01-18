#include <bits/stdc++.h>
using namespace std;
int main(){
    // 1. 가장 작은 가방으로 최대 가격의 보석을 담는다.
    int N,K;
    cin >> N >> K;
    vector<pair<int, int>> V;
    vector<int> C;
    priority_queue<int> q;
    long long res = 0;
    for(int i=0;i<N;i++){
        int m, v;
        cin >> m >> v;
        V.push_back({m,v});
    }
    for(int i=0;i<K;i++){
        int c;
        cin >> c;
        C.push_back(c);
    }
    sort(V.begin(), V.end());
    sort(C.begin(), C.end());
    int idx=0;
    for(int i=0;i<K;i++){
        for(int j=idx;j<N;j++){
            if(C[i] < V[j].first)
                break;
            else{
                q.push(V[j].second);
                idx++;
            }
        }
        if(q.size()){
            res+=q.top();
            q.pop();
        }
    }
    cout << res;
    return 0;
}