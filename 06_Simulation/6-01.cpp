// 감시
// https://www.acmicpc.net/problem/15683

#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n, m;
int maps[51][51];

vector<pair<int, int>> house;
vector<pair<int, int>> chick;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maps[i][j];

            // 1, 2인 경우에는 위치를 저장해주기 
            if (maps[i][j] == 1) { house.push_back({i, j}); }
            if (maps[i][j] == 2) { chick.push_back({i, j}); }
        }
    }

    // next_permutation으로 조합을 구현해야 함 (0/1로 밀어넣기)




    return 0;
}