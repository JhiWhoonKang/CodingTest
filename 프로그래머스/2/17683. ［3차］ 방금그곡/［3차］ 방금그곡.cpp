#include <string>
#include <vector>

using namespace std;

string replaceSharp(string s)
{
    string replaceS = "";
    for(int i = 0; i < s.length(); ++i)
    {
        if(i + 1 < s.length() && s[i + 1] == '#')
        {
            replaceS += tolower(s[i]);
            ++i;
        }
        else
        {
            replaceS += s[i];
        }
    }
    
    return replaceS;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int maxPlayTime = -1;
    
    m = replaceSharp(m);
    
    for(const auto& info : musicinfos)
    {
        string startTime = info.substr(0, 5);
        string endTime = info.substr(6, 5);
        
        int titleEnd = info.find(',', 12);
        string title = info.substr(12, titleEnd - 12);
        string sheet = info.substr(titleEnd + 1);
        
        int startMin = stoi(startTime.substr(0, 2)) * 60 + stoi(startTime.substr(3, 2));
        int endMin = stoi(endTime.substr(0, 2)) * 60 + stoi(endTime.substr(3, 2));
        int playTime = endMin - startMin;
        
        sheet = replaceSharp(sheet);
        
        string playedMelody = "";
        int sheetLen = sheet.length();
        for(int i = 0; i < playTime; i++)
        {
            playedMelody += sheet[i % sheetLen];
        }
        
        if(playedMelody.find(m) != string::npos)
        {
            if(playTime > maxPlayTime)
            {
                maxPlayTime = playTime;
                answer = title;
            }
        }
    }
    
    return answer;
}