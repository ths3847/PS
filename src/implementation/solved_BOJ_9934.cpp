#include <bits/stdc++.h>
using namespace std;
int K;
vector<int> v;
vector<vector<int>> res;
void rec(int s, int e, int depth){
    if(s==e){
        res[depth].push_back(v[s]);
        return;
    }
    int m = (s+e)/2;
    res[depth].push_back(v[m]);
    depth++;
    rec(s, m-1,depth);
    rec(m+1, e,depth);
}
int main(){
    cin >> K;
    cin.ignore();
    string str;
    getline(cin, str);
    istringstream iss(str);
    string token;
    while(iss >> token)
        v.push_back(stoi(token));
    res.resize(K);
    rec(0,v.size()-1, 0);
    for(int i=0;i<K;i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j];
            if(j!=res[i].size()-1)
                cout << " ";
        }
        if(i!=K-1)
            cout << endl;
    }
    return 0;
}