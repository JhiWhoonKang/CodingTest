#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string convert(long long num)
{
    string n = "";
    while(num != 0)
    {
        n += to_string(num % 2);
        num /= 2;
    }
    if(num % 2 != 0)
    {
        n += to_string((num % 2));
    }
    
    reverse(n.begin(), n.end());
    
    return n;
}

// long long fx(long long num)
// {
//     string strNum = convert(num);
    
    
    
//     return ;
// }

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(const auto& number : numbers)
    {
        if(number % 2 == 0)
        {
            answer.emplace_back(number + 1);
        }
        else
        {
            long long bit = (~number) & (number + 1);
            long long changedNum = (number | bit) ^ (bit >> 1);
            answer.emplace_back(changedNum);
        }
    }
    
    return answer;
}