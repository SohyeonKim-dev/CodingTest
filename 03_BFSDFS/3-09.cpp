// 나이트의 이동
// https://www.acmicpc.net/problem/7562

#include <bits/stdc++.h>

#define X first
#define Y second 

using namespace std;

int t;
vector<int> answer;

// 나이트의 이동 
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        int n;
        int posx, posy;
        int desx, desy;
        
        int board[300][300];

        memset(board, -1, sizeof(board));

        cin >> n;
        cin >> posx >> posy;
        cin >> desx >> desy;

        // posx, posy에서 출발 
        queue<pair<int, int>> Q;
        board[posx][posy] = 0;

        Q.push({posx, posy});

        while(!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();

            if (cur.X == desx && cur.Y == desy) {
                answer.push_back(board[cur.X][cur.Y]);
                break;
            }

            for (int dir = 0; dir < 8; dir++) {
                int tempx = cur.X + dx[dir];
                int tempy = cur.Y + dy[dir];

                if (tempx < 0 || tempx >= n || tempy < 0 || tempy >= n) continue;
                if (board[tempx][tempy] != -1) continue; // 이미 방문 -> pass

                board[tempx][tempy] = board[cur.X][cur.Y] + 1;
                Q.push({tempx, tempy});
            }
        }
    }
    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n' ;
    }

    return 0;
}