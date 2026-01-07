#include <bits/stdc++.h>
using namespace std;
int main(){
    int mx;
    string op1;
    string op2;
    string ret = "";
    cin >> op1 >> op2;
    int c = 0;
    mx = max(op1.size(), op2.size());
    reverse(op1.begin(), op1.end());
    reverse(op2.begin(), op2.end());
    for(int i=0;i<mx;i++){
        if(i >= op1.size()) op1+="0";
        if(i >= op2.size()) op2+="0";
    }
    for(int i=0;i<mx;i++){
        int tmp;
        tmp = (op1[i]-'0') + (op2[i]-'0');
        if(c) tmp++;

        if(tmp/10)
            c = 1;
        else
            c = 0;
        
        ret+=to_string(tmp%10);
    }
    if(c)
        ret+="1";
    reverse(ret.begin(), ret.end());
    cout << ret;
}