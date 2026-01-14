#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    string tok;
    cin >> str >> tok;
    stack<char> s;
    
    for(char ch : str){
        s.push(ch);
        if(s.size() >= tok.size() && s.top() == tok[tok.size()-1]){
            string tmp="";
            for(int i=0;i<tok.size();i++){
                tmp+=s.top();
                s.pop();
            }
            reverse(tmp.begin(), tmp.end());
            if(tmp!=tok)
                for(char c : tmp) s.push(c);
        }
    }
    if(s.size()==0)
        cout << "FRULA";
    else{
        string res="";
        while(s.size()){
            res+=s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        cout << res;
    }
    return 0;
}