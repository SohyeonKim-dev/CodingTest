// 구간 합 구하기 4
// https://www.acmicpc.net/problem/11659

#include <bits/stdc++.h>

using namespace std;

int n, m;
int sum[100001]; // 1-index

// 수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램
// 미리 저장해두고, 출력? dp[i] - dp[j] 이런 식으로? 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int temp;
    for (int i = 1; i <= n; i++) { // index 주의 - n 포함!
        cin >> temp;
        sum[i] = sum[i-1] + temp;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << '\n';
    }

    return 0;
}