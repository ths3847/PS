#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> v;
    int res=0;
    for(int i=0;i<K;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    vector<int> used;
    for(int i=0;i<K;i++){
        if(find(used.begin(), used.end(), v[i])!=used.end()) continue; //used가 채워지기 전에 같은 수가 여러번 들어올 수 있음
        if(used.size() < N){
            used.push_back(v[i]);
            continue;
        }
        int idx=0;
        int mx=0;
        for(int j=0;j<N;j++){
            int c;
            c = find(v.begin()+i, v.end(), used[j])-v.begin();
            if(c>mx){
                mx=c;
                idx = j;
            }
        }
        used[idx] = v[i];
        res++;
    }
    cout << res;
    return 0;
}