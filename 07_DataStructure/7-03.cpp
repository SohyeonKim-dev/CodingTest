// 올바른 괄호 
// https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include<string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool solution(string s) {
    stack<char> chars;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            chars.push(s[i]);
        } 
        
        if (s[i] == ')') {
            // 스택이 비면 -> 바로 false
            if (chars.empty()) return false;

            if (chars.top() == '(') {
                chars.pop(); // '(' 도 없앤다 
            } else {
                // ( 랑 짝이 안맞으면 -> false
                return false;
            }
        } 
    }
    // 아직 뭔가 남아있다면 false
    return chars.empty();
}