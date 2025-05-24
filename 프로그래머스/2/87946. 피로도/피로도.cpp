#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int k, vector<vector<int>> dungeons, vector<bool>& visited, int tempCnt, int& answer)
{
    answer = max(answer, tempCnt);
    
    for(int versusIdx = 0; versusIdx < dungeons.size(); ++versusIdx)
    {
        if(dungeons[versusIdx][0] <= k && !visited[versusIdx])
        {
            visited[versusIdx] = true;
            dfs(k - dungeons[versusIdx][1], dungeons, visited, tempCnt + 1, answer);
            visited[versusIdx] = false;
        }
    }
    
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);
    
    dfs(k, dungeons, visited, 0, answer);
    
    return answer;
}