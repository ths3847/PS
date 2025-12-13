#include <bits/stdc++.h>
using namespace std;

int l = 2;
int N,M;
int total;
vector<int> v;
void combi(vector<int> &idx, int s){
    if(idx.size()==l){
        if(v[idx[0]]+v[idx[1]] == M)
            total++;
        return;
    }
    for(int i=s+1;i<N;i++){
        idx.push_back(i);
        combi(idx, i);
        idx.pop_back();
    }
}
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    vector<int> idx;
    combi(idx, -1);
    cout << total;
    return 0;
}