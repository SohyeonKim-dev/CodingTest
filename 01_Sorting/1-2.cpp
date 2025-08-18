// 가장 큰 수
// https://school.programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int radix(int n) {
    while(n >= 10) {
        n = n / 10;
    }
    return n;
}

bool compare(int a, int b) {
    // if (radix(a) == radix(b)) {
    //     // 30 vs 3 인 경우, 3이 먼저 가야함 -> 해결하기
    //     return a > b;
    // } else {
    //     return radix(a) >= radix(b);
    // }
    
    string A = to_string(a);
    string B = to_string(b);
    return A + B > B + A;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), [](int a, int b){
        return compare(a, b);
    });
    
    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    
    // test case 추가 (numbers가 다 0이면 0이어야 함)
    if (answer[0] == '0') return "0";
    
    return answer;
}
