#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    
    const int halfN = n / 2;
    int start = 1;
    int end = 1;
    int sum = 1;
    for(;start <= halfN;)
    {
        if(sum == n)
        {
            ++answer;
            ++end;
            sum += end;
        }
        else if(sum < n)
        {
            ++end;
            sum += end;
        }
        else
        {            
            sum -= start;
            ++start;
        }
    }
    
    return answer;
}