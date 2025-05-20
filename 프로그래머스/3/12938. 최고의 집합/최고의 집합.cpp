#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int A = s / n;
    int AA = s % n;
    if(!A)
    {
        answer.push_back(-1);
        return answer;
    }
    if(!AA)
    {
        for(int i = 0; i < n; ++i)
        {
            answer.push_back(A);
        }
    }
    else
    {
        for(int i = 0; i < n - AA; ++i)
        {
            answer.push_back(A);
        }
        
        for(int i = AA; i != 0; --i)
        {
            answer.push_back(A + 1);
        }
    }        
        
    return answer;
}