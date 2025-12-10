#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    int N, L, total;
    bool down, result;
    cin >> N >> L;
    vector<vector<int>> v(N,vector<int>(N,0));
    total = 0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> v[i][j];
    }
    for(int i=0;i<N;i++){
        int s=1;
        int before = v[i][0];
        down = false;
        result = true;
        for(int j=1;j<N;j++){
            if(abs(v[i][j]-before)>1){
                result =false;
                break;
            }
            else if(v[i][j]==before){
                s++;
            }
            else if(v[i][j]>before){
                if(down || (s<L)){
                    result = false;
                    break;
                }
                s=1;
            }
            else{
                if(down){
                    result = false;
                    break;
                }
                down=true;
                s=1;
            }
            if(down){
                if(s==L){
                    s-=L;
                    down = false;
                }
            }
            before = v[i][j];
        }
        if(down)
            result =false;
        if(result)
            total++;
    }


    for(int i=0;i<N;i++){
        int s=1;
        int before = v[0][i];
        down = false;
        result = true;
        for(int j=1;j<N;j++){
            if(abs(v[j][i]-before)>1){
                result =false;
                break;
            }
            else if(v[j][i]==before){
                s++;
            }
            else if(v[j][i]>before){
                if(down || (s<L)){
                    result = false;
                    break;
                }
                s=1;
            }
            else{
                if(down){
                    result = false;
                    break;
                }
                down=true;
                s=1;
            }
            if(down){
                if(s==L){
                    s-=L;
                    down = false;
                }
            }
            before = v[j][i];
        }
        if(down)
            result =false;
        if(result)
            total++;
    }


    cout << total;
    return 0;
}

