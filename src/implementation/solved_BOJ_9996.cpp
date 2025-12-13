#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string p;
    cin >> N;
    cin >> p;
    int start =0;
    int end =p.find("*");
    string pre = p.substr(start, end-start);
    string suf = p.substr(end+1);
    for(int i=0; i<N;i++){
        bool print = true;
        string tmp;
        cin >> tmp;
        if(tmp.size() < pre.size()+suf.size()){
            cout << "NE";
            if(i!=N-1) cout << endl;
            continue;
        }
        if(tmp.substr(0,pre.size()) != pre)
            print = false;
        if(tmp.substr(tmp.size()-suf.size(), suf.size())!= suf)
            print = false;
        if(print)
            cout << "DA";
        else
            cout << "NE";
        if(i!=N-1)
            cout << endl;
    }
    return 0;

}