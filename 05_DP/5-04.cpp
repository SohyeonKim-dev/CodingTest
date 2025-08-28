// RGB거리
// https://www.acmicpc.net/problem/1149

#include <bits/stdc++.h>

using namespace std;

int n;
int paints[1000][3];
int dp[1000][3];

// 모든 집을 칠하는 비용의 최솟값을 출력

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> paints[i][j];
        }
    }

    // 점화식 작성하기

    dp[0][0] = paints[0][0];
    dp[0][1] = paints[0][1];
    dp[0][2] = paints[0][2];

    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + paints[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + paints[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + paints[i][2];
    }

    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << '\n';
    return 0;
}