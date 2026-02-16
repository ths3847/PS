#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
vector<vector<int>> dp;
int N;
vector<int> rec(int idx){
    if(idx==1){
        vector<int> res(1,1);
        return res;
    }
    if(!dp[idx].empty()) return dp[idx];
    vector<int> &ret = dp[idx];
    vector<int> tmp;
    ret = rec(idx-1);
    if(idx%3==0){
        tmp = rec(idx/3);
        ret = tmp.size() < ret.size() ? tmp : ret;
    }
    if(idx%2==0){
        tmp = rec(idx/2);
        ret = tmp.size() < ret.size() ? tmp : ret;
    }


    ret.push_back(idx);
    return ret;
}
int main(){
    cin >> N;
    dp.assign((N+1), vector<int>());
    vector<int> res;
    res = rec(N);
    reverse(res.begin(), res.end());
    cout << res.size()-1 << endl;
    for(auto i : res) cout << i << " ";
    cout << endl;
    return 0;
}