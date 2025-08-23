// 폰켓몬
// https://school.programmers.co.kr/learn/courses/30/lessons/1845

#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int selection = nums.size() / 2;
    
    set<int> pocketmon;
    
    for (int i = 0; i < nums.size(); i++) {
        pocketmon.insert(nums[i]);
    }
    
    int diff = pocketmon.size();
    
    if (diff > selection) {
        return selection;
    } else {
        return diff;
    }
}