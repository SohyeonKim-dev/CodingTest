// 계단 오르기 
// https://www.acmicpc.net/problem/2579

#include <bits/stdc++.h>

using namespace std;

int n;
int steps[301];
int dp[301];

// 얻을 수 있는 총 점수의 최댓값을 출력

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    // 계단 input 
    for (int i = 0; i < n; i++) {
        cin >> steps[i];
    }

    // dp[n]을 밟는다는 가정에서, 점화식 구성  
    // 3개 연속 불가, 4번째가 현재라면 (현재 칸 더한다면)
    // - O X O or O X O O (- 상관 없음)
    // X O O X (지금 안밟는다면) or O X O X

    dp[0] = steps[0];
    dp[1] = steps[1] + dp[0];
    dp[2] = max(steps[2] + steps[0], steps[1] + steps[2]);
    
    // 이러면 steps[2]를 뒤로 뺄 수 있구나 -> 점화식처럼 
    
    // dp[3] = max(step[0] + step[1] + step[3], step[0] + step[2] + step[3])
    //       = step[3] + max(step[0] + step[1], step[0] + step[2])
    //       = max(dp[1], dp[0] + step[2]) + step[3]

    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i-2], dp[i-3] + steps[i-1]) + steps[i];
    }

    // 0-index 주의
    cout << dp[n-1] << "\n";
    return 0;
}