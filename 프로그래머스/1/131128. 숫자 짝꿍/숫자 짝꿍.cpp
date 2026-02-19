#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    // vector<char> xChar;
    // vector<char> yChar;
    unordered_map<char, int> xMap(0);
    unordered_map<char, int> yMap(0);
    vector<char> tempC;
    for(const auto& c : X)
    {
        // xChar.emplace_back(c);
        ++xMap[c];
    }
    
    for(const auto& c : Y)
    {
        // yChar.emplace_back(c);
        ++yMap[c];
    }
    
    for(const auto& c : X)
    {
        if(xMap[c] > 0 && yMap[c] > 0)
        {
            --xMap[c];
            --yMap[c];
            tempC.emplace_back(c);
        }
    }
    
    // sort(xChar.begin(), xChar.end());
    // sort(yChar.begin(), yChar.end());
    sort(tempC.begin(), tempC.end(), [](const char a, const char b)
         {
             return a > b;
         });
    
    const int tempCSize = tempC.size();
    if(!tempCSize)
    {
        return "-1";
    }    
    else if(tempC[0] == '0' && tempC[tempCSize - 1] == '0')
    {
        return "0";
    }
    else
    {
        for(const auto& c : tempC)
        {
            answer += c;
        }

        return answer;
    }    
}