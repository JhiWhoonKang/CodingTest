#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    const int maxTime = prices.size();
    answer.resize(maxTime, 0);
    stack<int> stk;
    for(int curTime = 0; curTime < maxTime; ++curTime)
    {
        while(!stk.empty() && prices[curTime] < prices[stk.top()])
        {
            int topTime = stk.top();
            stk.pop();
            answer[topTime] = curTime - topTime;
        }
        stk.push(curTime);
    }
    
    while(!stk.empty())
    {
        int topTime = stk.top();
        stk.pop();
        answer[topTime] = (maxTime - 1) - topTime;
    }
    
    return answer;
}