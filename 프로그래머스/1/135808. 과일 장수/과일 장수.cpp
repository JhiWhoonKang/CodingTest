#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), [](int a, int b)
         {
             return a > b;
         });

    int scoreIdx = 0;
    
    const int maxBoxNum = score.size() / m;
    for(int curBoxIdx = 1; curBoxIdx <= maxBoxNum; ++curBoxIdx)
    {
        auto result = min_element(score.begin() + scoreIdx, score.begin() + scoreIdx + m);        
        answer += ((*result) * m);
        scoreIdx += m;
    }
    
    return answer;
}