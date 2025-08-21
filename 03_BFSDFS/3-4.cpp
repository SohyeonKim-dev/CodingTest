// 불!
// https://www.acmicpc.net/problem/4179

#include <bits/stdc++.h> 

#define X first
#define Y second

using namespace std;

int n, m;
int board[1000][1000];
int visited[1000][1000];

int main() {
    ios::sync_with_stdio(false);
    cin::tie(0);

    // input
    cin >> n >> m ;

    for (int i = 0; i < n; i++) {
        string input_line;
        cin << input_line;
        for (int j = 0; j < m; j++) {
            board[i][j] = input_line[j] - '0';
        }
    }

    
}
