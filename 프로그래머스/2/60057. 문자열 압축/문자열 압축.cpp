#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int solution(string s) {
    int answer = INT_MAX;
    
    if(s.size() == 1)
    {
        return s.size();
    }
    
    for(int length = 1; length <= s.size() / 2; ++length)
    {
        string answerS = "";
        string prevS = "";
        string currS = "";
        answerS = "";
        
        int cnt = 1;
        
        prevS = s.substr(0, length);
        
        for(int idx = length; idx < s.size(); idx += length)
        {
            currS = s.substr(idx ,length);
            if(prevS == currS)
            {
               ++cnt;
            }
            else
            {                
                if(cnt > 1)
                {                    
                    answerS += to_string(cnt);
                    answerS += prevS;
                }
                else
                {
                    answerS += prevS;
                }
                prevS = currS;
                cnt = 1;
            }
        }
        if(cnt > 1)
        {
            answerS += to_string(cnt);
        }
        answerS += prevS;
        
        answer = min(answer, static_cast<int>(answerS.size()));
    }
    
    
    
    return answer;
}