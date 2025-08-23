// 나이트의 이동
// https://www.acmicpc.net/problem/7562

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

    for (int tc = 0; tc < t; tc++) {
        int move;
        int posx, posy;
        int desx, desy;
        
        int board[300][300];
        bool visited[300][300];

        cin >> move;
        cin >> posx >> posy;
        cin >> desx >> desy;



    }
    
    return 0;
}