#include <bits/stdc++.h>
using namespace std;

bool check(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='[' || str[i]=='(')
            s.push(str[i]);
        else if(str[i]==']'){
            if(s.size() == 0 ||s.top() != '[')
                return false;
            else
                s.pop();
        }
        else if(str[i]==')'){
            if(s.size() == 0 || s.top() != '(')
                return false;
            else
                s.pop();
        }
    }
    if(s.size()>0)
        return false;
    else
        return true;
}

int main(){
    
    while(1){
        string str;
        string tmp;
        getline(cin, str,'.');
        getline(cin,tmp);
        if(str.size()==0)
            break;
        check(str) ? cout << "yes" : cout << "no";
        cout << endl;
    }
    return 0;
}
