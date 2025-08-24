// 1, 2, 3 더하기
// https://www.acmicpc.net/problem/9095

#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int dp[12];
    memset(dp, 0, sizeof(dp));

    cin >> t;

    // test case 
    for (int tc = 0; tc < t; tc++) {
        int n;
        int temp_count = 0;

        cin >> n; 

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        // init 단계 이후로 i 지정하면 됨 
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; // 점화식
        }
        cout << dp[n] << '\n';
    }
    return 0;
}
// init 값 제대로 주고 -> 점화식 제대로 세우면 됨 