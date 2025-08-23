// 적록색약
// https://www.acmicpc.net/problem/10026

#include <bits/stdc++.h>

#define X first
#define Y second 

using namespace std;

int n;
char board[100][100];
bool visited[100][100];

int red, green, blue;
int redgreen;

// 행렬 (하, 우, 상, 좌)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    // input board 채우기
    for (int i = 0; i < n; i++){
        string input_line;
        cin >> input_line;
        for (int j = 0; j < n; j++) {
            board[i][j] = input_line[j];
        }
    }

    queue<pair<int, int>> RQ;
    queue<pair<int, int>> GQ;
    queue<pair<int, int>> BQ;

    // 전체 그래프 탐색 
    for (int i = 0; int i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 시작점이 될 RGB 찾기 

        }
    }
    cout << red + green + blue << ' ' << redgreen + blue;
}
