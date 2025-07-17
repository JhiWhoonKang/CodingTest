#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int isX = 0;
    int isntX = 0;
    char X = s[0];
    for(const char& c : s)
    {
        if(isX == 0 && isntX == 0)
        {
            X = c;
        }
        
        if(X == c)
        {
            ++isX;
        }
        else
        {
            ++isntX;
        }
        
        if(isX == isntX)
        {
            ++answer;
            isX = 0;
            isntX = 0;
        }
    }
    
    if(isX != isntX)
    {
        ++answer;
    }    
    
    return answer;
}