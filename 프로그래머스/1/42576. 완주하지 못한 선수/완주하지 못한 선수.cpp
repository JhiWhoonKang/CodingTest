#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


string search(vector<string>& participant, vector<string>& completion)
{
    unordered_map<string, int> names;
    
    for(const string& n : participant)
    {
        ++names[n];
    }
    
    for(const string& n : completion)
    {
        --names[n];
    }
    
    for(const string& n : participant)
    {
        if(names[n] > 0)
        {
            return n;
        }
    }
    return "";
}

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = search(participant, completion);
            
    return answer;
}