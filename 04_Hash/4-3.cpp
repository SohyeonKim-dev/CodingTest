// 전화번호 목록
// https://school.programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for (size_t i = 0; i < phone_book.size() - 1; i++) {
        string cur = phone_book[i];
        string next = phone_book[i+1];
        
        if (next.find(cur) == 0) {
            // 시작 지점이 0이다 -> 접두어 
            return false;
        }
    }
    return true;
}