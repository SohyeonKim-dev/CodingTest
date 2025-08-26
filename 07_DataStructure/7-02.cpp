// 기능개발
// https://school.programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> left; 
    int n = progresses.size();
    
    for (int i = 0; i < n; i++) {
        left.push_back(100 - progresses[i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (left[i] % speeds[i] == 0) { 
            left[i] = left[i] / speeds[i]; 
        } else {
            left[i] = (left[i] / speeds[i]) + 1;
        }
    }
    
    // left = [7, 3, 9];
    
    vector<int> answer;
    int cur = left[0];
    int temp = 1; // init 제대로 주는 것 주의!
    
    for (int i = 0; i < n - 1; i++) {
        if (cur >= left[i+1]) {
            temp += 1;
        } else {
            answer.push_back(temp);
            cur = left[i+1]; // i가 아니라 i+1
            temp = 1; // 지금 나 
        }
    }
    answer.push_back(temp);
    return answer;
}