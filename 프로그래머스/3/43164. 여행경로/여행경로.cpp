#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool dfs(int moved, int total, string airport, vector<string>& route, unordered_map<string, vector<pair<string, bool>>>& path) 
{
    route.push_back(airport);

    if (moved == total) 
    {
        return true;
    }

    for (auto& next : path[airport]) 
    {
        if (!next.second) 
        {
            next.second = true;
            if (dfs(moved + 1, total, next.first, route, path)) 
            {
                return true;
            }
            next.second = false;
        }
    }

    route.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, vector<pair<string, bool>>> path;

    for (const auto& t : tickets) 
    {
        path[t[0]].emplace_back(t[1], false);
    }

    for (auto& p : path) 
    {
        sort(p.second.begin(), p.second.end(), [](const pair<string, bool>& a, const pair<string, bool>& b) {
                 return a.first < b.first;
             });
    }

    dfs(0, tickets.size(), "ICN", answer, path);

    return answer;
}
