#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<char> s;
    string str;
    string tok;
    cin >> str >> tok;
    int idx=0;
    string res="";
    for(char ch : str){
        res+=ch;
        if(res.size() >= tok.size()&&res.substr(res.size()-tok.size(), tok.size())==tok){
            res.erase(res.end()-tok.size(), res.end());
        }
    }
    if(res!="")
        cout << res;
    else
        cout << "FRULA";
    return 0;
}