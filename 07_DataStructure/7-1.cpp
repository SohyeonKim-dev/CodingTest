// 같은 숫자는 싫어
// https://school.programmers.co.kr/learn/courses/30/lessons/12906

#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    stack<int> nums; 
    
    for (int i = 0; i < arr.size(); i++) {
        if (nums.empty() || nums.top() != arr[i]) {
            nums.push(arr[i]);
        }
    }
    
    // nums를 역순으로 벡터로 제출
    int n = nums.size();
    vector<int> answer(n);
    
    // for (int i = 0; i < n; i++) {
    //     answer[i] = nums.top();
    //     nums.pop();
    // }
    
    // 역순 인덱스 주의하기
    for (int i = n - 1; i >= 0; i--) {
        answer[i] = nums.top();
        nums.pop();
    }
    
    return answer;
}