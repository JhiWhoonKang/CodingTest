#include <string>
#include <vector>
#include <iostream>

using namespace std;

int w, h;
int cx, cy;
int opX[128], opY[128];


void searchSP(vector<string>& _park_)
{
    int i = 0;
    
    for(const string s:_park_)
    {
        int j = 0;   // j; w, i; h
        for(const char c:s)
        {
            if(c == 'S')
            {
                cout << "Start point" << "\n";
                cy = i, cx = j;
                return;
            }   
            ++j;
        }
        ++i;
    }
}

// op 공 n
void decodeCmd(vector<string> _routes_, vector<string>& _park_)
{
    for(const string& cmd : _routes_) 
    {
        char op = cmd[0];
        int n = cmd[2] - '0';

        int nx = cx, ny = cy;
        
        bool boolMove = true;
        
        for(int d = 1; d <= n; ++d) 
        {
            int tempX = cx + opX[op] * d;
            int tempY = cy + opY[op] * d;

            if(tempX < 0 || tempY < 0 || tempX >= w || tempY >= h || _park_[tempY][tempX] == 'X') 
            {
                cout << "ㄴㄴ" << "\n";
                boolMove = false;
                break;
            }
        }

        if (boolMove) 
        {
            cout << "here" << "\n";
            cout << "cx: " << cx << ", cy: " << cy << "\n";
            cx += opX[op] * n;
            cy += opY[op] * n;
        }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    // 시작 지점 : 'S'
    // 지나다니는 길 : 'O'
    // 장애물 : 'X'
    // [op n], op: N/S/W/E, n: 1~9
    // 가로 W, 세로 H || 0 - based
    // park: 공원 배열
    // routes: 명령어
    // 최종 위치 return
    // 공간 벗어나거나 장애물 만나면 => 현재 명령어 무시 -> 다음 명령어 수행
    
    w=park[0].size();
    h=park.size();
    
    opX['E'] = 1;  opX['W'] = -1;
    opY['S'] = 1;  opY['N'] = -1;
    
    searchSP(park);
    decodeCmd(routes, park);
    
    answer.push_back(cy);
    answer.push_back(cx);
    
    return answer;
}
