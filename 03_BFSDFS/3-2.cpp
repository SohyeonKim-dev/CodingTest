// 미로 탐색
// https://www.acmicpc.net/problem/2178

# include <bits/stdc++.h>

# define X first
# define Y second

using namespace std;

int board[100][100];
bool visited[100][100];

int n, m; // input 

// 행렬 - 아래, 오른쪽, 위, 왼쪽
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // input 받기 
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string input_line;
        cin >> input_line;
        for (int j = 0; j < m; j++) {
            board[i][j] = input_line[j] - '0';
        }
    }

    // 시작점은 (1, 1) to (n, m)
    queue<pair<int, int>> Q;

    // 시작점도 방문 처리 
    visited[0][0] = true;
    // int min_dist = 1; 

    Q.push({0, 0});

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int temp_X = cur.X + dx[dir];
            int temp_Y = cur.Y + dy[dir];

            if (temp_X < 0 || temp_X >= n || temp_Y < 0 || temp_Y >= m) { continue; }
            if (board[temp_X][temp_Y] == 0 || visited[temp_X][temp_Y]) { continue; }

            // board[temp_X][temp_Y] = board[temp_X][temp_Y] + 1;
            // 이전칸 + 1 -> temp는 4방향 탐색 중인 것 // 따라서 cur.X가 이전 값
            board[temp_X][temp_Y] = board[cur.X][cur.Y] + 1;

            visited[temp_X][temp_Y] = true;
            Q.push({temp_X, temp_Y});
        }
    }
    // 0-index 주의 
    // cout << board[n][m];
    cout << board[n-1][m-1]; // 이게 n,m 칸 ! 
}