// 프로세스
// https://school.programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// int solution(vector<int> priorities, int location) {
//     int answer = 0;
//     int n = priorities.size();
    
//     // property, time
//     queue<pair<int, int>> Q;
    
//     // 우선 순서대로 Q에 넣기 
//     for (int i = 0; i < n; i++) {
//         Q.push_back(priorities[i], i);
//     }
        
//     while(!Q.empty()) {
//         pair<int, int> cur = Q.front();
//         Q.pop();
        
//         // 최대를 계속 찾아야 함
//         // pq로 구현하기 
//     }
    
//     return answer;
// }


// PQ 구현 

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();
    
    // priority, index
    queue<pair<int, int>> Q;
    priority_queue<int> PQ; // priority max를 PQ로 관리! 
    
    // 우선 순서대로 Q에 넣기 
    for (int i = 0; i < n; i++) {
        Q.push({priorities[i], i});
        PQ.push({priorities[i]});
    }
        
    int count = 0;
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        
        if (cur.first == PQ.top()) {
            count += 1; 
            PQ.pop(); // max update
            
            // index가 내가 찾던 값이라면?
            if (cur.second == location) {
                return count;
            } 
        } 
        else {
            // max가 아니라면, 다시 뒤로 붙임
            Q.push(cur);
        }
    }
}