#include <bits/stdc++.h>
using namespace std;
int m[4];
bool check(vector<int> v){
    for(int i=0;i<4;i++){
        if(v[i]<m[i])
            return false;
    }
    return true;
}

int main(){
    int N;

    cin >> N;
    for(int i=0;i<4;i++) cin >> m[i];
    vector<vector<int>> v;
    vector<vector<int>> res;
    int mn=10000000;
    for(int i=0;i<N;i++){
        vector<int> tmpv;
        for(int j=0;j<5;j++){
            int tmp;
            cin >> tmp;
            tmpv.push_back(tmp);
        }
        v.push_back(tmpv);
    }
    for(int i=1;i<(1<<N);i++){
        vector<int> sumv(5);
        vector<int> listv;
        for(int j=0;j<N;j++){
            if(i&(1<<j)){
                for(int k=0;k<5;k++) sumv[k]+=v[j][k];
                listv.push_back(j+1);
            }
        }
        if(!check(sumv)) continue;
        if(sumv[4] < mn){
            res.clear();
            mn = sumv[4];
            res.push_back(listv);
        }
        else if(sumv[4] == mn)
            res.push_back(listv);
    }
    if(mn==10000000){
        cout << -1;
        return 0;
    }
    sort(res.begin(), res.end());
    cout << mn << "\n";
    for(int j=0;j<res[0].size();j++){
        cout << res[0][j];
        if(j!=res[0].size()-1) cout << " ";
    }
    return 0;
}