// 소수 찾기
// https://school.programmers.co.kr/learn/courses/30/lessons/42839

#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int num) {
    if (num < 2) return false; // 0, 1 소수 X
    
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// int solution(string numbers) {
//     int count = 0, temp = 0; 
//     set<int> number_set;
    
//     for (int i = 0; i < numbers.size(); i++) {
//         temp = numbers[i] - '0';
//         number_set.insert(temp);
//         if (is_prime(temp) == true) count += 1; 
//     } // 우선 숫자 하나로 소수인지 (중복 안되게 set으로 바꾸기)

//     // 주어진 배열의 위치들을 (index) 바꿔가면서 합쳐서 is_prime 확인 
//     // 길이 별 모든 조합 구현하기 
    
//     for (int len = 2; len < numbers.size(); len++){
        
//     }
    
//     return count;
// }

int solution(string numbers) {
    set<int> number_set;
    sort(numbers.begin(), numbers.end());

    do {
        for (int len = 1; len <= numbers.size(); len++) {
            int num = stoi(numbers.substr(0, len)); 
            // substr로 끊어서 -> 길이별로 구현 
            // stoi = string to int

            number_set.insert(num); // 중복 -> set 처리
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    // 조합을 next_permutation로 구현 
    // 123 -> 123 - 132 - 213 - 231 - 312 - 321 (사전순)
    // 맨 처음 순열도 사용하려고, do - while 

    int count = 0;

    // iterator, set<int>::iterator it -> 함수형 
    for (int n : number_set) {
        if (is_prime(n) == true) {
            count += 1;
        }
    }

    return count;
}