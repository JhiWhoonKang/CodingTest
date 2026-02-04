#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool isRight(int num)
{
    for(int i = 2; i <= sqrt(num); ++i)
    {
        if((num % i) == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    const int numSize = nums.size();
    
    vector<int> temp;
    temp.resize(numSize, 0);
    temp[numSize - 1] = 1;
    temp[numSize - 2] = 1;
    temp[numSize - 3] = 1;
    sort(nums.begin(), nums.end(), [](int a, int b)
         {
             return a < b;
         });
    
    do
    {
        int num = 0;
        int cnt = 0;
        for(int tempIdx = 0; tempIdx < numSize; ++tempIdx)
        {
            if(temp[tempIdx] == 1)
            {
                ++cnt;
                num += nums[tempIdx];
                if(cnt == 3)
                {
                    break;
                }
            }
        }
        
        if(isRight(num))
        {
            ++answer;
        }
    }while(next_permutation(temp.begin(), temp.end()));
    
    return answer;
}