#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    int skillSize = skill.size();
    
    int skillMapIdx = 0;
    vector<string> new_skill_trees;
    
    for(const auto& skill_tree : skill_trees)
    {
        string filteredString = "";
        for(const auto& c : skill_tree)
        {
            if(skill.find(c) != skill.npos)
            {
                filteredString += c;
            }
        }
        
        if(filteredString == skill.substr(0, filteredString.size()))
        {
            ++answer;
        }
    }            
    
    return answer;
}