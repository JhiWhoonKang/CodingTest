#include <string>
#include <vector>
#include <limits>
#include <set>

using namespace std;

const int nNum = 9;

vector<set<long long>> dpMap(nNum);
const int maxNumber = 32000;

int dp(int N, int number)
{
    if(N == number)
    {
        return 1;
    }    
    
    
    for(int i = 1; i <= 8; ++i)
    {
        int nums = 0;
        for(int j = 1; j <= i; ++j)
        {
            nums = nums * 10 + N;
            if(nums > numeric_limits<int>::max())
            {
                break;
            }            
        }
        dpMap[i].insert(nums);
        
        for(int j = 1; j <= i; ++j)
        {
            for(int a : dpMap[j])
            {
                for(int b : dpMap[i - j])
                {
                    dpMap[i].insert(a + b);
                    dpMap[i].insert(a - b);
                    dpMap[i].insert(a * b);
                    if (b != 0)
                    {
                        dpMap[i].insert(a / b);                    
                    }
                }
            }
        }
        
        if (dpMap[i].count(number))
        {
            return i;
        }
    }        
    
    return -1;
}

int solution(int N, int number) {
    int answer = 0;
    
    answer = dp(N, number);
    
    return answer;
}