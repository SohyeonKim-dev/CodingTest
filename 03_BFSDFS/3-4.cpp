// 불!
// https://www.acmicpc.net/problem/4179

#include <bits/stdc++.h> 

#define X first
#define Y second

using namespace std;

int n, m;
char board[1000][1000];
int fire[1000][1000];
int jihun[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 배열 전부를 -1로 초기화
    memset(fire, -1, sizeof(fire));
    memset(jihun, -1, sizeof(jihun));

    // input
    cin >> n >> m ;

    for (int i = 0; i < n; i++) {
        string input_line;
        cin >> input_line;
        for (int j = 0; j < m; j++) {
            board[i][j] = input_line[j];
        }
    }

    queue<pair<int, int>> FQ;
    queue<pair<int, int>> JQ;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'J') { JQ.push({i, j}); jihun[i][j] = 0;}
            if (board[i][j] == 'F') { FQ.push({i, j}); fire[i][j] = 0;}
        }
    }

    // 불과 지훈이 각자의 초를 기록하며 Q로 그래프 순회한다.
    while(!FQ.empty()) {
        pair<int, int> cur = FQ.front();
        FQ.pop();

        for (int dir = 0; dir < 4; dir++) {
            int tempx = cur.X + dx[dir];
            int tempy = cur.Y + dy[dir];

            if (tempx < 0 || tempx >= n || tempy < 0 || tempy >= m) continue;
            if (board[tempx][tempy] == '#' || fire[tempx][tempy] != -1) continue;
            
            fire[tempx][tempy] = fire[cur.X][cur.Y] + 1;
            FQ.push({tempx, tempy});
        }
    }

    // 불의 시간 관계가 모두 기록된 상황 -> 지훈이와 비교하면서 길을 찾아보자. 
    while(!JQ.empty()) {
        pair<int, int> cur = JQ.front();
        JQ.pop();

        for (int dir = 0; dir < 4; dir++) {
            int tempx = cur.X + dx[dir];
            int tempy = cur.Y + dy[dir];

            // 지훈이 탈출 성공 ! 
            if (tempx < 0 || tempx >= n || tempy < 0 || tempy >= m) {
                cout << jihun[cur.X][cur.Y] + 1;
                return 0;
            }

            if (board[tempx][tempy] == '#' || jihun[tempx][tempy] != -1) continue;
            if (fire[tempx][tempy] != -1 && jihun[cur.X][cur.Y] + 1 >= fire[tempx][tempy]) continue; // 불에 탐 
            
            jihun[tempx][tempy] = jihun[cur.X][cur.Y] + 1;
            JQ.push({tempx, tempy});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}