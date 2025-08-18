// 최소 직사각형 
// https://school.programmers.co.kr/learn/courses/30/lessons/86491

// 모든 명함을 수납할 수 있는 가장 작은 지갑

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 더 큰 수가 앞에 위치하도록 
void swaps (vector<int>& input) { // reference 추가 
    if (input[0] < input[1]){
        swap(input[0], input[1]);
    }
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    // 우선 전체에 swap 적용 
    for (int i = 0; i < sizes.size(); i++) {
        swaps(sizes[i]);
    }
    
    int max_first = (*max_element(sizes.begin(), sizes.end(),
                                  [](const vector<int>& a, const vector<int>& b) {
                                      return a[0] < b[0];  
                                  }))[0];
    
    int max_second = (*max_element(sizes.begin(), sizes.end(),
                                  [](const vector<int>& a, const vector<int>& b) {
                                      return a[1] < b[1];  
                                  }))[1];

    return max_first * max_second;
}