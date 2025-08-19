// 모의고사 
// https://school.programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

// int count_1 (numbers) {
//     int count = 0;
//     vector<int> pattern = [1, 2, 3, 4, 5];
    
//     for (int i = 0; i < numbers.size(); i++) {
//         if (numbers[i] == pattern[i % 5]) {
//             count += 1;
//         }
//     } 
//     // 반복되는 구현 -> 그냥 한번에 안에서 해도 될 듯 
//
//     return count;
// }

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int count1 = 0, count2 = 0, count3 = 0;
    
    vector<int> pattern_1 = {1, 2, 3, 4, 5};
    vector<int> pattern_2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> pattern_3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); i++){
        if (answers[i] == pattern_1[i % 5]) {
            count1 += 1;
        }
        
        if (answers[i] == pattern_2[i % 8]) {
            count2 += 1;
        }
        
        if (answers[i] == pattern_3[i % 10]) {
            count3 += 1;
        }
    }
    
    // 오름차순으로 넣어주기 
    int max_count = max(count1, max(count2, count3));

    if (max_count == count1) answer.push_back(1);
    if (max_count == count2) answer.push_back(2);
    if (max_count == count3) answer.push_back(3);

    // sort(answer.begin(), answer.end()); 
    return answer;
}