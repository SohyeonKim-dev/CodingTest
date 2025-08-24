// 1로 만들기 
// https://www.acmicpc.net/problem/1463

#include <bits/stdc++.h>

using namespace std;

int dp[1000001]; // +1 
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // 1이 되면 끝 
    dp[1] = 0;

    // i 시작 범위 주의, n 포함 
    for (int i = 2; i <= n; i++) {
        // 1 빼는 연산 제일 먼저 
        dp[i] = dp[i-1] + 1;

        if (i % 2 == 0) { 
            // 나누기 2 연산을 적용한 경우 vs keep
            dp[i] = min(dp[i], dp[i/2] + 1);
        }

        if (i % 3 == 0) { 
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }
    cout << dp[n];
}