// K번째 수
// https://school.programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++){
        vector<int> temp = commands[i];
        // span<int> slice(array.begin() + temp[0], array.begin() + temp[1]);
        vector<int> slice(array.begin() + temp[0] - 1, array.begin() + temp[1]);

        sort(slice.begin(), slice.end());
        answer.push_back(slice[temp[2] - 1]);
    }
    
    return answer;
}