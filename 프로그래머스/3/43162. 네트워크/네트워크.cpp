#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(const int n, vector<vector<int>>& computers, int curComNum, vector<bool>& visited)
{
    visited[curComNum] = true;
    for(int nxtComNum = 0; nxtComNum < n; ++nxtComNum)
    {
        if(computers[curComNum][nxtComNum] && !visited[nxtComNum])
        {
            dfs(n, computers, nxtComNum, visited);       
        }
    }    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, false);
    
    for(int curComNum = 0; curComNum< n; ++curComNum)
    {
        if(!visited[curComNum])
        {
            dfs(n, computers, curComNum, visited);
            ++answer;
        }        
    }
    
    return answer;
}