// 불!
// https://www.acmicpc.net/problem/4179

#include <bits/stdc++.h> 

#define X first
#define Y second

using namespace std;

int n, m;
char board[1000][1000];
int visited[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int min_count = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // input
    cin >> n >> m ;

    for (int i = 0; i < n; i++) {
        string input_line;
        cin >> input_line;
        for (int j = 0; j < m; j++) {
            board[i][j] = input_line[j];
        }
    }

    // 초기값 
    int jihun[2];
    int fire[2];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'J') { jihun[0] = i; jihun[1] = j; visited[i][j] = 'J'; }
            if (board[i][j] == 'F') { fire[0] = i; fire[1] = j; visited[i][j] = 'F'; }
        }
    }

    // 여러 시작점에서 bfs 진행 -> J 다음 F
    queue<pair<int, int>> Q;
    Q.push({jihun[0], jihun[1]}); 
    Q.push({fire[0], fire[1]});

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop(); 

        // 4칸씩 진행
        // J와 F를 구분하여 구현해야 될 것 같은데? 
        for (int dir = 0; dir < 4; dir++) {
            int tempx = cur.X + dx[dir];
            int tempy = cur.Y + dy[dir];

            // 범위를 넘거나, 벽이라면 Pass (지훈, 불 공통)
            if (board[cur.X][cur.Y] == '#') continue; 

            // 지금이 지훈이라면? 
            if (board[cur.X][cur.Y] == 'J') {
                if (board[tempx][tempy] == 'F' || board[tempx][tempy] == 'J') continue; // 불이 났거나, 재방문 -> pass
                
                if (tempx < 0 || tempx >= n || tempy < 0 || tempy >= m) {
                    // 지훈이가 탈출 성공 
                    cout << min_count ;
                    return 0;
                }

                visited[tempx][tempy] = 'J';
                Q.push({tempx, tempy});
                min_count += 1; 
            }

            if (board[cur.X][cur.Y] == 'F') {
                if (tempx < 0 || tempx >= n || tempy < 0 || tempy >= m) continue;
                if (board[tempx][tempy] == 'F') continue; // 내가 재방문 -> pass 
                visited[tempx][tempy] = 'F';
                Q.push({tempx, tempy});

                // 언제 지훈이의 탈출 여부를 알 수 있지? -> 탈출 조건을 달리 해야함 
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
