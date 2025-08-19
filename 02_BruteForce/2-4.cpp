// 카펫
// https://school.programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // h * w = brown + yellow
    // 2 * (h + w) - 4 = brown -> 방정식으로 풀 수 있는거 아님?
    
    int mul = brown + yellow;
    int add = (brown + 4) / 2;
    
    int h = 0, w = 0; // init
    
    for (int i = 1; i < add; i++) {
        if ((add - i) * i == mul) {
            h = max((add - i), i);
            w = add - h;
        }
    }
    
    answer.push_back(h);
    answer.push_back(w);
    return answer;
}