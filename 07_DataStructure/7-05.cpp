// 다리를 지나는 트럭
// https://school.programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) { 
    
    int n = truck_weights.size();
    
    int times = 0;
    int cur_truck = 0;
    int temp_weight = 0;
    
    queue<int> Q;
    // 초기의 진행 - 쭉 이어지도록 
    for(int i = 0; i < bridge_length; i++) {
        Q.push(0);
        // 무게 없는 차들을 넣어주는 것
        // bridge_length 단위 유지한 상태로 하나 넣고 -> 하나 빼주기 
    }
    
    while(!Q.empty() || cur_truck < n) {
        times += 1;
        
        // 제일 먼저 들어갔던 트럭이 이제 나오는 것 
        int cur = Q.front();
        temp_weight -= cur;
        Q.pop(); // 큐에서 트럭 제거
        
        // cur_truck <= n 등호때문에 무한루프 -> 시간초과 해결 !
        if (cur_truck < n && 
            temp_weight + truck_weights[cur_truck] <= weight) {
            
            temp_weight += truck_weights[cur_truck];
            Q.push(truck_weights[cur_truck]); // 현재 트럭 진입
            cur_truck += 1; 
        } else {
            // 0이 진입 - 빈칸 채우기
            if (cur_truck < n) {
                Q.push(0);
            }
        }
    }
    
    return times;
}
