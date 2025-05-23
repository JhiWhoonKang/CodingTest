#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MtoS(int minute, int second)
{
    int totalTime;
    return totalTime = minute * 60 + second;
}

string StoM(int second)
{
    string time = "";
    int minute = second / 60;
    int sec = second % 60;
    
    if(minute < 10)
    {
        time += "0";
        time += to_string(minute);
    }
    else
    {
        time += to_string(minute);
    }
    
    time += ":";
    
    if(sec < 10)
    {
        time += "0";
        time += to_string(sec);
    }
    else
    {
        time += to_string(sec);
    }
    
    return time;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int video_lenM = stoi(video_len.substr(0, 2));
    int video_lenS = stoi(video_len.substr(3, 2));
    
    const int totalSec = MtoS(video_lenM, video_lenS);
    
    int posM = stoi(pos.substr(0, 2));
    int posS = stoi(pos.substr(3, 2));
    
    int posSec = MtoS(posM, posS);
    
    const int op_startM = stoi(op_start.substr(0, 2));
    const int op_startS = stoi(op_start.substr(3, 2));
    
    const int op_endM = stoi(op_end.substr(0, 2));
    const int op_endS = stoi(op_end.substr(3, 2));
    
    const int openingStartPos = MtoS(op_startM, op_startS);
    const int openingEndPos = MtoS(op_endM, op_endS);
    
    
    for(const auto& cmd : commands)
    {
        if(cmd == "next")
        {   
            if(posSec >= openingStartPos && posSec <= openingEndPos)
            {
                posSec = openingEndPos;
            }
            
            if(totalSec - (posSec + 10) < 10)
            {
                posSec = totalSec;
            }
            
            else
            {
                posSec += 10;
            }                                                
        }
        
        else    // prev
        {                  
            if(posSec >= openingStartPos && posSec <= openingEndPos)
            {
                posSec = openingEndPos;
            }
            
            if((posSec - 10) < 0)
            {
                posSec = 0;
            }            
            
            else
            {
                posSec -= 10;
            }           
        }
    }
    
    if(posSec >= openingStartPos && posSec <= openingEndPos)
    {
        posSec = openingEndPos;
    }
    
    
    answer = StoM(posSec);
    
    
    return answer;
}