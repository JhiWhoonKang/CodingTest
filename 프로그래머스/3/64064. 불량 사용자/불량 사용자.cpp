#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

bool findId(const string& user, const string& banned)
{
    if(user.size() != banned.size())
    {
        return false;
    }
    
    for(int i = 0; i < user.size(); i++)
    {
        if(banned[i] == '*')
        {
            continue;
        }
        if(user[i] != banned[i])
        {
            return false;
        }
    }
    
    return true;
}

void dfs(int idx, const vector<string>& userList, const vector<string>& bannedList, set<string>& selected, set<set<string>>& allCases)
{
    if(idx == bannedList.size())
    {
        allCases.insert(selected);
        return;
    }

    for(int i = 0; i < userList.size(); i++)
    {
        const string& user = userList[i];
        if(selected.find(user) != selected.end())
        {
            continue;
        }

        if(findId(user, bannedList[idx]))
        {
            selected.insert(user);
            dfs(idx + 1, userList, bannedList, selected, allCases);
            selected.erase(user);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    set<set<string>> allCases;
    set<string> selected;
    
    dfs(0, user_id, banned_id, selected, allCases);
    
    answer = allCases.size();
    return answer;
}
