#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";    
    
    cout << "a: " << static_cast<int>('a') << ", " << "z: " << static_cast<int>('z') << "\n";
    cout << "A: " << static_cast<int>('A') << ", " << "Z: " << static_cast<int>('Z') << "\n";
    
    bool frontC = true;
    
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ')
        {
            frontC = true;
        }
        else
        {
            if(frontC)
            {
                s[i] = toupper(s[i]);
                frontC = false;
            }
            else
            {
                s[i] = tolower(s[i]);
            }
        }
    }
    
    answer = s;     
    
    return answer;
}