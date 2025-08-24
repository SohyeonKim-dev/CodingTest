#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    struct Music {
        string genre;
        int plays;
        int index;
    };
    
    vector<Music> musics;
    
    // genre, plays, index 묶기 
    // vector<string, int, int> musics; // 같은 타입만 가능 
    
    for (int i = 0; i < genres.size(); i++) {
        musics.push_back({genres[i], plays[i], i});
    }
    
    // 총 play count -> 정렬
    
    
    return answer;
}