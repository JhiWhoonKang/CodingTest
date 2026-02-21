#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    string stkStr = "";
    
    for(const char& c : s)
    {
        if(!stkStr.empty() && stkStr.back() == c)
        {
            stkStr.pop_back();
        }
        else
        {
            stkStr.push_back(c);
        }
    }
    
    if(stkStr.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}