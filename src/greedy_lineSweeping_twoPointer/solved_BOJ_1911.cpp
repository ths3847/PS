#include <bits/stdc++.h>
using namespace std;
int N, L;
int main(){
    vector<pair<int,int>> v;
    cin >> N >> L;
    for(int i=0;i<N;i++){
        int s, e;
        cin >> s >> e;
        v.push_back({s,e-1});
    }
    sort(v.begin(), v.end());
    int ret = 0;
    int ls = -1;
    int le = -1;
    for(int i=0;i<N;i++){
        if(le < v[i].first){
            ret++;
            ls = v[i].first;
            le = ls+L-1;
        }
        while(le < v[i].second){
            ret++;
            ls = le+1;
            le = ls+L-1;
        }
    }
    cout << ret;
}