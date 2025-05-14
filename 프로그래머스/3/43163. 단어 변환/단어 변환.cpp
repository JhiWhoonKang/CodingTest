#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool canSwitch(string s, string words)
{
    int cnt = 0;
    
    for(int idx = 0; idx < s.size(); ++idx)
    {
        if(s[idx] != words[idx])
        {
            ++cnt;
        }
    }
    
    return cnt == 1 ? true : false;
}

int bfs(string begin, string target, vector<string>& words)
{
    if(find(words.begin(), words.end(), target) == words.end())
    {
        return 0;
    }
    
    queue<pair<string, int>> q;
    vector<bool> visited(words.size(), false);
    
    q.push({begin, 0});
    
    while(!q.empty())
    {
        string s = q.front().first;
        int step = q.front().second;
        q.pop();                
        
        if(s == target)
        {
            return step;
        }
        
        for(int wordsIdx = 0; wordsIdx < words.size(); ++wordsIdx)
        {                                    
            if(!visited[wordsIdx] && canSwitch(s, words[wordsIdx]))
            {
                visited[wordsIdx] = true;
                q.push({words[wordsIdx], ++step});
            }                                    
        }        
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    answer = bfs(begin, target, words);
    
    return answer;
}