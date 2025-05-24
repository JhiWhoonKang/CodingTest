#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

char wordList[] = { 'A', 'E', 'I', 'O', 'U' };
bool found = false;
void dfs(string compareString, const string word, int& answer)
{
    if(compareString == word)
    {
        found = true;
        return;
    }
    
    if(compareString.size() >= 5 | found)
    {
        return;
    }
    
    for(int i = 0; i < 5; ++i)
    {
        if(found)
        {
            return;
        }

        ++answer;
        dfs(compareString + wordList[i], word, answer);
    }
    
    
}

int solution(string word) {
    int answer = 0;
    
    
    dfs("", word, answer);
    
    return answer;
}