#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    long long workNum = 0;
    priority_queue<int> pq;
    int remainWorkHour = n;
    
    for(const auto& work : works)
    {
        workNum += work;
        pq.push(work);
    }
    
    while(!pq.empty() && remainWorkHour != 0)
    {
        int biggestHour = pq.top();
        pq.pop();
        if(biggestHour - 1 < 0)
        {
            int scndBiggestHour = pq.top();
            pq.push(scndBiggestHour - 1);
        }
        else
        {
            if(biggestHour - 1 == 0)
            {
                --remainWorkHour;
                continue;
            }
            else
            {
                pq.push(biggestHour - 1);
            }               
        }
        // cout << "biggestHour: " << biggestHour - 1 << "\n";
        --remainWorkHour;
    }        
    
    while(!pq.empty())
    {
        int temp = pq.top();
        pq.pop();
        answer += (temp * temp);
        // cout << temp << "\n";
    }
    
    return answer;
}