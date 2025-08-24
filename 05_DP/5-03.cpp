// 계단 오르기 
// https://www.acmicpc.net/problem/2579

#include <bits/stdc++.h>

using namespace std;

int n;
int steps[301];
int dp[301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    // 계단 input 
    for (int i = 0; i < n; i++) {
        cin >> steps[i];
    }

    return 0;
}