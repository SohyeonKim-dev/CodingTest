// 2×n 타일링 2
// https://www.acmicpc.net/problem/11727

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;

    // index = n까지 가줘야 함 !
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
    }

    cout << dp[n] << '\n'; 
    return 0;
}