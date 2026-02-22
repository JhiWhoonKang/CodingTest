#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n) {
    long long answer = 1;
    
    #if 0
    long long maxTwoNum = n / 2;
    
    for(int curTwoNum = 1; curTwoNum <= maxTwoNum; ++maxTwoNum)
    {
        int curMaxOneNum = n - (curTwoNum * 2);
        int maxLength = curMaxOneNum + curTwoNum;
        // maxLength_C_curTwoNum
        
    }
    #endif
    
    if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 2;
    }
    
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }
    
    return dp[n];
}