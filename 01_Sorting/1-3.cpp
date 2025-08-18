// H-Index
// https://school.programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int h_index = 0;
    int max_num = *max_element(citations.begin(), citations.end());
    
    for (int h = 0; h <= max_num; h++){
        int temp_count = 0;
        
        // range 주의
        for (int j = 0; j < citations.size(); j++){
            if (citations[j] >= h) {
                temp_count += 1;
            }
        }
        if (temp_count >= h) {
            // h_index update
            h_index = h;
        }
    }
    return h_index;
}