#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        string tmp;
        cin >> tmp;
        stack<char> s;
        for(int j=0;j<tmp.size();j++){
            if(tmp[j] == '(') // '(' 일때는 무조건 넣고
                s.push(tmp[j]);
            else{ // ')' 일때는 스택에 '(' 를 pop, 만약 stack에 첫 입력이 ')' 이면 NO로 종료
                if(s.size()==0){
                    s.push(tmp[j]);
                    break;
                }
                s.pop();
            }
        }
        if(s.size())
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }
    return 0;
}