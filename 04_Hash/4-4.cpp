// 의상
// https://school.programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    set<string> clothes_type;
    int count[30] = {0};
    
    // 두번째 요소 기준으로 정렬
    // sort(clothes.begin(), clothes.end(),
    //      [](const vector<string> &a, const vector<string> &b) {
    //          return a[1] < b[1]; });
    
    for (size_t i = 0; i < clothes.size(); i++) {
        clothes_type.insert(clothes[i][1]);
    }
    
    // 이제는 index 접근을 위해 vector로 바꿈 
    vector<string> types(clothes_type.begin(), clothes_type.end());
    
    for (size_t i = 0; i < clothes.size(); i++) {
        for (size_t j = 0; j < clothes.size(); j++) {
            if (clothes[i][1] == types[j]) {
                count[j] += 1;
            }
        }
    }
    
    int combi = 1;
    
    for (size_t i = 0; i < clothes.size(); i++) {
        combi = combi * (count[i] + 1);
    }

    return combi - 1;
}