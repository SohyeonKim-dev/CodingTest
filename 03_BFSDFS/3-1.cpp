// 백준 - 그림 (BFS)
// https://www.acmicpc.net/problem/1926

#include <bits/stdc++.h>

#define X first
#define Y second 

using namespace std;

int board[500][500];
bool visited[500][500]; // visit 사용 금지 

int n, m;

// 아래, 오른쪽, 위, 왼쪽 (행렬)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    // 입출력 최적화 
    ios::sync_with_stdio(false);
    cin.tie(0);

    // input 입력 받아주기
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int max_painting = 0;
    int num_of_painting = 0;

    // 전체 그래프를 탐색하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || visited[i][j])
            {
                continue; // 그림이 아니거나, 이미 방문 -> pass
            }

            // 새로운 그림의 시작점 board[i][j]
            num_of_painting += 1;

            queue<pair<int, int>> Q;

            visited[i][j] = true;

            // BFS 시작
            Q.push({i, j});
            int temp_area = 0;

            while(Q.empty() != true) {
                temp_area += 1;

                // 큐에서 하나 빼낸다 (current)
                pair<int, int> cur = Q.front();
                Q.pop();

                // Q를 pop 하면서 -> 0 1 2 3 -> 인접한 4방향 탐색 
                for (int dir = 0; dir < 4; dir++) {
                    int cur_X = cur.X + dx[dir];
                    int cur_Y = cur.Y + dy[dir];

                    // 동일해도 범위 넘어감 -> 0-index 고려
                    if (cur_X < 0 || cur_X >= n || cur_Y < 0 || cur_Y >= m) {
                        continue; // 범위 탈출 -> pass
                    }

                    if (board[cur_X][cur_Y] == 0 || visited[cur_X][cur_Y]) {
                        continue; // 그림이 아니거나, 이미 방문 -> pass 
                    }

                    visited[cur_X][cur_Y] = true;    // 방문 표시
                    Q.push({cur_X, cur_Y});     // 새롭게 큐에 넣어주는 것 -> 이게 pop 될때 또 4방향 탐색 예정
                }

            }

            // Q가 빈 상태
            // 현 시작점 board[i][j]의 그림과, 전체의 max 처리 
            max_painting = max(max_painting, temp_area);

        }
    }

    // max_painting가 산출된 상태

    cout << num_of_painting << '\n' << max_painting;
}