#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, m, target;
    cin >> N >> target;
    m = N*N;
    vector<vector<int>> v(N, vector<int>(N,0));
    vector<int> result;
    int flag = -1;
    int x, y;
    int t=1;
    x=y=0;
    for(int i=0;i<N;i++){
        if(m==target){
            result.push_back(i+1);
            result.push_back(1);
        }
        v[i][0] = m--;
    }
    x= N-1;
    while(m>0){
        for(int i=0;i<N-t;i++)
        {
            y += (-1*flag);
            if(m==target){
                result.push_back(x+1);
                result.push_back(y+1);
            }
            v[x][y] = m--;
        }
        flag *= -1;
        for(int i=0;i<N-t;i++)
        {
            x += (-1*flag);
            if(m==target){
                result.push_back(x+1);
                result.push_back(y+1);
            }
            v[x][y] = m--;
        }
        t++;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            cout << v[i][j] << " ";
        }
        cout << v[i][N-1] << endl;
    }
    cout << result[0] << " " << result[1];
    return 0;
}