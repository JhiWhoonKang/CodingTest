#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <functional>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    const int targetsSize = targets.size();
    answer.resize(targetsSize, -1);
    
    unordered_map<char, int>km;
    const int keymapSize = keymap.size();
    
    for(const auto& key : keymap)
    {
        int idx = 1;
        for(const auto& c : key)
        {
            if(auto search = km.find(c); search == km.end())  // 문자 미보유
            {
                km[c] = idx;
            }
            else  // 문자 보유 -> idx 비교, 작은거 넣기
            {
                if(km[c] > idx)
                {
                    km[c] = idx;
                }
            }
            ++idx;
        }
    }
        
    int answerIdx = -1;
    for(const auto& target : targets)
    {
        int num = 0;
        ++answerIdx;
        
        for(const auto& c : target)
        {
            if(auto search = km.find(c); search != km.end())    // 있으면
            {
                num += km[c];
                answer[answerIdx] = num;
            }
            else
            {
                answer[answerIdx] = -1;
                break;
            }
        }
    }
    
    
    return answer;
}