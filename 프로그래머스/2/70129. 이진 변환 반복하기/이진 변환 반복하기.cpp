#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int zeroNum = 0;
    vector<int> onlyOne = {};
    string nextS = s;
    
    bool stopFlag = false;
    int loopNum = 1;
    
    while(!stopFlag)
    {
        onlyOne = {};
        for(const auto& c : nextS)
        {
            if(c == '0')
            {
                ++zeroNum;
                continue;
            }
            onlyOne.push_back(1);
        }
        
        if(onlyOne.size() == 1)
        {
            stopFlag = true;
            break;
        }
        else
        {
            ++loopNum;
            nextS = "";
            int curNum = onlyOne.size();
            while(curNum / 2 != 0)
            {
                nextS += to_string(curNum % 2);
                curNum /= 2;
            }
            nextS += "1";
            if(nextS.size() > 1)
            {
                swap(nextS[0], nextS[nextS.size() - 1]);
            }
        }
    }
    
    answer.push_back(loopNum);
    answer.push_back(zeroNum);
    
    return answer;
}