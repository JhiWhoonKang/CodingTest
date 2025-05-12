#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> score(3, 0);
    
    vector<int> firstPattern = { 1,2,3,4,5 };
    vector<int> secondPattern = { 2,1,2,3,2,4,2,5 };  // <- 수정됨
    vector<int> thirdPattern = { 3,3,1,1,2,2,4,4,5,5 };
    
    for(int idx = 0; idx < answers.size(); ++idx)
    {
        if(firstPattern[idx % firstPattern.size()] == answers[idx])
        {
            ++score[0];
        }
        if(secondPattern[idx % secondPattern.size()] == answers[idx])
        {
            ++score[1];
        }
        if(thirdPattern[idx % thirdPattern.size()] == answers[idx])
        {
            ++score[2];
        }
    }
    
    int maxScore = *max_element(score.begin(), score.end());
    
    for(int i = 1; i <= 3; ++i)
    {
        if(score[i - 1] == maxScore)
        {
            answer.push_back(i);
        }
    }
    
    return answer;
}
