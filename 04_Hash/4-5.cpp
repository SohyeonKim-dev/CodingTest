// 베스트앨범
// https://school.programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    struct Music {
        string genre;
        int plays;
        int index;
    };
    
    int n = genres.size();
    vector<Music> musics;
    
    // genre, plays, index 묶기 
    // vector<string, int, int> musics; // 같은 타입만 가능 
    
    for (int i = 0; i < n; i++) {
        musics.push_back({genres[i], plays[i], i});
    }
    
    // hash -> genre에 plays 매칭 
    unordered_map<string, int> genrePlays;
    
    for (int i = 0; i < n; i++) {
        genrePlays[musics[i].genre] += musics[i].plays;
    }
    
    // 벡터로 만들고 best 찾기
    vector<pair<string, int>> genrePlays_vec(genrePlays.begin(), genrePlays.end());
    
    // int 값으로 정렬 
    sort(genrePlays_vec.begin(), genrePlays_vec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });
    
    pair<string, int> firstG = genrePlays_vec[0];
    pair<string, int> secondG = genrePlays_vec[1];
    
    // 정답 제출용
    vector<int> answer;
    
    // first 곡 2개 찾기 
    vector<Music> temp;
    
    for (int i = 0; i < n; i++) {
        if(musics[i].genre == firstG.first) {
            temp.push_back(musics[i]);
        }
    }
    
    sort(temp.begin(), temp.end(), [](Music &a, Music &b) {
        if (a.plays == b.plays) {
            // 만약 재생 횟수가 같다면, 고유 번호(인덱스) 낮은걸로 넣기
            return a.index < b.index;
        }
        return a.plays > b.plays;
    });
    
    answer.push_back(temp[0].index);
    answer.push_back(temp[1].index);
    
    // 이제 두번째 장르
    vector<Music> temp2;
    
    for (int i = 0; i < n; i++) {
        if(musics[i].genre == secondG.first) {
            temp2.push_back(musics[i]);
        }
    }
    
    sort(temp2.begin(), temp2.end(), [](Music &a, Music &b) {
        if (a.plays == b.plays) {
            // 만약 재생 횟수가 같다면, 고유 번호(인덱스) 낮은걸로 넣기
            return a.index < b.index;
        }
        return a.plays > b.plays;
    });
    
    answer.push_back(temp2[0].index);
    answer.push_back(temp2[1].index);
    
    return answer;
}

// 개선된 버전 -> for문으로 묶어줘야 한다. 