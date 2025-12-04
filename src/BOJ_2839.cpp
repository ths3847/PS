#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    int memo[5001];
    fill(begin(memo), end(memo), 5000);
    memo[3] = 1;
    memo[5] = 1;
    cin >> N;

    for(int i=6;i<=5000;i++)
        memo[i] = min(memo[i-3], memo[i-5]) + 1;
    
    if(memo[N] >= 5000) cout << -1;
    else cout << memo[N];

    return 0;
}