#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> orangeMap(0);
    vector<int> temp(k, 0);
    for(const auto& t : tangerine)
    {
        ++orangeMap[t];
    }
    
    vector<int> eachOrangeNum;
    for(const auto& p : orangeMap)
    {
        eachOrangeNum.emplace_back(p.second);
    }
    
    sort(eachOrangeNum.begin(), eachOrangeNum.end(), [](const int& a, const int& b)
         {
             return a > b;
         });
    
    int curOrangeNum = 0;
    int idx = 0;
    while(!(curOrangeNum >= k))
    {
        curOrangeNum += eachOrangeNum[idx];
        ++idx;
    }
    
    return idx;
}