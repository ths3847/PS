#include <bits/stdc++.h>
using namespace std;

bool isDigit(char ch)
{
    if(ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}

string trans(string str){
    if(str[0] != '0')
        return str;
    while(str.length()>1){
        if(str[0] == '0')
            str.erase(str.begin());
        else
            break;
    }
    return str;
}


int main(){
    int N;
    string str;
    vector<string> answer;
    cin >> N;
    for(int i=0;i<N;i++){
        string tmp;
        cin >> str;
        for(int j=0;j<str.length();j++){
            if(isDigit(str[j]))
                tmp += str[j];
            else{
                if(!tmp.empty()){
                    answer.push_back(trans(tmp));
                    tmp.clear();
                }
            }
        }
        if(!tmp.empty()){
            answer.push_back(trans(tmp));
            tmp.clear();
        }
    }
    sort(answer.begin(), answer.end(), [](const string& a, const string& b) {
        if (a.size() != b.size())
            return a.size() < b.size();  // 1순위: 길이

        return a < b;  // 2순위: 사전순
    });
    for(int i=0; i < answer.size()-1;i++) cout << answer[i] << endl;
    if(answer.size()>0)
        cout << answer[answer.size()-1];
    
    return 0;
}