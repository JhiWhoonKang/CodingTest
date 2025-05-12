#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int totalBlock = brown + yellow;    
    int minHeight = 3;
    
    
    for(int i = totalBlock; i >= minHeight; --i)
    {
        if(totalBlock % i == 0)
        {
            if(totalBlock / i > i)
            {
                break;
            }
            else
            {
                if(brown == (i * 2 + (totalBlock / i) * 2 - 4))
                {
                    answer.push_back(i);
                    answer.push_back(totalBlock / i);
                }
            }
        }
    }
        
    return answer;
}