// 숨바꼭질
// https://www.acmicpc.net/problem/1697

#include <bits/stdc++.h> 

using namespace std;

int n, k;
int pos[100001]; // step 저장
// int min_count;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    // pos[k] = -1; // 동생은 -1에 있다
    // 그냥 index k를 쓰면 됨 

    // 수빈이 현재 위치 
    queue<int> Q;
    Q.push(n);
    pos[n] = 1;

    if (n == k) { cout << 0; return 0; } // 처음부터 동생 잡은 경우 

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        // 배열 탈출 (3가지 mov) or 동생 찾고 종료 
        int temp[3] = { cur - 1, cur + 1, 2 * cur };

        // 수빈이의 현재 위치 == 동생 
        // if (cur == k) { cout << pos[cur] - 1; return 0; }

        for (int dir = 0; dir < 3; dir++) {

            // 범위 체크 먼저 
            if (temp[dir] < 0 || temp[dir] > 100000) continue;

            // 동생 찾으면 종료 
            if (temp[dir] == k) {
                cout << pos[cur]; 
                return 0;
            }

            if (pos[temp[dir]] > 0) continue; // 재방문 pass 

            pos[temp[dir]] = pos[cur] + 1; // step + 1
            Q.push(temp[dir]);
        }
    }
}
