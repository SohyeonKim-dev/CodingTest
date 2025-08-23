// 단지 번호 붙이기 
// https://www.acmicpc.net/problem/2667

#include <bits/stdc++.h>

#define X first
#define Y second 

using namespace std;

int n;

int board[25][25];
bool visited[25][25];

// 행렬 (하, 우, 상, 좌)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int num_of_group = 0;
    vector<int> buildings; 

    // input board 채우기 
    for (int i = 0; i < n; i++) {
        string inputline; 
        cin >> inputline;
        for (int j = 0; j < n; j++) {
            board[i][j] = inputline[j] - '0'; // string to int 
        }
    }

    // 그래프 탐색 시작 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 || visited[i][j]) continue;

            // board[i][j] = 단지의 시작점
            num_of_group += 1;
            visited[i][j] = true;
            int temp_count = 1;

            queue<pair<int, int>> Q;
            Q.push({i, j});

            while(!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int tempx = cur.X + dx[dir];
                    int tempy = cur.Y + dy[dir];

                    if (tempx < 0 || tempx >= n || tempy < 0 || tempy >= n) continue;
                    if (board[tempx][tempy] == 0 || visited[tempx][tempy]) continue;

                    visited[tempx][tempy] = true;
                    temp_count += 1;

                    Q.push({tempx, tempy});
                }
            }
            buildings.push_back(temp_count);
        }
    }
    // 정렬
    sort(buildings.begin(), buildings.end());

    cout << num_of_group << '\n';

    for (size_t i = 0; i < buildings.size(); i++) {
        cout << buildings[i] << '\n';
    }

    return 0;
}
