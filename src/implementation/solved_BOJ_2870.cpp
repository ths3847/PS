#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M;
    cin >> M;
    vector<string> v;
    vector<string> res;
    for(int i=0;i<M;i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<M;i++){
        string tmp;
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] >= '0' && v[i][j]<='9')
                tmp+=v[i][j];
            else{
                if(tmp.size()>0)
                    res.push_back(tmp);
                tmp="";
            }
        }
        if(tmp.size()>0)
            res.push_back(tmp);
    }

    for(int i=0;i<res.size();i++){
        while(res[i][0] == '0' && res[i].size()!=1)
            res[i].erase(0,1);
    }

    sort(res.begin(), res.end(), [](const string &a, const string &b){
        if(a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    });

    for(int i=0;i<res.size();i++){
        cout << res[i];
        if(i!=res.size()-1)
            cout << endl;
    }
    
    return 0;
}