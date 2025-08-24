// 스타트링크
// https://www.acmicpc.net/problem/5014

#include <bits/stdc++.h>

using namespace std;

int f, s, g, u, d;
int building[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 전체 F층, 지금 S, 도착지 G
    // Up은 U칸씩, Down은 D씩 가능
    cin >> f >> s >> g >> u >> d;

    building[s] = 1; 
    queue<int> Q;
    Q.push({s});

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        if (cur == g) {
            cout << building[cur] - 1;
            return 0;
        }

        // Up + Down Move
        if (cur + u <= f && building[cur + u] == 0) {
            building[cur + u] = building[cur] + 1;
            Q.push({cur + u});
        }

        // 조건 -> 1 범위 주의 
        if (cur - d >= 1 && building[cur - d] == 0) {
            building[cur - d] = building[cur] + 1;
            Q.push({cur - d});
        }
    }
    cout << "use the stairs";
    return 0;
}