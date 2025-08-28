// 1로 만들기 2
// https://www.acmicpc.net/problem/12852

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000001];
int path[1000001];

// 연산을 하는 횟수의 최솟값을 출력
// N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분해서 순서대로 출력

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i-1] + 1; // 1 빼는 연산 하나 더하기 
        path[i] = i - 1;

        // 1 빼기보다는 작을 때 -> 조건에 넣으면 됨
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) { 
            dp[i] = dp[i/2] + 1;
            path[i] = i/2;
        }

        if (i % 3 == 0 && dp[i] > dp[i/3] + 1) { 
            dp[i] = dp[i/3] + 1;
            path[i] = i/3;
        }
    }

    cout << dp[n] << '\n';

    // 경로 출력하기 

    int cur = n;
    while(cur > 1) {
        cout << cur << ' ';
        cur = path[cur]; // 이전 값을 넣어서, 재귀적으로 흘러감!

        // if (cur % 3 == 0) {
        //     cout << dp[cur//3] << ' ';
        //     cur /= 3;
        // }
        // else if (cur % 2 == 0) {
        //     cout << dp[cur//3] << ' ';
        //     cur /= 2;
        // }
        // else {
        //     cout << dp[cur-1] << ' ';
        //     cur -= 1;
        // }
    }

    cout << 1 ;
    return 0;
}