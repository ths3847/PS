#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int N, W[16][16], dp[16][1<<16];
/**
 * top down 방식
 * 미래의 가능한 경로를 전부 계산해서 현재 시점의 최솟값을 구한다.
 * stack에 전부 담고, pop 하면서 확인 함
 * 경로 전부 확인하지만 메모이제이션으로 중복 계산 없엔다
 */
int tsp(int here, int visited){
    if(visited == (1<<N)-1){
        if(W[here][0] == 0){
            return INF;
        }
        else
            return W[here][0];
    }
    if(dp[here][visited] != -1) return dp[here][visited];
    int &ret = dp[here][visited];
    ret = INF;
    for(int i=0;i<N;i++){
        if(W[here][i]==0) continue;
        if((1<<i)&visited) continue;
        ret = min(ret, tsp(i, visited | (1<<i))+W[here][i]);
    }
    return ret;

}
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> W[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << tsp(0,1);
    return 0;
}
