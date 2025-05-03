#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    // 등수 순서대로 담긴 배열: players
    // 해설진이 부른 이름을 담은 문자열 배열: callings
    // 1~꼴 담아서 return
    
    cout<<players.size()<<"\n";
    
    #if 0
    for(string& s : callings)
    {
        for(int i=1; i<players.size(); ++i)
        {
            if(s == players[i])
            {
                swap(players[i], players[i-1]);
                break;
            }
        }
    }
    #endif
    
    #if 01
    
    // players.size()만큼 버킷을 미리 할당
    unordered_map<string, int> running(players.size());
    
    for(int i=0; i<players.size(); ++i)
    {
        running[players[i]] = i;
    }
    
    for(string& s : callings)
    {
        int idx = running[s];
        swap(players[idx], players[idx - 1]);
        running[s] = idx - 1;
        running[players[idx]] = idx;
    }    
    
    #endif
    
    return players;
}