#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    unordered_map<string, int> nameMap;
    int yearIdx = 0;
    for(const auto& person : name)
    {
        nameMap[person] = yearning[yearIdx];
        ++yearIdx;
    }
    
    for(const auto& group : photo)
    {
        int num = 0;
        for(const auto& person : group)
        {
            if(nameMap.find(person) != nameMap.end())
            {
                num += nameMap[person];
            }
        }
        answer.emplace_back(num);
    }
        
    
    return answer;
}