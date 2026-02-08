#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(const vector<string>&pron, string cur, string pre, unordered_set<string>& pset)
{
    if(cur != "")
    {
        pset.insert(cur);
    }
    
    for(const auto& s : pron)
    {
        if(s == pre)
        {
            continue;
        }
        
        if(cur.length() + s.length() <= 30)
        {
            dfs(pron, cur + s, s, pset);
        }
    }
    
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    const vector<string> pron = { "aya","ma","woo","ye" };
    #if 0
    unordered_map<string, bool> pmap(false);
    
    do
    {
        string curs = "";
        for(const auto& s : pron)
        {            
            curs += s;
            pmap[curs] = true;
        }
    }while(next_permutation(pron.begin(), pron.end()));
    
    for(const auto& bab : babbling)
    {
        if(pmap[bab])
        {
            ++answer;
        }
    }
    #endif
    unordered_set<string>pset;
    dfs(pron, "", "", pset);
    
    for(const auto&bab : babbling)
    {
        if(pset.count(bab))
        {
            ++answer;
        }
    }
    
    return answer;
}