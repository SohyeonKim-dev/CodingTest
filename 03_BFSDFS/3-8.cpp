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
    int group = 0;
    int nums_of_group[n];

    // input board 채우기 
    for (int i = 0; i < n; i++) {
        string inputline; 
        cin >> inputline;
        for (int j = 0; j < n; j++) {
            board[i][j] = inputline[j] - '0' // string to int 
        }
    }

    // 그래프 탐색 시작 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 || visited[i][j]) continue;

            // board[i][j] = 단지의 시작점
            group += 1;

            queue<pair<int, int>> Q;
            Q.push({i, j});

            while(!Q.empty()) {

            }
        }
    }
}
