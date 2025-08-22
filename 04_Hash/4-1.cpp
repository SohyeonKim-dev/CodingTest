// 완주하지 못한 선수
// https://school.programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <set>

using namespace std;

// set 
string solution(vector<string> participant, vector<string> completion) {
    
    multiset<string> s(participant.begin(), participant.end());
    for (const string &x : completion) s.erase(s.find(x)); 
    
    return *s.begin();
}

// 그냥 하나씩 비교하는 코드도 돌려보기 