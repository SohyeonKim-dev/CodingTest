// 영역 구하기
// https://www.acmicpc.net/problem/2583

#include <bits/stdc++.h>

#define X first
#define Y second 

using namespace std;

int m, n, k;

int board[100][100];
bool visited[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int num_of_areas = 0;
vector<int> areas;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> k;

    // input 처리 
    for (int i = 0; i < k; i++) {
        int fx, fy, sx, sy;
        cin >> fx >> fy >> sx >> sy;

        // for (int row = 0; row < sy - fy; row++) {
        //     for (int col = 0; col < sx - sy; col++) {
        //         board[m - fy - row][fx + col] = 1;
        //     }
        // }

        for (int y = fy; y < sy; y++) {
            for (int x = fx; x < sx; x++) {
                board[y][x] = 1;
            }
        }
    }

    // 시작점 1 찾기 -> board[i][j]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 || visited[i][j]) continue;

            visited[i][j] = true;
            num_of_areas += 1;
            int temp_area = 1;

            queue<pair<int, int>> Q;
            Q.push({i, j});

            while(!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int tempx = cur.X + dx[dir];
                    int tempy = cur.Y + dy[dir];

                    if (tempx < 0 || tempx >= m || tempy < 0 || tempy >= n) continue;
                    if (board[tempx][tempy] == 1 || visited[tempx][tempy]) continue;

                    visited[tempx][tempy] = true;
                    temp_area += 1;
                    Q.push({tempx, tempy});
                }
            }
            areas.push_back(temp_area);
        }
    }
    sort(areas.begin(), areas.end());
    cout << num_of_areas << '\n';

    for (size_t i = 0; i < areas.size(); i++) {
        cout << areas[i] << '\n';
    }

    return 0;
}