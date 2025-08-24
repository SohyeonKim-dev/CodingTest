// 안전 영역
// https://www.acmicpc.net/problem/2468

#include <bits/stdc++.h>

#define X first
#define Y second 

using namespace std;

int n;
vector<int> areas;

int board[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int max_height = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            max_height = max(max_height, board[i][j]);
        }
    }

    // 각 높이 별 BFS 진행하기 
    for (int t = 0; t < max_height; t++) {
        int temp_area = 0;

        int checked[100][100] = {0};
        bool visited[100][100] = {false};

        // checked init 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > t) {
                    checked[i][j] = 1;
                }
                // 물에 잠긴 지역 = 0 // 땅은 1
            }
        }

        // 시작점이 checked[i][j] == 1 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (checked[i][j] == 0 || visited[i][j]) continue;

                visited[i][j] = true;
                queue<pair<int, int>> Q;
                Q.push({i, j});

                while(!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int tempx = cur.X + dx[dir];
                        int tempy = cur.Y + dy[dir];

                        if (tempx < 0 || tempx >= n || tempy < 0 || tempy >= n) continue;
                        if (checked[tempx][tempy] == 0 || visited[tempx][tempy]) continue;

                        visited[tempx][tempy] = true;
                        Q.push({tempx, tempy});
                    }
                }
                // board[i][j] 덩어리에 대해 area ++ 
                temp_area += 1;
            }
        }
        areas.push_back(temp_area);
    }
    // sort(areas.begin(), areas.end());
    cout << *max_element(areas.begin(), areas.end());
    return 0;
}