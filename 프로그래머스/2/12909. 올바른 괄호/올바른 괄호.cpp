#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int leftNum = 0, rightNum = 0;
    
    for(int idx = 0; idx < s.size(); ++idx)
    {
        if(idx == 0 && s[idx] == ')')
        {
            return false;
        }        
        if(s[idx] == '(')
        {
            ++leftNum;
        }
        else if(s[idx] == ')')
        {
            if(leftNum <= 0)
            {
                return false;
            }
            
            ++rightNum;
            --leftNum;
        }
    }
    
    if(leftNum == 0)
    {
        return true;
    }
    return false;
}