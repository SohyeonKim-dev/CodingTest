// 유기농 배추
// https://www.acmicpc.net/problem/1012

#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int t; 

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    // test case 별 분기 
    for (int i = 0; i < t; i++) {
        // testcase 별 update 필요하다면, 여기서 선언 
        int n, m, k;
       cin >> m >> n >> k;

        int board[50][50];
        bool visited[50][50];

        // 오답 원인 -> 배열 초기화 (test case)
        memset(board, 0, sizeof(board));
        memset(visited, false, sizeof(visited));

        int worms = 0; 

        // board 채우기 
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> y >> x;
            board[x][y] = 1;
        }

        // 시작점을 찾는 BFS 
        // 전체 그래프 탐색하며, 시작점 1 찾기 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0 || visited[i][j]) continue;

                // 이제 board[i][j]는 시작점 -> 큐에 넣어준다
                worms += 1;
                visited[i][j] = true;

                // 큐 선언은 여기서부터 
                queue<pair<int, int>> Q;
                Q.push({i, j});

                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int tempx = cur.X + dx[dir];
                        int tempy = cur.Y + dy[dir];

                        if (tempx < 0 || tempx >= n || tempy < 0 || tempy >= m) continue; // 범위 over pass
                        if (board[tempx][tempy] == 0 || visited[tempx][tempy]) continue; // 배추 없으면 pass 

                        visited[tempx][tempy] = true; // 배추가 있다면 -> 방문 표시 && 큐에 넣어주기
                        Q.push({tempx, tempy});       // 다시 BFS 이어나가기 
                    }
                }
            }
        }
        cout << worms << '\n'; // 각 test case마다 개행
    }
    return 0;
}