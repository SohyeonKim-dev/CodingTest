// 2×n 타일링
// https://www.acmicpc.net/problem/11726

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000];

// 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    // index = n까지 가줘야 함 !
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;

        // dp[i] = dp[i-1] + 2 * dp[i-2];
        // 세로줄 하나 + dp[n-1] 
        // 가로둘 세로둘 + 2칸 뒤로 dp[n-2] -> 세로 둘 = 이전에 처리 된 case로 본다. 
    }

    cout << dp[n] << '\n'; 
    return 0;
}