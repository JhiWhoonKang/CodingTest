#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool compare(char a, char b)
{
    return a < b;
}

string solution(string number, int k) {
    string answer = "";
    
    #if 0
    
    어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자
    number: 문자열 형식
    k: 제거할 수의 개수
    => number에서 k개 제거 후 만들 수 있는 가장 큰 숫자 -> 문자열 변환 -> return
    
    #endif
        
    
    vector<char> stk;
    
    for(const char num:number)
    {
        while(!stk.empty() && k>0 && stk.back() < num)
        {
            stk.pop_back();
            --k;
        }
        stk.push_back(num);
    }
    
    while (k > 0) 
    {
        stk.pop_back();
        --k;
    }

    for (const char c : stk) 
    {
        answer += c;
    }
    
    return answer;
}