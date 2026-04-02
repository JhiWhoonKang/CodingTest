#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if(n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 2;
    }
    
    
    int prev2 = 1;  // dp[n-2]
    int prev1 = 2;  // dp[n-1]
    int cur = 0;    // dp[n]
    
    for(int i = 3; i <= n; ++i)
    {
        cur = (prev1 + prev2) % 1000000007;
        
        prev2 = prev1;
        prev1 = cur;
    }
    
    
    return cur;
}