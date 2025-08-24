// 토마토
// https://www.acmicpc.net/problem/7576

#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int n, m;
int board[1000][1000];
int visited[1000][1000];
// int days[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // input
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 시작점이 board[i][j] == 1 -> 시작점이 됨
    // 여러 시작점에서 동시에 4칸 탐색 이루어져야 한다 (Q에 한꺼번에 넣어줘야 함)

    queue<pair<int, int>> Q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                Q.push({i, j});
            }
        }
    }

    // 시작점인 지점들이 Q에 들어간 상황 
    // 이제 큐가 빌 때까지 pop 하면서 bfs 돌리면 됨
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int temp_x = cur.X + dx[dir];
            int temp_y = cur.Y + dy[dir];

            if (temp_x < 0 || temp_x >= n || temp_y < 0 || temp_y >= m) continue;
            if (board[temp_x][temp_y] != 0 || visited[temp_x][temp_y]) continue;

            board[temp_x][temp_y] = board[cur.X][cur.Y] + 1;

            visited[temp_x][temp_y] = true;
            Q.push({temp_x, temp_y});
        }
    }

    // 정답 출력 -> max or -1 
    int max_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                cout << -1;
                return 0;
            }
            max_count = max(max_count, board[i][j]);
        }
    }
    cout << max_count - 1; // 시작점부터 1이라서, 며칠 지났냐하면 하나를 빼줘야한다. 
}